//
// Created by qnurye on 24-9-20.
//
#include "views/teacher.h"
#include "utils/display.h"

void handleTeacherMenu(Teacher *currentTeacher) {
    int exit = 0;
    int choice;
    while (!exit) {
        clearScreen();
        printHeader("教师主页");

        printOption(1, "查询个人信息");
        printOption(2, "上传成绩");
        printOption(3, "发布通知");
        printOption(4, "课表查询");
        printOption(5, "退出");

        printPrompt("我想要：");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayTeacherInfo(currentTeacher);
                break;
            case 2:
            case 3:
            case 4:
                break;
            case 5:
                exit = 1;
                break;
            default:
                break;
        }
    }
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
        const char *header = "工号\t姓名\t性别";
        const char *separator = "-----------------------------";
        printTable(header, separator, printTeacherRow, head);
    }
    anyKey();
}

void displayImportTeacherPrompt(void) {
    clearScreen();
    printColored(YELLOW, "请输入教师信息（工号 姓名 男/女）：\n");
    printColored(BLUE, "(输入“返回”可返回主菜单）\n");
}

void displayImportTeacherError(int error_code) {
    if (error_code == 0) {
        printColored(RED, "性别输入错误，请输入'男'或'女'。\n");
    } else {
        printColored(RED, "输入错误，请重试。\n");
    }
}

void displayTeacherInfo(Teacher *teacher) {
    clearScreen();
    printHeader("个人信息");

    printf("\n");
    printColored(CYAN, "工号: ");
    printf("%s\n", teacher->id);

    printColored(CYAN, "姓名: ");
    printf("%s\n", teacher->name);

    printColored(CYAN, "性别: ");
    printf("%s\n", teacher->gender);

    anyKey();
}
