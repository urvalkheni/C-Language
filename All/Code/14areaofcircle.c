// Enhanced Geometric Area Calculator with Advanced Shape Analysis
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define PI 3.14159265358979323846
#define MAX_VERTICES 20

// Structure for 2D point
typedef struct {
    double x, y;
} Point;

// Function prototypes
void displayMainMenu();
void calculateCircleArea();
void calculateEllipseArea();
void calculateTriangleArea();
void calculateRectangleArea();
void calculatePolygonArea();
void calculateSectorArea();
void calculateRingArea();
void calculateTrapezoidArea();
void calculate3DShapes();
void geometricAnalysis();
void unitConversion();
double triangleAreaHeron(double a, double b, double c);
double triangleAreaCoordinates(Point p1, Point p2, Point p3);
double polygonAreaShoelace(Point vertices[], int n);
void displayShapeProperties(const char* shapeName, double area, double perimeter);

int main() {
    int choice;
    
    printf("===============================================\n");
    printf("    ENHANCED GEOMETRIC CALCULATOR v2.0\n");
    printf("===============================================\n");
    printf("Comprehensive Area & Volume Calculator for\n");
    printf("2D Shapes, 3D Objects, and Geometric Analysis\n");
    printf("===============================================\n\n");

    while(1) {
        displayMainMenu();
        printf("Enter your choice (1-11, 0 to exit): ");
        scanf("%d", &choice);

        switch(choice) {
            case 0:
                printf("\nThank you for using Enhanced Geometric Calculator!\n");
                exit(0);
            case 1:
                calculateCircleArea();
                break;
            case 2:
                calculateEllipseArea();
                break;
            case 3:
                calculateTriangleArea();
                break;
            case 4:
                calculateRectangleArea();
                break;
            case 5:
                calculatePolygonArea();
                break;
            case 6:
                calculateSectorArea();
                break;
            case 7:
                calculateRingArea();
                break;
            case 8:
                calculateTrapezoidArea();
                break;
            case 9:
                calculate3DShapes();
                break;
            case 10:
                geometricAnalysis();
                break;
            case 11:
                unitConversion();
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }

    return 0;
}

void displayMainMenu() {
    printf("\n============== GEOMETRIC CALCULATOR ==============\n");
    printf("1.  Circle (Area, Circumference, Properties)\n");
    printf("2.  Ellipse (Area, Perimeter, Eccentricity)\n");
    printf("3.  Triangle (Multiple Methods)\n");
    printf("4.  Rectangle & Square\n");
    printf("5.  Regular Polygon\n");
    printf("6.  Circle Sector & Segment\n");
    printf("7.  Ring (Annulus)\n");
    printf("8.  Trapezoid & Parallelogram\n");
    printf("9.  3D Shapes (Sphere, Cylinder, Cone, etc.)\n");
    printf("10. Geometric Analysis & Comparisons\n");
    printf("11. Unit Conversion\n");
    printf("0.  Exit\n");
    printf("================================================\n");
}

void calculateCircleArea() {
    double radius, area, circumference, diameter;
    
    printf("\n=== CIRCLE CALCULATIONS ===\n");
    printf("Enter radius: ");
    scanf("%lf", &radius);
    
    if(radius <= 0) {
        printf("Error: Radius must be positive!\n");
        return;
    }
    
    area = PI * radius * radius;
    circumference = 2 * PI * radius;
    diameter = 2 * radius;
    
    printf("\n--- Circle Properties ---\n");
    printf("Radius: %.6f units\n", radius);
    printf("Diameter: %.6f units\n", diameter);
    printf("Area: %.6f square units\n", area);
    printf("Circumference: %.6f units\n", circumference);
    printf("Area using π approximation (22/7): %.6f\n", (22.0/7.0) * radius * radius);
    
    // Additional properties
    printf("\n--- Advanced Properties ---\n");
    printf("Area of inscribed square: %.6f\n", 2 * radius * radius);
    printf("Area of circumscribed square: %.6f\n", 4 * radius * radius);
    printf("Ratio of circle to inscribed square: %.6f\n", PI / 2);
    printf("Ratio of circumscribed square to circle: %.6f\n", 4 / PI);
    
    displayShapeProperties("Circle", area, circumference);
}

void calculateEllipseArea() {
    double a, b, area, perimeter, eccentricity;
    
    printf("\n=== ELLIPSE CALCULATIONS ===\n");
    printf("Enter semi-major axis (a): ");
    scanf("%lf", &a);
    printf("Enter semi-minor axis (b): ");
    scanf("%lf", &b);
    
    if(a <= 0 || b <= 0) {
        printf("Error: Axes must be positive!\n");
        return;
    }
    
    area = PI * a * b;
    // Ramanujan's approximation for ellipse perimeter
    double h = pow((a - b) / (a + b), 2);
    perimeter = PI * (a + b) * (1 + (3 * h) / (10 + sqrt(4 - 3 * h)));
    
    if(a > b) {
        eccentricity = sqrt(1 - (b * b) / (a * a));
    } else {
        eccentricity = sqrt(1 - (a * a) / (b * b));
    }
    
    printf("\n--- Ellipse Properties ---\n");
    printf("Semi-major axis: %.6f\n", a > b ? a : b);
    printf("Semi-minor axis: %.6f\n", a < b ? a : b);
    printf("Area: %.6f square units\n", area);
    printf("Perimeter (approximation): %.6f units\n", perimeter);
    printf("Eccentricity: %.6f\n", eccentricity);
    printf("Focus distance from center: %.6f\n", sqrt(fabs(a*a - b*b)));
    
    if(fabs(a - b) < 0.0001) {
        printf("Note: This is essentially a circle!\n");
    }
}

void calculateTriangleArea() {
    int method;
    double area;
    
    printf("\n=== TRIANGLE CALCULATIONS ===\n");
    printf("Choose method:\n");
    printf("1. Three sides (Heron's formula)\n");
    printf("2. Base and height\n");
    printf("3. Three coordinates\n");
    printf("4. Two sides and included angle\n");
    printf("Enter choice: ");
    scanf("%d", &method);
    
    switch(method) {
        case 1: {
            double a, b, c;
            printf("Enter three sides:\n");
            printf("Side a: "); scanf("%lf", &a);
            printf("Side b: "); scanf("%lf", &b);
            printf("Side c: "); scanf("%lf", &c);
            
            // Triangle inequality check
            if(a + b <= c || b + c <= a || a + c <= b) {
                printf("Error: Invalid triangle! Triangle inequality violated.\n");
                return;
            }
            
            area = triangleAreaHeron(a, b, c);
            double perimeter = a + b + c;
            double s = perimeter / 2;
            double inradius = area / s;
            double circumradius = (a * b * c) / (4 * area);
            
            printf("\n--- Triangle Properties ---\n");
            printf("Sides: %.3f, %.3f, %.3f\n", a, b, c);
            printf("Area: %.6f square units\n", area);
            printf("Perimeter: %.6f units\n", perimeter);
            printf("Semi-perimeter: %.6f units\n", s);
            printf("Inradius: %.6f units\n", inradius);
            printf("Circumradius: %.6f units\n", circumradius);
            
            // Triangle type
            double max_side = fmax(fmax(a, b), c);
            double sum_squares = a*a + b*b + c*c - max_side*max_side;
            if(fabs(sum_squares - max_side*max_side) < 0.0001) {
                printf("Triangle type: Right triangle\n");
            } else if(sum_squares > max_side*max_side) {
                printf("Triangle type: Acute triangle\n");
            } else {
                printf("Triangle type: Obtuse triangle\n");
            }
            break;
        }
        case 2: {
            double base, height;
            printf("Enter base: "); scanf("%lf", &base);
            printf("Enter height: "); scanf("%lf", &height);
            
            if(base <= 0 || height <= 0) {
                printf("Error: Base and height must be positive!\n");
                return;
            }
            
            area = 0.5 * base * height;
            printf("\nArea: %.6f square units\n", area);
            break;
        }
        case 3: {
            Point p1, p2, p3;
            printf("Enter coordinates of three vertices:\n");
            printf("Point 1 (x y): "); scanf("%lf %lf", &p1.x, &p1.y);
            printf("Point 2 (x y): "); scanf("%lf %lf", &p2.x, &p2.y);
            printf("Point 3 (x y): "); scanf("%lf %lf", &p3.x, &p3.y);
            
            area = triangleAreaCoordinates(p1, p2, p3);
            if(area == 0) {
                printf("Error: Points are collinear!\n");
                return;
            }
            
            printf("\nArea: %.6f square units\n", area);
            break;
        }
        case 4: {
            double side1, side2, angle;
            printf("Enter first side: "); scanf("%lf", &side1);
            printf("Enter second side: "); scanf("%lf", &side2);
            printf("Enter included angle (degrees): "); scanf("%lf", &angle);
            
            area = 0.5 * side1 * side2 * sin(angle * PI / 180);
            printf("\nArea: %.6f square units\n", area);
            break;
        }
        default:
            printf("Invalid method!\n");
    }
}

void calculateRectangleArea() {
    double length, width, area, perimeter, diagonal;
    
    printf("\n=== RECTANGLE CALCULATIONS ===\n");
    printf("Enter length: "); scanf("%lf", &length);
    printf("Enter width: "); scanf("%lf", &width);
    
    if(length <= 0 || width <= 0) {
        printf("Error: Dimensions must be positive!\n");
        return;
    }
    
    area = length * width;
    perimeter = 2 * (length + width);
    diagonal = sqrt(length * length + width * width);
    
    printf("\n--- Rectangle Properties ---\n");
    printf("Length: %.6f units\n", length);
    printf("Width: %.6f units\n", width);
    printf("Area: %.6f square units\n", area);
    printf("Perimeter: %.6f units\n", perimeter);
    printf("Diagonal: %.6f units\n", diagonal);
    
    if(fabs(length - width) < 0.0001) {
        printf("Note: This is a square!\n");
        printf("Area of inscribed circle: %.6f\n", PI * pow(length/2, 2));
        printf("Area of circumscribed circle: %.6f\n", PI * pow(diagonal/2, 2));
    }
    
    displayShapeProperties("Rectangle", area, perimeter);
}

void calculatePolygonArea() {
    int sides;
    double sideLength, area, perimeter, apothem, circumradius, inradius;
    
    printf("\n=== REGULAR POLYGON CALCULATIONS ===\n");
    printf("Enter number of sides: "); scanf("%d", &sides);
    printf("Enter side length: "); scanf("%lf", &sideLength);
    
    if(sides < 3 || sideLength <= 0) {
        printf("Error: Invalid input!\n");
        return;
    }
    
    double angle = PI / sides;
    apothem = sideLength / (2 * tan(angle));
    perimeter = sides * sideLength;
    area = 0.5 * perimeter * apothem;
    circumradius = sideLength / (2 * sin(angle));
    inradius = apothem;
    
    printf("\n--- Regular %d-gon Properties ---\n", sides);
    printf("Side length: %.6f units\n", sideLength);
    printf("Area: %.6f square units\n", area);
    printf("Perimeter: %.6f units\n", perimeter);
    printf("Apothem (inradius): %.6f units\n", inradius);
    printf("Circumradius: %.6f units\n", circumradius);
    printf("Central angle: %.6f degrees\n", 360.0 / sides);
    printf("Interior angle: %.6f degrees\n", 180.0 * (sides - 2) / sides);
    
    // Compare to circle
    double circumscribedCircleArea = PI * circumradius * circumradius;
    double inscribedCircleArea = PI * inradius * inradius;
    printf("\nComparison to circles:\n");
    printf("Circumscribed circle area: %.6f\n", circumscribedCircleArea);
    printf("Inscribed circle area: %.6f\n", inscribedCircleArea);
    printf("Polygon efficiency: %.4f%%\n", (area / circumscribedCircleArea) * 100);
}

void calculateSectorArea() {
    double radius, angle, area, arcLength;
    int angleType;
    
    printf("\n=== CIRCLE SECTOR CALCULATIONS ===\n");
    printf("Enter radius: "); scanf("%lf", &radius);
    printf("Angle in: 1-Degrees, 2-Radians: "); scanf("%d", &angleType);
    printf("Enter angle: "); scanf("%lf", &angle);
    
    if(radius <= 0) {
        printf("Error: Radius must be positive!\n");
        return;
    }
    
    double angleRad = (angleType == 1) ? angle * PI / 180 : angle;
    area = 0.5 * radius * radius * angleRad;
    arcLength = radius * angleRad;
    
    printf("\n--- Sector Properties ---\n");
    printf("Radius: %.6f units\n", radius);
    printf("Angle: %.6f degrees (%.6f radians)\n", angleRad * 180 / PI, angleRad);
    printf("Sector area: %.6f square units\n", area);
    printf("Arc length: %.6f units\n", arcLength);
    printf("Sector perimeter: %.6f units\n", arcLength + 2 * radius);
    
    double fullCircleArea = PI * radius * radius;
    printf("Percentage of full circle: %.4f%%\n", (area / fullCircleArea) * 100);
}

void calculateRingArea() {
    double outerRadius, innerRadius, area;
    
    printf("\n=== RING (ANNULUS) CALCULATIONS ===\n");
    printf("Enter outer radius: "); scanf("%lf", &outerRadius);
    printf("Enter inner radius: "); scanf("%lf", &innerRadius);
    
    if(outerRadius <= 0 || innerRadius <= 0 || innerRadius >= outerRadius) {
        printf("Error: Invalid radii! Outer radius must be greater than inner radius.\n");
        return;
    }
    
    area = PI * (outerRadius * outerRadius - innerRadius * innerRadius);
    double outerCircumference = 2 * PI * outerRadius;
    double innerCircumference = 2 * PI * innerRadius;
    double width = outerRadius - innerRadius;
    
    printf("\n--- Ring Properties ---\n");
    printf("Outer radius: %.6f units\n", outerRadius);
    printf("Inner radius: %.6f units\n", innerRadius);
    printf("Ring width: %.6f units\n", width);
    printf("Ring area: %.6f square units\n", area);
    printf("Outer circumference: %.6f units\n", outerCircumference);
    printf("Inner circumference: %.6f units\n", innerCircumference);
    printf("Average circumference: %.6f units\n", (outerCircumference + innerCircumference) / 2);
}

void calculateTrapezoidArea() {
    double base1, base2, height, area;
    
    printf("\n=== TRAPEZOID CALCULATIONS ===\n");
    printf("Enter first parallel side: "); scanf("%lf", &base1);
    printf("Enter second parallel side: "); scanf("%lf", &base2);
    printf("Enter height: "); scanf("%lf", &height);
    
    if(base1 <= 0 || base2 <= 0 || height <= 0) {
        printf("Error: All dimensions must be positive!\n");
        return;
    }
    
    area = 0.5 * (base1 + base2) * height;
    double averageBase = (base1 + base2) / 2;
    
    printf("\n--- Trapezoid Properties ---\n");
    printf("Parallel sides: %.6f, %.6f units\n", base1, base2);
    printf("Height: %.6f units\n", height);
    printf("Area: %.6f square units\n", area);
    printf("Average of parallel sides: %.6f units\n", averageBase);
    
    if(fabs(base1 - base2) < 0.0001) {
        printf("Note: This is a rectangle!\n");
    }
}

void calculate3DShapes() {
    int shape;
    
    printf("\n=== 3D SHAPE CALCULATIONS ===\n");
    printf("1. Sphere\n2. Cylinder\n3. Cone\n4. Cube\n5. Rectangular Prism\n");
    printf("Choose shape: "); scanf("%d", &shape);
    
    switch(shape) {
        case 1: {
            double radius, volume, surfaceArea;
            printf("Enter radius: "); scanf("%lf", &radius);
            
            volume = (4.0/3.0) * PI * pow(radius, 3);
            surfaceArea = 4 * PI * radius * radius;
            
            printf("\n--- Sphere Properties ---\n");
            printf("Radius: %.6f units\n", radius);
            printf("Volume: %.6f cubic units\n", volume);
            printf("Surface area: %.6f square units\n", surfaceArea);
            printf("Great circle area: %.6f square units\n", PI * radius * radius);
            break;
        }
        case 2: {
            double radius, height, volume, surfaceArea;
            printf("Enter radius: "); scanf("%lf", &radius);
            printf("Enter height: "); scanf("%lf", &height);
            
            volume = PI * radius * radius * height;
            surfaceArea = 2 * PI * radius * (radius + height);
            
            printf("\n--- Cylinder Properties ---\n");
            printf("Radius: %.6f, Height: %.6f units\n", radius, height);
            printf("Volume: %.6f cubic units\n", volume);
            printf("Surface area: %.6f square units\n", surfaceArea);
            printf("Lateral area: %.6f square units\n", 2 * PI * radius * height);
            break;
        }
        case 3: {
            double radius, height, volume, surfaceArea, slantHeight;
            printf("Enter radius: "); scanf("%lf", &radius);
            printf("Enter height: "); scanf("%lf", &height);
            
            slantHeight = sqrt(radius * radius + height * height);
            volume = (1.0/3.0) * PI * radius * radius * height;
            surfaceArea = PI * radius * (radius + slantHeight);
            
            printf("\n--- Cone Properties ---\n");
            printf("Radius: %.6f, Height: %.6f units\n", radius, height);
            printf("Slant height: %.6f units\n", slantHeight);
            printf("Volume: %.6f cubic units\n", volume);
            printf("Surface area: %.6f square units\n", surfaceArea);
            break;
        }
    }
}

void geometricAnalysis() {
    printf("\n=== GEOMETRIC ANALYSIS TOOLS ===\n");
    printf("This section provides comparative analysis between shapes\n");
    printf("and mathematical relationships in geometry.\n\n");
    
    printf("Famous geometric relationships:\n");
    printf("1. Circle vs Square: π/4 ≈ 0.7854 (area ratio for same perimeter)\n");
    printf("2. Sphere vs Cube: π/6 ≈ 0.5236 (volume ratio for same surface area)\n");
    printf("3. Golden Ratio in Pentagon: φ = (1+√5)/2 ≈ 1.618\n");
    printf("4. Isoperimetric inequality: Circle has maximum area for given perimeter\n");
    printf("5. Euler's formula for polyhedra: V - E + F = 2\n");
}

void unitConversion() {
    printf("\n=== UNIT CONVERSION ===\n");
    printf("Convert between different area units\n");
    
    double value;
    int fromUnit, toUnit;
    
    printf("Enter area value: "); scanf("%lf", &value);
    printf("From unit: 1-sq.m, 2-sq.ft, 3-sq.in, 4-hectare, 5-acre: ");
    scanf("%d", &fromUnit);
    printf("To unit: 1-sq.m, 2-sq.ft, 3-sq.in, 4-hectare, 5-acre: ");
    scanf("%d", &toUnit);
    
    // Convert to square meters first
    double sqMeters = value;
    switch(fromUnit) {
        case 2: sqMeters = value * 0.092903; break;
        case 3: sqMeters = value * 0.00064516; break;
        case 4: sqMeters = value * 10000; break;
        case 5: sqMeters = value * 4046.86; break;
    }
    
    // Convert to target unit
    double result = sqMeters;
    switch(toUnit) {
        case 2: result = sqMeters / 0.092903; break;
        case 3: result = sqMeters / 0.00064516; break;
        case 4: result = sqMeters / 10000; break;
        case 5: result = sqMeters / 4046.86; break;
    }
    
    printf("Result: %.6f\n", result);
}

// Helper functions
double triangleAreaHeron(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double triangleAreaCoordinates(Point p1, Point p2, Point p3) {
    return fabs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2.0);
}

void displayShapeProperties(const char* shapeName, double area, double perimeter) {
    printf("\n--- Shape Analysis ---\n");
    printf("Shape: %s\n", shapeName);
    printf("Compactness ratio: %.6f\n", 4 * PI * area / (perimeter * perimeter));
    printf("(Closer to 1.0 means more compact, circle = 1.0)\n");
}