//User input size//
#include<stdio.h>
int main(){
    int a,n,product=1;
    printf("Enter The size of array. \n");
    scanf("%d",&a);
    n=a;
    int arr[a];
    printf("Enter The Value in array.");
    for(int i=0;i<3;i++){
        scanf("%d ",&arr[i]);
    }
    for(int j=0;j<3;j++){
        product *= arr[j];
    }
    printf("The Product of array element is %d. \n",product);
    return 0;
}