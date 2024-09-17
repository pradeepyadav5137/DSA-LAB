#include <stdio.h>

// Function to determine if a year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to determine the number of days in a given month
int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}

// Function to calculate the day of the week for the 1st day of the month
int getStartDayOfMonth(int month, int year) {
    int day = 1;
    int y = year - (14 - month) / 12;
    int m = month + 12 * ((14 - month) / 12) - 2;
    int d = (day + y + y/4 - y/100 + y/400 + (31*m)/12) % 7;
    return d;
}

// Function to print the calendar for a given month and year
void printCalendar(int month, int year) {
    char *months[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};
    
    int daysInMonth = getDaysInMonth(month, year);
    int startDay = getStartDayOfMonth(month, year);

    // Print the header
    printf("\n  %s %d\n", months[month-1], year);
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    // Print initial spaces
    for (int i = 0; i < startDay; i++) {
        printf("     ");
    }

    // Print days of the month
    for (int day = 1; day <= daysInMonth; day++) {
        printf("%5d", day);
        
        if ((day + startDay) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    int month, year;

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    printf("Enter year: ");
    scanf("%d", &year);

    printCalendar(month, year);

    return 0;
}

