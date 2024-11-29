//For two number sum printf //
#include<stdio.h>
int main(){
    int arr[7],pair,sum,pairsum=0;
    printf("Enter The pair sum array :: ");
    scanf("%d",&pair);
    printf("Enter Array Elements :: ");
    for(int i=0;i<7;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            if(arr[i]+arr[j]==pair) {
                pairsum += 1;
            printf("The pair is (%d,%d). \n",arr[i],arr[j]);
            }
        }
    }
    printf("Total number of pair which sum is %d are %d. \n",pair,pairsum);
    printf("\n");
    return 0;
}