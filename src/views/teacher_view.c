//
// Created by qnurye on 24-9-20.
//
#include "views/teacher_view.h"
#include "controllers/grade_controller.h"
#include "models/student.h"
#include "models/grade.h"
#include "utils/display.h"
#include "models/timetable.h"
#include "models/course_schedule.h"
#include <string.h>
#include "controllers/notification_controller.h"
#include "models/classroom.h"

void displayTeacherInfo(Teacher *teacher) {
    clearScreen();
    printHeader("Personal Information");

    printPrompt("ID: ");
    printf("%s", teacher->id);

    printPrompt("Name: ");
    printf("%s", teacher->name);

    printPrompt("Gender: ");
    printf("%s\n", teacher->gender);

    anyKey();
}

void printTeacherRow(void *data, char *row) {
    Teacher *teacher = (Teacher *) data;
    snprintf(row, 100, "%s\t%s\t%s", teacher->id, teacher->name, teacher->gender);
}

void displayTeachers(Teacher *head) {
    clearScreen();
    if (head == NULL) {
        printColored(RED, "No Teachers to display.\n");
    } else {
        const char *header = "ID\tName\tGender";
        const char *separator = "-----------------------------";
        printTable(header, separator, printTeacherRow, head);
    }
    anyKey();
}

void displayImportTeacherPrompt(void) {
    clearScreen();
    printColored(YELLOW, "Please enter teacher information (ID Name Male/Female): \n");
    printColored(BLUE, "(Enter 'back' to return to the main menu)\n");
}

void displayImportTeacherError(int error_code) {
    if (error_code == 0) {
        printColored(RED, "Gender input error, please enter 'Male' or 'Female'.\n");
    } else {
        printColored(RED, "Input error, please try again.\n");
    }
}

void handleUploadGradeView(Student *studentsHead, Grade **gradesHead) {
    char student_id[20];
    char course_name[50];
    int usual_grade;
    int final_grade;
    float usual_grade_proportion;

    while (1) {
        clearScreen();
        printColored(YELLOW, "Upload Grades (Enter 'back' to return to the main menu)\n");

        printPrompt("Please enter student ID: ");
        scanf("%s", student_id);
        if (strcmp(student_id, "back") == 0) {
            return;
        }

        printPromptNoNewLine("Please enter course name: ");
        scanf("%s", course_name);

        printPrompt("Please enter usual grade: ");
        scanf("%d", &usual_grade);

        printPromptNoNewLine("Please enter final grade: ");
        scanf("%d", &final_grade);

        printPromptNoNewLine("Please enter the proportion of usual grade (e.g. 0.4 means 40%): ");
        scanf("%f", &usual_grade_proportion);

        processUploadGrade(studentsHead, gradesHead, student_id, course_name, usual_grade, final_grade,
                           usual_grade_proportion);
        anyKey();
    }
}

void displayTeacherMenu(void) {
    clearScreen();
    printHeader("Teacher Homepage");

    printOption(1, "Query Personal Information");
    printOption(2, "Upload Grades");
    printOption(3, "Publish Notification");
    printOption(4, "Query Course Schedule");
    printOption(5, "View Published Notifications");
    printOption(6, "Exit");

    printPrompt("I want to: ");
}

int getTeacherMenuChoice(void) {
    int choice;
    scanf("%d", &choice);
    return choice;
}

void handlePublishNotification(Teacher *currentTeacher, Notification **notificationsHead) {
    clearScreen();
    printHeader("Publish Notification");

    char title[100];
    char content[500];

    printPrompt("Please enter notification title: ");
    scanf(" %[^\n]", title);

    printPrompt("Please enter notification content: ");
    scanf(" %[^\n]", content);

    publishNotification(notificationsHead, title, content, currentTeacher->name);
}

void
displayCourseScheduleForTeacher(CourseSchedule *schedules, const char *teacher_id, Classroom *classrooms, Teacher *teachers) {
    clearScreen();
    printHeader("Query Course Schedule");

    int resultCount = 0;

    printf("%-10s %-10s %-10s %-10s %-10s %-10s\n", "Course ID", "Day", "Course Name", "Teacher", "Classroom", "Time");
    printf("------------------------------------------------------------\n");

    CourseSchedule *current = schedules;
    while (current != NULL) {

        if (strcmp(current->teacher_id, teacher_id) != 0) {
            current = current->next;
            continue;
        }

        resultCount++;

        const char *dayName;
        switch (current->day_of_week) {
            case Mon:
                dayName = "Monday";
                break;
            case Tue:
                dayName = "Tuesday";
                break;
            case Wed:
                dayName = "Wednesday";
                break;
            case Thu:
                dayName = "Thursday";
                break;
            case Fri:
                dayName = "Friday";
                break;
            case Sat:
                dayName = "Saturday";
                break;
            case Sun:
                dayName = "Sunday";
                break;
            default:
                dayName = "Unknown";
        }

        char timeRange[30];
        snprintf(timeRange, sizeof(timeRange), "%s-%s",
                 TIMETABLE[current->start_lesson_id - 1].start_time,
                 TIMETABLE[current->end_lesson_id - 1].end_time);

        printf("%-10d %-10s %-10s %-10s %-10s %-10s\n",
               current->schedule_id, dayName, current->course_name,
               findTeacherByID(teachers, current->teacher_id)->name,
               findClassroomById(classrooms, current->classroom_id)->name,
               timeRange);

        current = current->next;
    }

    if (resultCount == 0) {
        printColored(RED, "No course to display.\n");
    }
    anyKey();
}
