#include "views/classroom_view.h"

const char *DAY_NAMES[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

void displayClassroomWeeklyAvailability(const char *classroomName, ClassroomAvailableTimeList availableTimes) {
    clearScreen();
    printHeader("Weekly Availability for Classroom");
    char border[] = "----------------------------------------------------";

    ClassroomAvailableTime *classroomTime = NULL;
    for (int i = 0; i < availableTimes.count; i++) {
        if (strcmp(availableTimes.availableTimes[i].classroom->name, classroomName) == 0) {
            classroomTime = &availableTimes.availableTimes[i];
            break;
        }
    }

    if (!classroomTime) {
        printColored(RED, "Classroom %s not found.\n", classroomName);
        anyKey();
        return;
    }

    // Print the header with day names
    centerColorPrint(border, CYAN, "%-6s %-13s", "Lesson", "Time");  // Extended width for "Time" column
    for (int day = 0; day < 7; day++) {
        printColored(CYAN, "%-5s", DAY_NAMES[day]); // Each day column is 10 characters wide
    }
    printf("\n");
    centerColorPrint(border, MAGENTA, "%s\n", border);

    // Loop through each period to display the time and availability across the week
    for (int period = 0; period < MAX_PERIODS; period++) {
        // Print the lesson number and extended time range column with fixed width
        centerPrint(border, "%-6d %-5s-%-7s", period + 1, TIMETABLE[period].start_time, TIMETABLE[period].end_time);

        // Print availability for each day of the week with fixed width
        for (int day = 0; day < 7; day++) {
            if (classroomTime->availableLessons.lessons[day][period] == 1) {
                printColored(GREEN, "%-5s", " V");  // Available indicator with fixed width
            } else {
                printColored(RED, "%-5s", " X");   // Unavailable indicator with fixed width
            }
        }
        printf("\n");
    }
}


void displayAvailableClassroomsByPeriod(DayOfWeek day, ClassroomAvailableTimeList availableTimes) {
    clearScreen();
    printHeader(DAY_NAMES[day]);

    char border[] = "----------------------------------------------";

    centerColorPrint(border, CYAN, "%-15s %-15s\n", "Time Block", "Classrooms");
    centerColorPrint(border, MAGENTA, "%s\n", border);

    int resultCount = 0;

    // Loop through each period for the selected day
    for (int period = 0; period < MAX_PERIODS; period++) {
        int periodAvailableCount = 0;
        centerPrint(border, "%-5s - %-9s", TIMETABLE[period].start_time, TIMETABLE[period].end_time);

        // Loop through each classroom to check if it's available for this period
        for (int i = 0; i < availableTimes.count; i++) {
            ClassroomAvailableTime *classroomTime = &availableTimes.availableTimes[i];
            Classroom *classroom = classroomTime->classroom;

            // Check if the classroom is available (marked by 1) for this period
            if (classroomTime->availableLessons.lessons[day][period] == 1) {
                // Print the classroom name in green to indicate availability
                if (periodAvailableCount > 0) {
                    printf(", ");  // Separate multiple classrooms with commas
                }
                printColored(GREEN, "%s", classroom->name);
                periodAvailableCount++;
            }
        }

        if (periodAvailableCount == 0) {
            // If no classrooms are available for this period, display a message
            printColored(RED, "No classrooms available");
        }

        printf("\n");
        resultCount += periodAvailableCount;
    }

    if (resultCount == 0) {
        printColored(RED, "No available classrooms for the selected day.\n");
    }
}

#include <stdio.h>

void displayClassrooms(Classroom *head) {
    clearScreen();
    printHeader("All Classrooms");
    Classroom *current = head;

    while (current != NULL) {
        printOption(current->id, current->name);
        current = current->next;
    }
    printPrompt("Check:");
}
