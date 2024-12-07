#include<stdio.h>
void reverse(int arr[],int si,int ei){
    for(int i=si,j=ei;i<j;i++,j--){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    return;
}
int main(){
    int x;
    printf("Enter The Size of array :: ");
    scanf("%d",&x);
    int arr[x];
    int k;
    printf("Enter the reverse k step :: ");
    scanf("%d",&k);
    for(int i=0;i<x;i++){
        printf("Enter The Array Element :: ");
        scanf("%d",&arr[i]);
    }
    if(k > x)k = k % x;
    reverse(arr,0,x-1);
    reverse(arr,0,k-1);
    reverse(arr,k,x-1);
    for(int i=0;i<x;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}