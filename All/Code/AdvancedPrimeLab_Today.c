#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

// Simple sieve + Miller-Rabin primality test + trial division factor

void sieve_primes(int limit){ char *is = malloc(limit+1); for(int i=0;i<=limit;i++) is[i]=1; is[0]=is[1]=0; for(int p=2;p*p<=limit;p++) if(is[p]) for(int q=p*p;q<=limit;q+=p) is[q]=0; printf("Primes up to %d:\n",limit); for(int i=2;i<=limit;i++) if(is[i]) printf("%d ", i); printf("\n"); free(is); }

uint64_t modmul(uint64_t a, uint64_t b, uint64_t mod){ __uint128_t r = ( __uint128_t)a * b; return (uint64_t)(r % mod); }
uint64_t modpow(uint64_t a, uint64_t d, uint64_t mod){ uint64_t res=1; while(d){ if(d&1) res = modmul(res,a,mod); a=modmul(a,a,mod); d>>=1;} return res; }

int miller_rabin(uint64_t n){ if(n<2) return 0; int smallPrimes[]={2,3,5,7,11,13,17,19,23,29,31}; for(int i=0;i<11;i++){ if(n==smallPrimes[i]) return 1; if(n%smallPrimes[i]==0) return 0; }
 uint64_t d=n-1; int s=0; while((d&1)==0){ d>>=1; s++; }
 uint64_t witnesses[] = {2,325,9375,28178,450775,9780504,1795265022}; int wn = sizeof(witnesses)/sizeof(witnesses[0]); for(int i=0;i<wn;i++){ uint64_t a = witnesses[i] % n; if(a==0) continue; uint64_t x = modpow(a,d,n); if(x==1||x==n-1) continue; int comp=1; for(int r=1;r<s;r++){ x = modmul(x,x,n); if(x==n-1){ comp=0; break; } } if(comp) return 0; } return 1; }

void trial_factor(uint64_t n){ printf("Factors of %llu:\n", (unsigned long long)n); for(uint64_t p=2;p*p<=n;p++){ while(n%p==0){ printf("%llu ", (unsigned long long)p); n/=p; } } if(n>1) printf("%llu", (unsigned long long)n); printf("\n"); }

int main(){ int choice; while(1){ printf("\n=== Advanced Prime Lab ===\n1.Sieve 2.MR test 3.Factor 4.Exit >"); if(scanf("%d", &choice)!=1) break; if(choice==1){ int L; printf("limit: "); scanf("%d", &L); sieve_primes(L);} else if(choice==2){ unsigned long long x; printf("n: "); scanf("%llu", &x); printf("isPrime: %s\n", miller_rabin(x)?"Yes":"No"); } else if(choice==3){ unsigned long long x; printf("n: "); scanf("%llu", &x); trial_factor(x);} else break; } return 0; }
