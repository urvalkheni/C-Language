// Nested if program //
#include<stdio.h>
int main(){
      int i;
      printf("Enter the number :: ");
      scanf("%d",&i);
      if(i%3==0){
        if(i%5==0){
            printf("Number Divisable by 3 and 5.");
        }
        else{
            printf("Number is not Divisable by 3 and 5.");
        }
      }
      else{
        printf("Number is not Divisable by 3 and 5.");
      }
      return 0;
}