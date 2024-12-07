#include<stdio.h>

int main() {
    char s1[5] = "URVAL"; // Correctly null-terminated
    char s2[6] = "KRSIH"; // Increased size to accommodate the null terminator

    printf("%s\n", s1); // Properly prints the null-terminated string s1
    printf("%s\n", s2); // Properly prints the null-terminated string s2

    return 0;
}
