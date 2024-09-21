#include "views/student_view.h"
#include "utils/display.h"
#include "controllers/grade_controller.h"
#include <string.h>

void displayStudentHomepage(Student *currentStudent, Grade *gradesHead) {
    int exit = 0;
    int choice;
    while (!exit) {
        clearScreen();
        printHeader("学生主页");

        printOption(1, "查询个人信息");
        printOption(2, "查询成绩");
        printOption(3, "查询通知");
        printOption(4, "课表查询");
        printOption(5, "空教室查询");
        printOption(6, "退出");

        printPrompt("我想要：");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayStudentInfo(currentStudent);
                break;
            case 2:
                displayStudentGrades(currentStudent->id, gradesHead);
                break;
            case 3:
                // 实现查询通知
                break;
            case 4:
                // 实现课表查询
                break;
            case 5:
                // 实现空教室查询
                break;
            case 6:
                exit = 1;
                break;
            default:
                printColored(RED, "无效的选项，请重试。\n");
                anyKey();
                break;
        }
    }
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
        const char *header = "学号\t姓名\t性别";
        const char *separator = "-----------------------------";
        printTable(header, separator, printStudentRow, head);
    }
    anyKey();
}

void displayImportStudentPrompt(void) {
    printf("请输入学生信息（学号 姓名 男/女）：(输入“返回”可返回主菜单）\n");
}

void displayImportStudentError(int error_code) {
    if (error_code == 0) {
        printf("性别输入错误，请输入'男'或'女'。\n");
    } else {
        printf("输入错误，请重试。\n");
    }
}

void displayStudentInfo(Student *student) {
    clearScreen();
    printHeader("个人信息");

    printPrompt("学号: ");
    printf("%s", student->id);

    printPrompt("姓名: ");
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
    printHeader("成绩查询");

    if (grades == NULL) {
        printColored(RED, "没有成绩记录。\n");
    } else {
        const char *header = "课程名称\t平时分\t期末分\t平时分占比";
        const char *separator = "--------------------------------------------";
        printTable(header, separator, printGradeRow, grades);
    }

    anyKey();
}
