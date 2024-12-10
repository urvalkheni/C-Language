#include<stdio.h>
int main(){
    double population = 1441981744.0;
    double female = (1441981744 * 48.4) / 100;
    double male = (1441981744 * 51.6)/100;
    double literacy = 1441981744 * (85.95/100); 
    double maleLiteracyRate = male * (80.95/100);
    double feamleLiteracyRate = female * (62.84/100);
    printf("Total Population is %.0f . \n",population);
    printf("Total female out of Population is %.0f. \n",female);
    printf("Total male out of Population is %.0f. \n",male);
    printf("Total Literacy rate of Population is %.0f. \n",literacy);
    printf("Total Literacy rate of Male Population is %.0f. \n",maleLiteracyRate);
    printf("Total Literacy rate of Female Population is %.0f. \n",feamleLiteracyRate);
    return 0;
}