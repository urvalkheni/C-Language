/*
 * Advanced Rectangle Calculator & Geometry Analyzer v2.0
 * Features: Area, perimeter, diagonal, geometric properties,
 *           multiple rectangle operations, comparisons
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Function prototypes
void basicRectangleCalculator();
void diagonalCalculator();
void rectangleComparison();
void goldenRectangleCheck();
void areaPerimeterRatio();
void rectangleScaling();
void multipleRectangles();
void rectangleIntersection();
void circumscribedCircle();
void inscribedCircle();
void rectangleTransformation();
void costCalculation();
void tileCalculator();
void rectangleProperties();
void visualizeRectangle();
void displayMenu();

int main() {
    int choice;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║   Advanced Rectangle Calculator & Geometry Analyzer v2.0  ║\n");
    printf("║          Comprehensive Geometric Analysis Tool            ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                basicRectangleCalculator();
                break;
            case 2:
                diagonalCalculator();
                break;
            case 3:
                rectangleComparison();
                break;
            case 4:
                goldenRectangleCheck();
                break;
            case 5:
                areaPerimeterRatio();
                break;
            case 6:
                rectangleScaling();
                break;
            case 7:
                multipleRectangles();
                break;
            case 8:
                rectangleIntersection();
                break;
            case 9:
                circumscribedCircle();
                break;
            case 10:
                inscribedCircle();
                break;
            case 11:
                rectangleTransformation();
                break;
            case 12:
                costCalculation();
                break;
            case 13:
                tileCalculator();
                break;
            case 14:
                rectangleProperties();
                break;
            case 15:
                visualizeRectangle();
                break;
            case 16:
                printf("\n--- Rectangle Properties ---\n");
                printf("\n• Area = Length × Width\n");
                printf("• Perimeter = 2 × (Length + Width)\n");
                printf("• Diagonal = √(Length² + Width²)\n");
                printf("• Golden Rectangle: Length/Width ≈ 1.618\n");
                break;
            case 0:
                break;
            default:
                printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Rectangle Calculator!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC CALCULATIONS                                     │\n");
    printf("│  [1]  Basic Rectangle Calculator                        │\n");
    printf("│  [2]  Diagonal Calculator                               │\n");
    printf("│  [3]  Rectangle Comparison                              │\n");
    printf("│  [4]  Golden Rectangle Check                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED ANALYSIS                                      │\n");
    printf("│  [5]  Area-Perimeter Ratio                              │\n");
    printf("│  [6]  Rectangle Scaling                                 │\n");
    printf("│  [7]  Multiple Rectangles                               │\n");
    printf("│  [8]  Rectangle Intersection                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  GEOMETRIC OPERATIONS                                   │\n");
    printf("│  [9]  Circumscribed Circle                              │\n");
    printf("│  [10] Inscribed Circle                                  │\n");
    printf("│  [11] Rectangle Transformation                          │\n");
    printf("│  [12] Cost Calculation                                  │\n");
    printf("│  [13] Tile Calculator                                   │\n");
    printf("│  [14] Rectangle Properties                              │\n");
    printf("│  [15] Visualize Rectangle                               │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Rectangle Properties Info                         │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void basicRectangleCalculator() {
    double length, height, area, perimeter;
    
    printf("\nPlease enter the Length of Rectangle :: ");
    scanf("%lf", &length);
    printf("Please enter the Height of Rectangle :: ");
    scanf("%lf", &height);
    
    area = length * height;
    perimeter = 2 * (length + height);
    
    printf("\n--- Rectangle Calculations ---\n");
    printf("The Area Of rectangle is :: %.2f\n", area);
    printf("The perimeter of rectangle is :: %.2f\n", perimeter);
    
    if(area > perimeter) {
        printf("The Area of Rectangle is Bigger than Perimeter.\n");
    } else if(area < perimeter) {
        printf("The Perameter of Rectangle is Bigger than Area.\n");
    } else {
        printf("Area and Perimeter are equal.\n");
    }
}

void diagonalCalculator() {
    double length, width, diagonal;
    
    printf("\nEnter length: ");
    scanf("%lf", &length);
    printf("Enter width: ");
    scanf("%lf", &width);
    
    diagonal = sqrt(length * length + width * width);
    
    printf("\n--- Diagonal Calculation ---\n");
    printf("Length: %.2f\n", length);
    printf("Width: %.2f\n", width);
    printf("Diagonal: %.2f\n", diagonal);
    printf("Formula: √(L² + W²) = √(%.2f² + %.2f²)\n", length, width);
}

void rectangleComparison() {
    double l1, w1, l2, w2;
    double area1, area2, peri1, peri2;
    
    printf("\nRectangle 1 - Enter length: ");
    scanf("%lf", &l1);
    printf("Rectangle 1 - Enter width: ");
    scanf("%lf", &w1);
    
    printf("Rectangle 2 - Enter length: ");
    scanf("%lf", &l2);
    printf("Rectangle 2 - Enter width: ");
    scanf("%lf", &w2);
    
    area1 = l1 * w1;
    area2 = l2 * w2;
    peri1 = 2 * (l1 + w1);
    peri2 = 2 * (l2 + w2);
    
    printf("\n--- Rectangle Comparison ---\n");
    printf("Rectangle 1: Area=%.2f, Perimeter=%.2f\n", area1, peri1);
    printf("Rectangle 2: Area=%.2f, Perimeter=%.2f\n", area2, peri2);
    
    if(area1 > area2)
        printf("Rectangle 1 has larger area (by %.2f)\n", area1 - area2);
    else if(area2 > area1)
        printf("Rectangle 2 has larger area (by %.2f)\n", area2 - area1);
    else
        printf("Both rectangles have equal area\n");
}

void goldenRectangleCheck() {
    double length, width, ratio;
    const double GOLDEN_RATIO = 1.618033988749895;
    
    printf("\nEnter length: ");
    scanf("%lf", &length);
    printf("Enter width: ");
    scanf("%lf", &width);
    
    ratio = length / width;
    
    printf("\n--- Golden Rectangle Check ---\n");
    printf("Length/Width ratio: %.6f\n", ratio);
    printf("Golden ratio (φ): %.6f\n", GOLDEN_RATIO);
    
    if(fabs(ratio - GOLDEN_RATIO) < 0.1) {
        printf("✓ This is approximately a Golden Rectangle!\n");
    } else {
        printf("✗ This is not a Golden Rectangle\n");
        printf("Difference: %.6f\n", fabs(ratio - GOLDEN_RATIO));
    }
}

void areaPerimeterRatio() {
    double length, width, area, perimeter, ratio;
    
    printf("\nEnter length: ");
    scanf("%lf", &length);
    printf("Enter width: ");
    scanf("%lf", &width);
    
    area = length * width;
    perimeter = 2 * (length + width);
    ratio = area / perimeter;
    
    printf("\n--- Area-Perimeter Ratio ---\n");
    printf("Area: %.2f\n", area);
    printf("Perimeter: %.2f\n", perimeter);
    printf("Ratio (Area/Perimeter): %.4f\n", ratio);
    
    if(ratio > 1.0)
        printf("Area is %.2f times larger than perimeter\n", ratio);
    else
        printf("Perimeter is %.2f times larger than area\n", 1.0/ratio);
}

void rectangleScaling() {
    double length, width, scale;
    
    printf("\nEnter original length: ");
    scanf("%lf", &length);
    printf("Enter original width: ");
    scanf("%lf", &width);
    printf("Enter scale factor: ");
    scanf("%lf", &scale);
    
    double new_l = length * scale;
    double new_w = width * scale;
    double orig_area = length * width;
    double new_area = new_l * new_w;
    
    printf("\n--- Rectangle Scaling ---\n");
    printf("Original: %.2f × %.2f (Area: %.2f)\n", length, width, orig_area);
    printf("Scaled:   %.2f × %.2f (Area: %.2f)\n", new_l, new_w, new_area);
    printf("Area multiplied by: %.2f\n", new_area / orig_area);
}

void multipleRectangles() {
    int n;
    printf("\nEnter number of rectangles: ");
    scanf("%d", &n);
    
    double total_area = 0, total_perimeter = 0;
    
    for(int i = 1; i <= n; i++) {
        double l, w;
        printf("\nRectangle %d - Length: ", i);
        scanf("%lf", &l);
        printf("Rectangle %d - Width: ", i);
        scanf("%lf", &w);
        
        total_area += l * w;
        total_perimeter += 2 * (l + w);
    }
    
    printf("\n--- Multiple Rectangles Summary ---\n");
    printf("Total area: %.2f\n", total_area);
    printf("Total perimeter: %.2f\n", total_perimeter);
    printf("Average area: %.2f\n", total_area / n);
}

void rectangleIntersection() {
    double l1, w1, l2, w2, overlap_l, overlap_w;
    
    printf("\nRectangle 1 dimensions (L×W): ");
    scanf("%lf %lf", &l1, &w1);
    printf("Rectangle 2 dimensions (L×W): ");
    scanf("%lf %lf", &l2, &w2);
    printf("Overlap length: ");
    scanf("%lf", &overlap_l);
    printf("Overlap width: ");
    scanf("%lf", &overlap_w);
    
    double overlap_area = overlap_l * overlap_w;
    double total_area = (l1 * w1) + (l2 * w2) - overlap_area;
    
    printf("\n--- Rectangle Intersection ---\n");
    printf("Rectangle 1 area: %.2f\n", l1 * w1);
    printf("Rectangle 2 area: %.2f\n", l2 * w2);
    printf("Overlap area: %.2f\n", overlap_area);
    printf("Total covered area: %.2f\n", total_area);
}

void circumscribedCircle() {
    double length, width, diagonal, radius, circle_area;
    
    printf("\nEnter length: ");
    scanf("%lf", &length);
    printf("Enter width: ");
    scanf("%lf", &width);
    
    diagonal = sqrt(length * length + width * width);
    radius = diagonal / 2.0;
    circle_area = M_PI * radius * radius;
    
    printf("\n--- Circumscribed Circle ---\n");
    printf("Rectangle diagonal: %.2f\n", diagonal);
    printf("Circle radius: %.2f\n", radius);
    printf("Circle area: %.2f\n", circle_area);
    printf("Rectangle area: %.2f\n", length * width);
}

void inscribedCircle() {
    double length, width, radius, circle_area;
    
    printf("\nEnter length: ");
    scanf("%lf", &length);
    printf("Enter width: ");
    scanf("%lf", &width);
    
    radius = (length < width) ? length / 2.0 : width / 2.0;
    circle_area = M_PI * radius * radius;
    
    printf("\n--- Inscribed Circle ---\n");
    printf("Maximum inscribed circle radius: %.2f\n", radius);
    printf("Circle area: %.2f\n", circle_area);
    printf("Rectangle area: %.2f\n", length * width);
    printf("Unused area: %.2f\n", (length * width) - circle_area);
}

void rectangleTransformation() {
    double length, width;
    
    printf("\nEnter length: ");
    scanf("%lf", &length);
    printf("Enter width: ");
    scanf("%lf", &width);
    
    printf("\n--- Rectangle Transformations ---\n");
    printf("Original: %.2f × %.2f\n", length, width);
    printf("Rotated 90°: %.2f × %.2f\n", width, length);
    printf("Doubled: %.2f × %.2f\n", 2*length, 2*width);
    printf("Halved: %.2f × %.2f\n", length/2, width/2);
    printf("Square (avg): %.2f × %.2f\n", (length+width)/2, (length+width)/2);
}

void costCalculation() {
    double length, width, cost_per_unit;
    
    printf("\nEnter length: ");
    scanf("%lf", &length);
    printf("Enter width: ");
    scanf("%lf", &width);
    printf("Enter cost per unit area: ");
    scanf("%lf", &cost_per_unit);
    
    double area = length * width;
    double perimeter = 2 * (length + width);
    double total_cost = area * cost_per_unit;
    
    printf("\n--- Cost Calculation ---\n");
    printf("Area: %.2f sq units\n", area);
    printf("Cost per unit: $%.2f\n", cost_per_unit);
    printf("Total cost: $%.2f\n", total_cost);
    printf("Cost per perimeter unit: $%.2f\n", total_cost / perimeter);
}

void tileCalculator() {
    double room_l, room_w, tile_l, tile_w;
    
    printf("\nEnter room length: ");
    scanf("%lf", &room_l);
    printf("Enter room width: ");
    scanf("%lf", &room_w);
    printf("Enter tile length: ");
    scanf("%lf", &tile_l);
    printf("Enter tile width: ");
    scanf("%lf", &tile_w);
    
    double room_area = room_l * room_w;
    double tile_area = tile_l * tile_w;
    int tiles_needed = (int)ceil(room_area / tile_area);
    
    printf("\n--- Tile Calculator ---\n");
    printf("Room area: %.2f\n", room_area);
    printf("Tile area: %.2f\n", tile_area);
    printf("Tiles needed: %d\n", tiles_needed);
    printf("Total coverage: %.2f\n", tiles_needed * tile_area);
}

void rectangleProperties() {
    double length, width;
    
    printf("\nEnter length: ");
    scanf("%lf", &length);
    printf("Enter width: ");
    scanf("%lf", &width);
    
    double area = length * width;
    double perimeter = 2 * (length + width);
    double diagonal = sqrt(length * length + width * width);
    double aspect_ratio = length / width;
    
    printf("\n--- Complete Rectangle Properties ---\n");
    printf("Dimensions: %.2f × %.2f\n", length, width);
    printf("Area: %.2f\n", area);
    printf("Perimeter: %.2f\n", perimeter);
    printf("Diagonal: %.2f\n", diagonal);
    printf("Aspect Ratio: %.4f\n", aspect_ratio);
    
    if(length == width)
        printf("Type: Square\n");
    else if(aspect_ratio > 2.0 || aspect_ratio < 0.5)
        printf("Type: Elongated Rectangle\n");
    else
        printf("Type: Standard Rectangle\n");
}

void visualizeRectangle() {
    int length, width;
    
    printf("\nEnter length (5-30): ");
    scanf("%d", &length);
    printf("Enter width (5-30): ");
    scanf("%d", &width);
    
    if(length > 30) length = 30;
    if(width > 30) width = 30;
    
    printf("\n--- Rectangle Visualization ---\n\n");
    
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < length; j++) {
            if(i == 0 || i == width - 1 || j == 0 || j == length - 1)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
    
    printf("\nArea: %d\n", length * width);
    printf("Perimeter: %d\n", 2 * (length + width));
}

/* Version note: updated 2025-11-17 — minor header/metadata bump */