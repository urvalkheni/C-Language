#include<stdio.h>
int main() {
    for(int i = 0; i <= 255; i++) { // Only up to 255, as ASCII values range from 0–255
       printf("|%c| ",i);
    }
    return 0;
}
