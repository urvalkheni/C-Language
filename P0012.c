//Find Profit or Lose //
#include<stdio.h>
int main(){
    float costprice,sellprice;
    float profit,lose;

    printf("Please enter the cost price of the product :: ");
    scanf("%f",&costprice);
    printf("Please enter the sell price of the product :: ");
    scanf("%f",&sellprice);

    if(sellprice>costprice){
        profit = sellprice - costprice;
        printf("You Get Profit worth '%f' rupees.",profit);
    }
    if(sellprice<costprice){
        lose = costprice - sellprice;
        printf("You Get Lose worth '%f' rupees.",lose);
    }
    
    return 0;
}
