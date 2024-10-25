#include "models/course_schedule_selection.h"
#include "controllers/notification_controller.h"
#include "views/student_view.h"
#include "utils/display.h"
#include "controllers/grade_controller.h"
#include <string.h>
#include <stdlib.h>
#include "models/classroom.h"
#include "models/timetable.h"

void displayStudentMenu(void) {

    clearScreen();
    printHeader("Student Homepage");

    printOption(1, "Query Personal Information");
    printOption(2, "Query Grades");
    printOption(3, "Query Notifications");
    printOption(4, "Query Course Schedule");
    printOption(5, "Query Empty Classrooms");
    printOption(6, "Select Courses");
    printOption(7, "Change Password");
    printOption(8, "Exit");

    printPrompt("I want to: ");
}

void printStudentRow(void *data, char *row) {
    Student *student = (Student *) data;
    snprintf(row, 100, "%s\t%s\t%s", student->id, student->name, student->gender);
}

void displayStudents(Student *head) {
    clearScreen();
    if (head == NULL) {
        printColored(RED, "No students to display.\n");
    } else {
        const char *header = "ID\tName\tGender";
        const char *separator = "-----------------------------";
        printTable(header, separator, printStudentRow, head);
    }
    anyKey();
}

void displayImportStudentPrompt(void) {
    printf("Please enter student information (ID Name Male/Female): (Enter 'back' to return to the main menu)\n");
}

void displayImportStudentError(int error_code) {
    if (error_code == 0) {
        printf("Gender input error, please enter 'Male' or 'Female'.\n");
    } else {
        printf("Input error, please try again.\n");
    }
}

void displayStudentInfo(Student *student) {
    clearScreen();
    printHeader("Personal Information");

    printPrompt("ID: ");
    printf("%s", student->id);

    printPrompt("Name: ");
    printf("%s\n", student->name);

    anyKey();
}

void printGradeRow(void *data, char *row) {
    Grade *grade = (Grade *) data;
    snprintf(row, 100, "%s\t%d\t%d\t%.2f", grade->course_name, grade->usual_grade, grade->final_grade,
             grade->usual_grade_proportion);
}

void displayGrades(Grade *grades) {
    clearScreen();
    printHeader("Query Grades");

    if (grades == NULL) {
        printColored(RED, "No grades to display.\n");
    } else {
        const char *header = "Course Name\tUsual Grade\tFinal Grade\tUsual Grade Proportion";
        const char *separator = "--------------------------------------------";
        printTable(header, separator, printGradeRow, grades);
    }

    anyKey();
}

// 辅助函数：反转通知链表以实现从新到旧的显示顺序
static Notification *reverseNotifications(Notification *head) {
    Notification *prev = NULL;
    Notification *current = head;
    while (current != NULL) {
        Notification *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void displayStudentNotifications(Notification *notificationsHead) {
    Notification *reversedHead = reverseNotifications(notificationsHead);
    if (reversedHead == NULL) {
        printColored(RED, "No notifications to display.\n");
        anyKey();
        return;
    }

    // 计算通知数量
    int count = 0;
    Notification *temp = reversedHead;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // 将通知存储到数组中以便索引访问
    Notification **notificationsArray = (Notification **) malloc(count * sizeof(Notification *));
    if (notificationsArray == NULL) {
        printColored(RED, "Memory allocation failed.\n");
        anyKey();
        return;
    }

    temp = reversedHead;
    for (int i = 0; i < count; i++) {
        notificationsArray[i] = temp;
        temp = temp->next;
    }

    // 显示通知列表
    clearScreen();
    printHeader("Notification List");

    for (int i = 0; i < count; i++) {
        char content[400];
        snprintf((char *) &content, 400, "%s (Published on %s)\n", notificationsArray[i]->title,
                 notificationsArray[i]->date);
        printOption(i + 1, content);
    }

    printf("\n");
    printPromptNoNewLine("Please enter the number of the notification you want to view (or enter 0 to return): ");
    int choice;
    scanf("%d", &choice);

    if (choice == 0) {
        free(notificationsArray);
        return;
    }

    if (choice < 1 || choice > count) {
        printColored(RED, "Invalid number, please try again.\n");
        anyKey();
        free(notificationsArray);
        return;
    }

    // 显示选中的通知详情
    Notification *selected = notificationsArray[choice - 1];
    clearScreen();
    printHeader(selected->title);
    printPrompt("Published by: ");
    printf("%s", selected->teacher_name);
    printPrompt("Date: ");
    printf("%s\n\n", selected->date);
    printPrompt(selected->content);
    printf("\n\n");
    anyKey();

    free(notificationsArray);
}

void displayCourseScheduleForStudents(CourseSchedule *schedules, const char *student_id, Classroom *classrooms,
                                      CourseScheduleSelection *courseSelectionsHead, Teacher *teachers) {
//    TODO)) 先选课，后查表

    clearScreen();
    printHeader("Query Course Schedule");

    int resultCount = 0;

    printf("%-10s %-10s %-10s %-10s %-10s %-10s\n", "Course ID", "Day", "Course Name", "Teacher", "Classroom", "Time");
    printf("------------------------------------------------------------\n");

    CourseSchedule *current = schedules;
    while (current != NULL) {

        if (student_id && !hasSelectedCourse(courseSelectionsHead, student_id, current->schedule_id)) {
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
        printColored(RED, "No courses to display.\n");
    }
    anyKey();
}

void handleCourseSelection(Student *currentStudent, CourseSchedule *courseSchedulesHead,
                           CourseScheduleSelection **courseSelectionsHead, Classroom *classroomsHead,
                           Teacher *teachers) {

    displayCourseScheduleForStudents(courseSchedulesHead, NULL, classroomsHead, *courseSelectionsHead, teachers);

    int scheduleId;
    printf("Please enter the schedule ID of the course you want to select (or enter 0 to cancel): ");
    scanf("%d", &scheduleId);

    if (scheduleId == 0) {
        return;
    }

    CourseSchedule *selectedCourse = findCourseScheduleById(courseSchedulesHead, scheduleId);
    if (selectedCourse == NULL) {
        printf("Invalid schedule ID, please try again.\n");
        anyKey();
        return;
    }

    if (hasSelectedCourse(*courseSelectionsHead, currentStudent->id, scheduleId)) {
        printf("You have already selected this course.\n");
        anyKey();
        return;
    }

    addCourseSelection(courseSelectionsHead, scheduleId, currentStudent->id);
    printf("Course selection successful.\n");
    anyKey();
}
