#include<stdio.h>
int main(){
    int arr[7] = {1,2,3,4,3,2,1};
    for(int i=0;i<7;i++){
        for(int j=i+1;j<7;j++){
            if(arr[i] == arr[j]) printf("%d is the duplicate element. \n",arr[i]);
        }
    }
    return 0;
}