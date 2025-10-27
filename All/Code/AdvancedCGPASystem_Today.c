#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSES 64
#define CSV_FILE "cgpa_today.csv"

typedef struct { char code[16]; char name[64]; float credits; float marks; float gp; } Course;

float marks_to_gp(float m){ if(m>=90) return 10; if(m>=80) return 9; if(m>=70) return 8; if(m>=60) return 7; if(m>=50) return 6; if(m>=40) return 5; return 0; }

void compute_and_show(Course a[], int n){ float tw=0, tc=0; for(int i=0;i<n;i++){ a[i].gp = marks_to_gp(a[i].marks); tw += a[i].gp * a[i].credits; tc += a[i].credits; }
 if(tc==0){ printf("No credits entered\n"); return; } printf("Courses:%d TotalCredits:%.2f CGPA:%.2f\n", n, tc, tw/tc);
 for(int i=0;i<n;i++) printf("%s %s Cr:%.2f M:%.2f GP:%.1f\n", a[i].code, a[i].name, a[i].credits, a[i].marks, a[i].gp);
}

int import_csv(Course a[]){ FILE *f=fopen(CSV_FILE,"r"); if(!f) return 0; char line[256]; int n=0; fgets(line,sizeof(line),f); while(fgets(line,sizeof(line),f) && n<MAX_COURSES){ sscanf(line, "%15[^,],%63[^,],%f,%f", a[n].code, a[n].name, &a[n].credits, &a[n].marks); n++; } fclose(f); return n; }

void export_csv(Course a[], int n){ FILE *f=fopen(CSV_FILE,"w"); if(!f){ printf("Cannot write CSV\n"); return;} fprintf(f,"code,name,credits,marks\n"); for(int i=0;i<n;i++) fprintf(f,"%s,%s,%.2f,%.2f\n", a[i].code, a[i].name, a[i].credits, a[i].marks); fclose(f); printf("Exported %d\n", n); }

int main(){ Course arr[MAX_COURSES]; int n=0, ch; while(1){ printf("\n1:Add 2:Import 3:Export 4:Compute 5:Clear 6:Exit >"); if(scanf("%d", &ch)!=1) break; if(ch==1){ if(n>=MAX_COURSES){ printf("full\n"); continue;} printf("code: "); scanf("%15s", arr[n].code); getchar(); printf("name: "); fgets(arr[n].name, sizeof(arr[n].name), stdin); arr[n].name[strcspn(arr[n].name, "\n")]=0; printf("credits: "); scanf("%f", &arr[n].credits); printf("marks: "); scanf("%f", &arr[n].marks); n++; }
 else if(ch==2){ n=import_csv(arr); printf("Imported %d\n", n);} else if(ch==3){ export_csv(arr,n);} else if(ch==4){ compute_and_show(arr,n);} else if(ch==5){ n=0; printf("Cleared\n"); } else break; }
 return 0; }
