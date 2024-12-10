#include<stdio.h>
#include<stdbool.h>
int main(){
    int arr[99];
    int a=1,x=69;
    bool flag = false;
    for(int i=0;i<99;i++){
        if(i==x-2) a++;
        arr[i] = a;
        a++;}
    printf("\n");
    for(int i=0;i<99;i++){
        if(arr[i]==x) {
            flag = true;
            break;
        }
    }
    if(flag==true){
        printf("%d is present in array.\n",x);
    }
    else{
        printf("%d is not present in array.\n",x);
    }
    return 0;
}