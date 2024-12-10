//Power Function(logarithmic)//
#include<stdio.h>
long long power(long long a,long long b){
    if(b%2==0){if(b==0) return 1;
    if(b==1) return a;
    long long recAns;
    long long n = power(a,b/2);
    recAns = n * power(a,b/2);
    return recAns;}
    else{
        if(b==0) return 1;
    if(b==1) return a;
    long long recAns;
    long long n = power(a,b/2);
    recAns = n * n * a;
    return recAns;
    }
}
int main(){
    long long a;
    printf("Enter The Base :: ");
    scanf("%lld",&a);
    long long b;
    printf("Enter The Power :: ");
    scanf("%lld",&b);  
    printf("ans is %lld.",power(a,b));
    return 0;

}