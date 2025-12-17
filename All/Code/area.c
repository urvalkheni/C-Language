/*
 * Advanced Area & Volume Calculator v2.0
 * Features: 2D shapes, 3D solids, conversions,
 *           comprehensive geometric calculations
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function prototypes
double circleArea(double r);
double circlePerimeter(double r);
double rectangleArea(double l, double w);
double rectanglePerimeter(double l, double w);
double triangleArea(double b, double h);
double trianglePerimeterHerons(double a, double b, double c);
double squareArea(double s);
double squarePerimeter(double s);
double trapezoidArea(double a, double b, double h);
double ellipseArea(double a, double b);
double sectorArea(double r, double angle);
double sphereVolume(double r);
double sphereSurfaceArea(double r);
double cubeVolume(double s);
double cubeSurfaceArea(double s);
double cylinderVolume(double r, double h);
double cylinderSurfaceArea(double r, double h);
double coneVolume(double r, double h);
double coneSurfaceArea(double r, double h);
double rectangularPrismVolume(double l, double w, double h);
void displayMenu();

// Main function
int main() {
    int choice;
    double r, l, w, h, s, a, b, c, angle;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║       Advanced Area & Volume Calculator v2.0              ║\n");
    printf("║          2D Shapes & 3D Solids Calculator                 ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-20): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\n--- Circle Area & Perimeter ---\n");
                printf("Enter radius: ");
                scanf("%lf", &r);
                if(r <= 0) {
                    printf("Error: Radius must be positive!\n");
                    break;
                }
                printf("Area: %.2f\n", circleArea(r));
                printf("Perimeter (Circumference): %.2f\n", circlePerimeter(r));
                break;
                
            case 2:
                printf("\n--- Rectangle Area & Perimeter ---\n");
                printf("Enter length: ");
                scanf("%lf", &l);
                printf("Enter width: ");
                scanf("%lf", &w);
                if(l <= 0 || w <= 0) {
                    printf("Error: Length and width must be positive!\n");
                    break;
                }
                printf("Area: %.2f\n", rectangleArea(l, w));
                printf("Perimeter: %.2f\n", rectanglePerimeter(l, w));
                break;
                
            case 3:
                printf("\n--- Triangle Area ---\n");
                printf("Enter base: ");
                scanf("%lf", &b);
                printf("Enter height: ");
                scanf("%lf", &h);
                if(b <= 0 || h <= 0) {
                    printf("Error: Base and height must be positive!\n");
                    break;
                }
                printf("Area: %.2f\n", triangleArea(b, h));
                break;
                
            case 4:
                printf("\n--- Triangle (Heron's Formula) ---\n");
                printf("Enter side a: ");
                scanf("%lf", &a);
                printf("Enter side b: ");
                scanf("%lf", &b);
                printf("Enter side c: ");
                scanf("%lf", &c);
                double s_val = (a + b + c) / 2;
                double area = sqrt(s_val * (s_val - a) * (s_val - b) * (s_val - c));
                printf("Area: %.2f\n", area);
                printf("Perimeter: %.2f\n", a + b + c);
                break;
                
            case 5:
                printf("\n--- Square Area & Perimeter ---\n");
                printf("Enter side: ");
                scanf("%lf", &s);
                if(s <= 0) {
                    printf("Error: Side must be positive!\n");
                    break;
                }
                printf("Area: %.2f\n", squareArea(s));
                printf("Perimeter: %.2f\n", squarePerimeter(s));
                printf("Diagonal: %.2f\n", s * sqrt(2));
                break;
                
            case 6:
                printf("\n--- Trapezoid Area ---\n");
                printf("Enter parallel side a: ");
                scanf("%lf", &a);
                printf("Enter parallel side b: ");
                scanf("%lf", &b);
                printf("Enter height: ");
                scanf("%lf", &h);
                if(a <= 0 || b <= 0 || h <= 0) {
                    printf("Error: All dimensions must be positive!\n");
                    break;
                }
                printf("Area: %.2f\n", trapezoidArea(a, b, h));
                break;
                
            case 7:
                printf("\n--- Ellipse Area ---\n");
                printf("Enter semi-major axis a: ");
                scanf("%lf", &a);
                printf("Enter semi-minor axis b: ");
                scanf("%lf", &b);
                printf("Area: %.2f\n", ellipseArea(a, b));
                break;
                
            case 8:
                printf("\n--- Circle Sector Area ---\n");
                printf("Enter radius: ");
                scanf("%lf", &r);
                printf("Enter angle (degrees): ");
                scanf("%lf", &angle);
                printf("Area: %.2f\n", sectorArea(r, angle));
                break;
                
            case 9:
                printf("\n--- Sphere Volume & Surface Area ---\n");
                printf("Enter radius: ");
                scanf("%lf", &r);
                if(r <= 0) {
                    printf("Error: Radius must be positive!\n");
                    break;
                }
                printf("Volume: %.2f\n", sphereVolume(r));
                printf("Surface Area: %.2f\n", sphereSurfaceArea(r));
                break;
                
            case 10:
                printf("\n--- Cube Volume & Surface Area ---\n");
                printf("Enter side: ");
                scanf("%lf", &s);
                printf("Volume: %.2f\n", cubeVolume(s));
                printf("Surface Area: %.2f\n", cubeSurfaceArea(s));
                printf("Space Diagonal: %.2f\n", s * sqrt(3));
                break;
                
            case 11:
                printf("\n--- Cylinder Volume & Surface Area ---\n");
                printf("Enter radius: ");
                scanf("%lf", &r);
                printf("Enter height: ");
                scanf("%lf", &h);
                printf("Volume: %.2f\n", cylinderVolume(r, h));
                printf("Surface Area: %.2f\n", cylinderSurfaceArea(r, h));
                break;
                
            case 12:
                printf("\n--- Cone Volume & Surface Area ---\n");
                printf("Enter radius: ");
                scanf("%lf", &r);
                printf("Enter height: ");
                scanf("%lf", &h);
                printf("Volume: %.2f\n", coneVolume(r, h));
                printf("Surface Area: %.2f\n", coneSurfaceArea(r, h));
                break;
                
            case 13:
                printf("\n--- Rectangular Prism ---\n");
                printf("Enter length: ");
                scanf("%lf", &l);
                printf("Enter width: ");
                scanf("%lf", &w);
                printf("Enter height: ");
                scanf("%lf", &h);
                printf("Volume: %.2f\n", rectangularPrismVolume(l, w, h));
                printf("Surface Area: %.2f\n", 2 * (l*w + w*h + h*l));
                break;
                
            case 14:
                printf("\n--- Regular Polygon Area ---\n");
                printf("Enter number of sides: ");
                int n;
                scanf("%d", &n);
                printf("Enter side length: ");
                scanf("%lf", &s);
                double polygon_area = (n * s * s) / (4 * tan(PI / n));
                printf("Area: %.2f\n", polygon_area);
                break;
                
            case 15:
                printf("\n--- Annulus (Ring) Area ---\n");
                printf("Enter outer radius: ");
                scanf("%lf", &a);
                printf("Enter inner radius: ");
                scanf("%lf", &b);
                printf("Area: %.2f\n", PI * (a*a - b*b));
                break;
                
            case 16:
                printf("\n--- Hemisphere ---\n");
                printf("Enter radius: ");
                scanf("%lf", &r);
                printf("Volume: %.2f\n", (2.0/3.0) * PI * r * r * r);
                printf("Curved Surface Area: %.2f\n", 2 * PI * r * r);
                printf("Total Surface Area: %.2f\n", 3 * PI * r * r);
                break;
                
            case 17:
                printf("\n--- Pyramid Volume ---\n");
                printf("Enter base area: ");
                scanf("%lf", &a);
                printf("Enter height: ");
                scanf("%lf", &h);
                printf("Volume: %.2f\n", (1.0/3.0) * a * h);
                break;
                
            case 18:
                printf("\n--- Torus Volume & Surface Area ---\n");
                printf("Enter major radius R: ");
                scanf("%lf", &a);
                printf("Enter minor radius r: ");
                scanf("%lf", &b);
                printf("Volume: %.2f\n", 2 * PI * PI * a * b * b);
                printf("Surface Area: %.2f\n", 4 * PI * PI * a * b);
                break;
                
            case 19:
                printf("\n--- Area Converter ---\n");
                printf("Enter area in square meters: ");
                scanf("%lf", &a);
                printf("\nConversions:\n");
                printf("Square centimeters: %.2f\n", a * 10000);
                printf("Square feet: %.2f\n", a * 10.7639);
                printf("Square yards: %.2f\n", a * 1.19599);
                printf("Acres: %.6f\n", a * 0.000247105);
                break;
                
            case 20: {
                printf("\n--- Quick Reference ---\n");
                printf("\n2D SHAPES:\n");
                printf("Circle: πr²\n");
                printf("Rectangle: l × w\n");
                printf("Triangle: ½ × b × h\n");
                printf("Square: s²\n");
                printf("\n3D SOLIDS:\n");
                printf("Sphere: (4/3)πr³\n");
                printf("Cube: s³\n");
                printf("Cylinder: πr²h\n");
                printf("Cone: (1/3)πr²h\n");
                break;
            }
                
            case 0:
                printf("\n✓ Thank you for using Area Calculator!\n");
                break;
                
            default:
                printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  2D SHAPES                                              │\n");
    printf("│  [1]  Circle                                            │\n");
    printf("│  [2]  Rectangle                                         │\n");
    printf("│  [3]  Triangle (Base & Height)                          │\n");
    printf("│  [4]  Triangle (Heron's Formula)                        │\n");
    printf("│  [5]  Square                                            │\n");
    printf("│  [6]  Trapezoid                                         │\n");
    printf("│  [7]  Ellipse                                           │\n");
    printf("│  [8]  Circle Sector                                     │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  3D SOLIDS                                              │\n");
    printf("│  [9]  Sphere                                            │\n");
    printf("│  [10] Cube                                              │\n");
    printf("│  [11] Cylinder                                          │\n");
    printf("│  [12] Cone                                              │\n");
    printf("│  [13] Rectangular Prism (Cuboid)                        │\n");
    printf("│  [14] Regular Polygon                                   │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED SHAPES                                        │\n");
    printf("│  [15] Annulus (Ring)                                    │\n");
    printf("│  [16] Hemisphere                                        │\n");
    printf("│  [17] Pyramid                                           │\n");
    printf("│  [18] Torus (Donut)                                     │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  UTILITIES                                              │\n");
    printf("│  [19] Area Unit Converter                               │\n");
    printf("│  [20] Formula Quick Reference                           │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

double circleArea(double r) {
    return PI * r * r;
}

double circlePerimeter(double r) {
    return 2 * PI * r;
}

double rectangleArea(double l, double w) {
    return l * w;
}

double rectanglePerimeter(double l, double w) {
    return 2 * (l + w);
}

double triangleArea(double b, double h) {
    return 0.5 * b * h;
}

double squareArea(double s) {
    return s * s;
}

double squarePerimeter(double s) {
    return 4 * s;
}

double trapezoidArea(double a, double b, double h) {
    return 0.5 * (a + b) * h;
}

double ellipseArea(double a, double b) {
    return PI * a * b;
}

double sectorArea(double r, double angle) {
    return (angle / 360.0) * PI * r * r;
}

double sphereVolume(double r) {
    return (4.0 / 3.0) * PI * r * r * r;
}

double sphereSurfaceArea(double r) {
    return 4 * PI * r * r;
}

double cubeVolume(double s) {
    return s * s * s;
}

double cubeSurfaceArea(double s) {
    return 6 * s * s;
}

double cylinderVolume(double r, double h) {
    return PI * r * r * h;
}

double cylinderSurfaceArea(double r, double h) {
    return 2 * PI * r * (r + h);
}

double coneVolume(double r, double h) {
    return (1.0 / 3.0) * PI * r * r * h;
}

double coneSurfaceArea(double r, double h) {
    double slant = sqrt(r * r + h * h);
    return PI * r * (r + slant);
}

double rectangularPrismVolume(double l, double w, double h) {
    return l * w * h;
}