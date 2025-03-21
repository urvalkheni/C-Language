#include <stdio.h>

void delta_to_star(double R1, double R2, double R3) {
    // Calculate Star resistances
    double Ra, Rb, Rc;
    double sum = R1 + R2 + R3;

    Ra = (R1 * R2) / sum;
    Rb = (R2 * R3) / sum;
    Rc = (R3 * R1) / sum;

    // Output the result
    printf("Delta to Star Conversion:\n");
    printf("Star Resistance Ra = %.2f Ohms\n", Ra);
    printf("Star Resistance Rb = %.2f Ohms\n", Rb);
    printf("Star Resistance Rc = %.2f Ohms\n", Rc);
}

int main() {
    double R1, R2, R3;

    // Input Delta resistances
    printf("Enter the resistance R1 (Delta configuration): ");
    scanf("%lf", &R1);

    printf("Enter the resistance R2 (Delta configuration): ");
    scanf("%lf", &R2);

    printf("Enter the resistance R3 (Delta configuration): ");
    scanf("%lf", &R3);

    // Call function to convert Delta to Star
    delta_to_star(R1, R2, R3);

    return 0;
}
