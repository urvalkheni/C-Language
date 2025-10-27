#include <stdio.h>
#include <stdlib.h>

long long gcd(long long a, long long b){ if(b==0) return llabs(a); return gcd(b, a%b); }
long long lcm(long long a, long long b){ return llabs(a / gcd(a,b) * b); }

long long egcd(long long a, long long b, long long *x, long long *y){ if(a==0){ *x=0; *y=1; return b; } long long x1,y1; long long g = egcd(b%a, a, &x1, &y1); *x = y1 - (b/a)*x1; *y = x1; return g; }

long long modinv(long long a, long long m){ long long x,y; long long g = egcd(a,m,&x,&y); if(g!=1) return 0; long long res = (x % m + m) % m; return res; }

long long modpow(long long a,long long e,long long m){ long long res=1% m; a%=m; while(e){ if(e&1) res = (__int128)res * a % m; a = (__int128)a*a % m; e>>=1;} return res; }

int main(){ int ch; while(1){ printf("\n1.GCD 2.LCM 3.ExtendedGCD 4.ModInv 5.ModPow 6.Exit> "); if(scanf("%d", &ch)!=1) break; if(ch==1){ long long a,b; scanf("%lld %lld", &a,&b); printf("gcd=%lld\n", gcd(a,b)); } else if(ch==2){ long long a,b; scanf("%lld %lld", &a,&b); printf("lcm=%lld\n", lcm(a,b)); } else if(ch==3){ long long a,b; scanf("%lld %lld", &a,&b); long long x,y; long long g = egcd(a,b,&x,&y); printf("g=%lld x=%lld y=%lld\n", g,x,y); } else if(ch==4){ long long a,m; scanf("%lld %lld", &a,&m); long long inv = modinv(a,m); if(inv) printf("inv=%lld\n", inv); else printf("No inv\n"); } else if(ch==5){ long long a,e,m; scanf("%lld %lld %lld", &a,&e,&m); printf("modpow=%lld\n", modpow(a,e,m)); } else break; } return 0; }
