#include<stdio.h>
int main(){
    int arr[5]={1,2,3,4,5};
    int temp;
    for(int i=0;i<5;i++){
        for(int j =i+1;j<5;j++){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp; 
        }
    }
    for(int i=0;i<5;i++) printf("%d ",arr[i]);

    return 0;
}