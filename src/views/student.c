#include <unistd.h>
#include "views/student.h"
#include "utils/display.h"
#include <sys/ioctl.h>
#include <string.h>

void displayStudentHomepage(void) {
    int exit = 0;
    int choice;
    while (!exit) {
        clearScreen();
        printHeader("学生主页");

        printOption(1, "查询个人信息");
        printOption(2, "查询成绩");
        printOption(3, "查询通知");
        printOption(4, "退出");

        printPrompt("我想要：");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            case 2:
            case 3:
                break;
            case 4:
                exit = 1;
                break;
            default:
                break;
        }
    }
}

void printStudentRow(void *data, char *row) {
    Student *student = (Student *)data;
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
