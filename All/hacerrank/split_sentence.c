#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char str[1000];
    fgets(str, sizeof(str), stdin);

   
    char *token = strtok(str, " \n");

    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " \n");
    }

    return 0;
}