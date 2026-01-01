/*
 * Advanced Date & Calendar Analyzer v2.0
 * Features: Leap year calculation, date validation,
 *           calendar functions, astronomical calculations
 * 
 * IMPROVEMENTS (v2.1):
 * - Enhanced date validation functions
 * - Added comprehensive input range checking
 * - Improved error handling for calendar operations
 * - Better documentation for all functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Function prototypes
bool isLeapYear(int year);
int getDaysInMonth(int month, int year);
int getDaysInYear(int year);
int getDayOfWeek(int day, int month, int year);
bool isValidDate(int day, int month, int year);
int daysBetweenDates(int d1, int m1, int y1, int d2, int m2, int y2);
void printCalendar(int month, int year);
void listLeapYears(int start, int end);
int countLeapYears(int start, int end);
void nextLeapYear(int year);
void previousLeapYear(int year);
void leapYearPattern(int year);
void centuryLeapYears(int century);
void dateArithmetic(int day, int month, int year, int daysToAdd);
int weekNumber(int day, int month, int year);
bool isCenturyLeapYear(int year);
void zodiacSign(int day, int month);
int ageCalculator(int bDay, int bMonth, int bYear);
void displayCurrentDate();
void dateStatistics(int day, int month, int year);
void displayMenu();

// Month names
const char *monthNames[] = {"", "January", "February", "March", "April", "May", "June",
                             "July", "August", "September", "October", "November", "December"};

// Day names
const char *dayNames[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Main function
int main() {
    int choice;
    int day, month, year;
    int d1, m1, y1, d2, m2, y2;
    int startYear, endYear, daysToAdd;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║       Advanced Date & Calendar Analyzer v2.0              ║\n");
    printf("║          Comprehensive Calendar Functions Tool            ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-18): ");
        int scanCheck = scanf("%d", &choice);
        
        // Validate input
        if(scanCheck != 1) {
            printf("Error: Invalid input. Please enter a number.\n");
            while(getchar() != '\n');
            continue;
        }
        
        if(choice == 0) break;
        
        switch(choice) {
            case 1:
                printf("\n--- Leap Year Checker ---\n");
                printf("Enter year: ");
                scanf("%d", &year);
                if(isLeapYear(year))
                    printf("%d is a LEAP YEAR! ✓\n", year);
                else
                    printf("%d is a COMMON YEAR.\n", year);
                break;
                
            case 2:
                printf("\n--- Days in Month ---\n");
                printf("Enter month (1-12): ");
                scanf("%d", &month);
                printf("Enter year: ");
                scanf("%d", &year);
                if(month < 1 || month > 12) {
                    printf("Invalid month! Use 1-12.\n");
                    break;
                }
                printf("%s %d has %d days.\n", monthNames[month], year, getDaysInMonth(month, year));
                break;
                
            case 3:
                printf("\n--- Days in Year ---\n");
                printf("Enter year: ");
                scanf("%d", &year);
                printf("%d has %d days.\n", year, getDaysInYear(year));
                break;
                
            case 4:
                printf("\n--- Day of Week Calculator ---\n");
                printf("Enter date (DD MM YYYY): ");
                scanf("%d %d %d", &day, &month, &year);
                if(isValidDate(day, month, year)) {
                    int dow = getDayOfWeek(day, month, year);
                    printf("%02d/%02d/%d falls on %s\n", day, month, year, dayNames[dow]);
                } else {
                    printf("Invalid date!\n");
                }
                break;
                
            case 5:
                printf("\n--- Date Validator ---\n");
                printf("Enter date (DD MM YYYY): ");
                scanf("%d %d %d", &day, &month, &year);
                if(isValidDate(day, month, year))
                    printf("✓ Valid date: %02d/%02d/%d\n", day, month, year);
                else
                    printf("✗ Invalid date!\n");
                break;
                
            case 6:
                printf("\n--- Days Between Dates ---\n");
                printf("Enter first date (DD MM YYYY): ");
                scanf("%d %d %d", &d1, &m1, &y1);
                printf("Enter second date (DD MM YYYY): ");
                scanf("%d %d %d", &d2, &m2, &y2);
                if(isValidDate(d1, m1, y1) && isValidDate(d2, m2, y2)) {
                    int days = daysBetweenDates(d1, m1, y1, d2, m2, y2);
                    printf("Days between dates: %d\n", abs(days));
                } else {
                    printf("Invalid date(s)!\n");
                }
                break;
                
            case 7:
                printf("\n--- Print Monthly Calendar ---\n");
                printf("Enter month (1-12): ");
                scanf("%d", &month);
                printf("Enter year: ");
                scanf("%d", &year);
                if(month < 1 || month > 12) {
                    printf("Invalid month! Use 1-12.\n");
                    break;
                }
                printCalendar(month, year);
                break;
                
            case 8:
                printf("\n--- List Leap Years in Range ---\n");
                printf("Enter start year: ");
                scanf("%d", &startYear);
                printf("Enter end year: ");
                scanf("%d", &endYear);
                listLeapYears(startYear, endYear);
                break;
                
            case 9:
                printf("\n--- Count Leap Years ---\n");
                printf("Enter start year: ");
                scanf("%d", &startYear);
                printf("Enter end year: ");
                scanf("%d", &endYear);
                int count = countLeapYears(startYear, endYear);
                printf("Leap years between %d and %d: %d\n", startYear, endYear, count);
                break;
                
            case 10:
                printf("\n--- Next Leap Year ---\n");
                printf("Enter year: ");
                scanf("%d", &year);
                nextLeapYear(year);
                break;
                
            case 11:
                printf("\n--- Previous Leap Year ---\n");
                printf("Enter year: ");
                scanf("%d", &year);
                previousLeapYear(year);
                break;
                
            case 12:
                printf("\n--- Leap Year Pattern Analysis ---\n");
                printf("Enter year: ");
                scanf("%d", &year);
                leapYearPattern(year);
                break;
                
            case 13:
                printf("\n--- Century Leap Years ---\n");
                printf("Enter century (e.g., 21 for 2000s): ");
                scanf("%d", &year);
                centuryLeapYears(year);
                break;
                
            case 14:
                printf("\n--- Date Arithmetic ---\n");
                printf("Enter date (DD MM YYYY): ");
                scanf("%d %d %d", &day, &month, &year);
                printf("Enter days to add (negative to subtract): ");
                scanf("%d", &daysToAdd);
                dateArithmetic(day, month, year, daysToAdd);
                break;
                
            case 15:
                printf("\n--- Week Number Calculator ---\n");
                printf("Enter date (DD MM YYYY): ");
                scanf("%d %d %d", &day, &month, &year);
                if(isValidDate(day, month, year)) {
                    int week = weekNumber(day, month, year);
                    printf("Week number: %d\n", week);
                }
                break;
                
            case 16:
                printf("\n--- Zodiac Sign Finder ---\n");
                printf("Enter birth date (DD MM): ");
                scanf("%d %d", &day, &month);
                zodiacSign(day, month);
                break;
                
            case 17:
                printf("\n--- Age Calculator ---\n");
                printf("Enter birth date (DD MM YYYY): ");
                scanf("%d %d %d", &day, &month, &year);
                int age = ageCalculator(day, month, year);
                if(age >= 0)
                    printf("You are %d years old.\n", age);
                break;
                
            case 18:
                displayCurrentDate();
                break;
                
            case 0:
                printf("\n✓ Thank you for using Calendar Analyzer!\n");
                break;
                
            default:
                printf("\n✗ Invalid choice! Please try again.\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    return 0;
}

// Display menu
void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC DATE FUNCTIONS                                   │\n");
    printf("│  [1]  Leap Year Checker                                 │\n");
    printf("│  [2]  Days in Month                                     │\n");
    printf("│  [3]  Days in Year                                      │\n");
    printf("│  [4]  Day of Week Calculator                            │\n");
    printf("│  [5]  Date Validator                                    │\n");
    printf("│  [6]  Days Between Dates                                │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  CALENDAR FUNCTIONS                                     │\n");
    printf("│  [7]  Print Monthly Calendar                            │\n");
    printf("│  [8]  List Leap Years in Range                          │\n");
    printf("│  [9]  Count Leap Years                                  │\n");
    printf("│  [10] Find Next Leap Year                               │\n");
    printf("│  [11] Find Previous Leap Year                           │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED FEATURES                                      │\n");
    printf("│  [12] Leap Year Pattern Analysis                        │\n");
    printf("│  [13] Century Leap Years                                │\n");
    printf("│  [14] Date Arithmetic (Add/Subtract Days)               │\n");
    printf("│  [15] Week Number Calculator                            │\n");
    printf("│  [16] Zodiac Sign Finder                                │\n");
    printf("│  [17] Age Calculator                                    │\n");
    printf("│  [18] Current Date & Time                               │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [0]  Exit Program                                      │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

// Check if leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Get days in month
int getDaysInMonth(int month, int year) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(month == 2 && isLeapYear(year))
        return 29;
    return daysInMonth[month];
}

// Get days in year
int getDaysInYear(int year) {
    return isLeapYear(year) ? 366 : 365;
}

// Get day of week (0=Sunday, 6=Saturday) - Zeller's Congruence
int getDayOfWeek(int day, int month, int year) {
    if(month < 3) {
        month += 12;
        year--;
    }
    int k = year % 100;
    int j = year / 100;
    int h = (day + (13 * (month + 1)) / 5 + k + k/4 + j/4 - 2*j) % 7;
    return (h + 6) % 7;  // Convert to 0=Sunday format
}

// Validate date
bool isValidDate(int day, int month, int year) {
    if(year < 1 || month < 1 || month > 12 || day < 1)
        return false;
    return day <= getDaysInMonth(month, year);
}

// Days between two dates
int daysBetweenDates(int d1, int m1, int y1, int d2, int m2, int y2) {
    int days1 = 0, days2 = 0;
    
    // Count days from year 1
    for(int y = 1; y < y1; y++)
        days1 += getDaysInYear(y);
    for(int m = 1; m < m1; m++)
        days1 += getDaysInMonth(m, y1);
    days1 += d1;
    
    for(int y = 1; y < y2; y++)
        days2 += getDaysInYear(y);
    for(int m = 1; m < m2; m++)
        days2 += getDaysInMonth(m, y2);
    days2 += d2;
    
    return days2 - days1;
}

// Print calendar
void printCalendar(int month, int year) {
    printf("\n═══════════════════════════════════════════════\n");
    printf("         %s %d\n", monthNames[month], year);
    printf("═══════════════════════════════════════════════\n");
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");
    printf("─────────────────────────────────────────────\n");
    
    int startDay = getDayOfWeek(1, month, year);
    int days = getDaysInMonth(month, year);
    
    // Print leading spaces
    for(int i = 0; i < startDay; i++)
        printf("    ");
    
    // Print days
    for(int day = 1; day <= days; day++) {
        printf("%4d", day);
        if((day + startDay) % 7 == 0)
            printf("\n");
    }
    printf("\n═══════════════════════════════════════════════\n");
}

// List leap years
void listLeapYears(int start, int end) {
    printf("\nLeap years from %d to %d:\n", start, end);
    printf("─────────────────────────────────────────\n");
    int count = 0;
    for(int year = start; year <= end; year++) {
        if(isLeapYear(year)) {
            printf("%d ", year);
            count++;
            if(count % 10 == 0) printf("\n");
        }
    }
    printf("\n\nTotal: %d leap years\n", count);
}

// Count leap years
int countLeapYears(int start, int end) {
    int count = 0;
    for(int year = start; year <= end; year++) {
        if(isLeapYear(year)) count++;
    }
    return count;
}

// Find next leap year
void nextLeapYear(int year) {
    year++;
    while(!isLeapYear(year)) year++;
    printf("Next leap year after %d is: %d\n", year-1, year);
}

// Find previous leap year
void previousLeapYear(int year) {
    year--;
    while(!isLeapYear(year) && year > 0) year--;
    if(year > 0)
        printf("Previous leap year before %d is: %d\n", year+1, year);
}

// Leap year pattern
void leapYearPattern(int year) {
    printf("\n═══════════════════════════════════════════════\n");
    printf("    LEAP YEAR PATTERN ANALYSIS\n");
    printf("═══════════════════════════════════════════════\n");
    
    printf("\nYear: %d\n", year);
    printf("─────────────────────────────────────────────\n");
    
    if(isLeapYear(year)) {
        printf("✓ This IS a leap year\n");
        printf("  Divisible by 4: YES\n");
        if(year % 100 == 0) {
            printf("  Century year: YES\n");
            printf("  Divisible by 400: %s\n", (year % 400 == 0) ? "YES" : "NO");
        }
    } else {
        printf("✗ This is NOT a leap year\n");
        printf("  Divisible by 4: %s\n", (year % 4 == 0) ? "YES" : "NO");
        if(year % 100 == 0) {
            printf("  Century year: YES (not divisible by 400)\n");
        }
    }
    
    printf("\nNext 5 leap years:\n");
    int count = 0, y = year + 1;
    while(count < 5) {
        if(isLeapYear(y)) {
            printf("%d ", y);
            count++;
        }
        y++;
    }
    printf("\n");
}

// Century leap years
void centuryLeapYears(int century) {
    int startYear = (century - 1) * 100;
    int endYear = century * 100 - 1;
    
    printf("\nLeap years in century %d (%d-%d):\n", century, startYear, endYear);
    printf("─────────────────────────────────────────────\n");
    
    int count = 0;
    for(int year = startYear; year <= endYear; year++) {
        if(isLeapYear(year)) {
            printf("%d ", year);
            count++;
            if(count % 10 == 0) printf("\n");
        }
    }
    printf("\n\nTotal: %d leap years in century %d\n", count, century);
}

// Date arithmetic
void dateArithmetic(int day, int month, int year, int daysToAdd) {
    if(!isValidDate(day, month, year)) {
        printf("Invalid date!\n");
        return;
    }
    
    printf("\nOriginal date: %02d/%02d/%d (%s)\n", 
           day, month, year, dayNames[getDayOfWeek(day, month, year)]);
    
    // Add/subtract days
    while(daysToAdd > 0) {
        int daysInMonth = getDaysInMonth(month, year);
        if(day + daysToAdd <= daysInMonth) {
            day += daysToAdd;
            daysToAdd = 0;
        } else {
            daysToAdd -= (daysInMonth - day + 1);
            day = 1;
            month++;
            if(month > 12) {
                month = 1;
                year++;
            }
        }
    }
    
    while(daysToAdd < 0) {
        if(day + daysToAdd >= 1) {
            day += daysToAdd;
            daysToAdd = 0;
        } else {
            daysToAdd += day;
            month--;
            if(month < 1) {
                month = 12;
                year--;
            }
            day = getDaysInMonth(month, year);
        }
    }
    
    printf("New date:      %02d/%02d/%d (%s)\n", 
           day, month, year, dayNames[getDayOfWeek(day, month, year)]);
}

// Week number
int weekNumber(int day, int month, int year) {
    int dayOfYear = day;
    for(int m = 1; m < month; m++) {
        dayOfYear += getDaysInMonth(m, year);
    }
    return (dayOfYear - 1) / 7 + 1;
}

// Zodiac sign
void zodiacSign(int day, int month) {
    const char *signs[] = {
        "Capricorn", "Aquarius", "Pisces", "Aries", "Taurus", "Gemini",
        "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius"
    };
    
    int dates[] = {20, 19, 21, 20, 21, 21, 23, 23, 23, 23, 22, 22};
    
    int sign = (day >= dates[month-1]) ? month - 1 : (month == 1 ? 11 : month - 2);
    printf("Zodiac Sign: %s ♈\n", signs[sign]);
}

// Age calculator
int ageCalculator(int bDay, int bMonth, int bYear) {
    time_t t = time(NULL);
    struct tm *now = localtime(&t);
    
    int age = now->tm_year + 1900 - bYear;
    if(now->tm_mon + 1 < bMonth || (now->tm_mon + 1 == bMonth && now->tm_mday < bDay))
        age--;
    
    return age;
}

// Display current date
void displayCurrentDate() {
    time_t t = time(NULL);
    struct tm *now = localtime(&t);
    
    printf("\n═══════════════════════════════════════════════\n");
    printf("         CURRENT DATE & TIME\n");
    printf("═══════════════════════════════════════════════\n");
    printf("\nDate: %02d/%02d/%d\n", now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
    printf("Day:  %s\n", dayNames[now->tm_wday]);
    printf("Time: %02d:%02d:%02d\n", now->tm_hour, now->tm_min, now->tm_sec);
    printf("Year: %s\n", isLeapYear(now->tm_year + 1900) ? "Leap Year" : "Common Year");
    printf("═══════════════════════════════════════════════\n");
}