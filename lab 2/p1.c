#include <stdio.h>
#include <string.h>

#define MAX_REMINDERS 100

// Arrays to hold month names and the number of days in each month
char *months[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Function to check for leap year
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    }
    return 0;
}

// Function to determine the day of the week for the first day of the month
int getFirstDayOfMonth(int year, int month) {
    int day = 1; // 1st day of the month
    int y = year - (14 - month) / 12;
    int x = y + y/4 - y/100 + y/400;
    int m = month + 12 * ((14 - month) / 12) - 2;
    return (day + x + (31*m)/12) % 7;
}

// Function to print the calendar layout
void printCalendar(int year, int month) {
    int days = daysInMonth[month - 1];

    // Adjust for leap year if February
    if (month == 2 && isLeapYear(year)) {
        days = 29;
    }

    int firstDay = getFirstDayOfMonth(year, month);

    printf("\n  %s %d\n", months[month - 1], year);
    printf("  Su  Mo  Tu  We  Th  Fr  Sa\n");

    // Print leading spaces for the first day
    for (int i = 0; i < firstDay; i++) {
        printf("    ");
    }

    // Print the days of the month
    for (int day = 1; day <= days; day++) {
        printf("%4d", day);

        // Move to the next line after Saturday
        if ((day + firstDay) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

// Structure for reminders
struct Reminder {
    int day;
    int month;
    int year;
    char description[100];
};

struct Reminder reminders[MAX_REMINDERS];
int reminderCount = 0;

// Function to set a reminder
void setReminder(int day, int month, int year, char *description) {
    if (reminderCount < MAX_REMINDERS) {
        reminders[reminderCount].day = day;
        reminders[reminderCount].month = month;
        reminders[reminderCount].year = year;
        strcpy(reminders[reminderCount].description, description);
        reminderCount++;
        printf("Reminder set for %d-%d-%d: %s\n", day, month, year, description);
    } else {
        printf("Cannot set more reminders, storage is full.\n");
    }
}

// Function to print all reminders for a specific day
void printReminders(int day, int month, int year) {
    printf("\nReminders for %d-%d-%d:\n", day, month, year);
    int found = 0;
    for (int i = 0; i < reminderCount; i++) {
        if (reminders[i].day == day && reminders[i].month == month && reminders[i].year == year) {
            printf("  - %s\n", reminders[i].description);
            found = 1;
        }
    }
    if (!found) {
        printf("  No reminders found for this day.\n");
    }
}

// Main function
int main() {
    int year, month, day;
    char description[100];

    printf("Enter the year: ");
    scanf("%d", &year);
    printf("Enter the month (1-12): ");
    scanf("%d", &month);

    // Print the calendar
    printCalendar(year, month);

    // Set a reminder
    printf("Enter a day to set a reminder: ");
    scanf("%d", &day);
    printf("Enter reminder description: ");
    scanf(" %[^\n]", description); // Read string with spaces
    setReminder(day, month, year, description);

    // Print reminders for the given day
    printReminders(day, month, year);

    return 0;
}
