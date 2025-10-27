#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 10

void read_matrix(double a[MAXN][MAXN], int n){ for(int i=0;i<n;i++) for(int j=0;j<n;j++){ printf("a[%d][%d]:",i,j); scanf("%lf", &a[i][j]); } }
void print_matrix(double a[MAXN][MAXN], int n){ for(int i=0;i<n;i++){ for(int j=0;j<n;j++) printf("%8.3f ", a[i][j]); printf("\n"); } }

void multiply(double a[MAXN][MAXN], double b[MAXN][MAXN], double res[MAXN][MAXN], int n){ for(int i=0;i<n;i++) for(int j=0;j<n;j++){ res[i][j]=0; for(int k=0;k<n;k++) res[i][j]+=a[i][k]*b[k][j]; } }

double determinant(double a[MAXN][MAXN], int n){ if(n==1) return a[0][0]; double det=0; double temp[MAXN][MAXN]; for(int p=0;p<n;p++){ int subi=0; for(int i=1;i<n;i++){ int subj=0; for(int j=0;j<n;j++){ if(j==p) continue; temp[subi][subj]=a[i][j]; subj++; } subi++; } det += a[0][p] * pow(-1,p) * determinant(temp, n-1); } return det; }

int gauss_jordan_inverse(double a[MAXN][MAXN], double inv[MAXN][MAXN], int n){ double aug[MAXN][2*MAXN]; for(int i=0;i<n;i++){ for(int j=0;j<n;j++) aug[i][j]=a[i][j]; for(int j=0;j<n;j++) aug[i][j+n]=(i==j); }
 for(int i=0;i<n;i++){ double piv=aug[i][i]; if(fabs(piv)<1e-12) return 0; for(int j=0;j<2*n;j++) aug[i][j]/=piv; for(int r=0;r<n;r++){ if(r==i) continue; double mult=aug[r][i]; for(int c=0;c<2*n;c++) aug[r][c]-=mult*aug[i][c]; } }
 for(int i=0;i<n;i++) for(int j=0;j<n;j++) inv[i][j]=aug[i][j+n]; return 1; }

int main(){ double A[MAXN][MAXN], B[MAXN][MAXN], R[MAXN][MAXN]; double Inv[MAXN][MAXN]; int n, ch; printf("Enter n (<=%d):", MAXN); scanf("%d", &n); if(n<1||n>MAXN) return 0; while(1){ printf("\n1:read A 2:read B 3:print A 4:det(A) 5:inv(A) 6:AxB 7:exit> "); scanf("%d", &ch); if(ch==1) read_matrix(A,n); else if(ch==2) read_matrix(B,n); else if(ch==3){ printf("A:\n"); print_matrix(A,n);} else if(ch==4){ printf("det= %.6f\n", determinant(A,n)); } else if(ch==5){ if(gauss_jordan_inverse(A,Inv,n)){ printf("Inverse:\n"); print_matrix(Inv,n);} else printf("Singular\n"); } else if(ch==6){ multiply(A,B,R,n); printf("A*B:\n"); print_matrix(R,n);} else break; }
 return 0; }
