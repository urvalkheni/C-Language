//For three Numbers //
#include<stdio.h>
int main(){
    int arr[8]={};
    int pair=12,sum,pairsum=0;
    // printf("Enter The pair sum array :: ");
    // scanf("%d",&pair);
    for(int i=0;i<8;i++){
        printf("Enter Array Elements :: ");
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<8;i++){
        for(int j=i+1;j<8;j++){
            for(int k=j+1;k<8;k++){
            if(arr[i]+arr[j]+arr[k]==pair){
                pairsum += 1;
            printf("The pair is (%d,%d,%d). \n",arr[i],arr[j],arr[k]);
            }
            }
        }
    }
    printf("Total number of pair which sum is %d are %d. \n",pair,pairsum);
    printf("\n");
    return 0;
}