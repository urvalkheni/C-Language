#include <stdio.h>

void star_to_delta(double Ra, double Rb, double Rc) {
    // Calculate Delta resistances
    double R1, R2, R3;
    R1 = (Ra * Rb + Rb * Rc + Rc * Ra) / Ra;
    R2 = (Ra * Rb + Rb * Rc + Rc * Ra) / Rb;
    R3 = (Ra * Rb + Rb * Rc + Rc * Ra) / Rc;

    // Output the result
    printf("Star to Delta Conversion:\n");
    printf("Delta Resistance R1 = %.2f Ohms\n", R1);
    printf("Delta Resistance R2 = %.2f Ohms\n", R2);
    printf("Delta Resistance R3 = %.2f Ohms\n", R3);
}

int main() {
    double Ra, Rb, Rc;

    // Input Star resistances
    printf("Enter the resistance Ra (Star configuration): ");
    scanf("%lf", &Ra);

    printf("Enter the resistance Rb (Star configuration): ");
    scanf("%lf", &Rb);

    printf("Enter the resistance Rc (Star configuration): ");
    scanf("%lf", &Rc);

    // Call function to convert Star to Delta
    star_to_delta(Ra, Rb, Rc);

    return 0;
}
