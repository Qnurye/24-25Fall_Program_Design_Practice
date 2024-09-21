#include "views/administrator.h"
#include "utils/display.h"

void handleAdministratorMenu(Student **studentsHead, Teacher **teachersHead) {
    int exit = 0;
    int choice;
    while (!exit) {
        clearScreen();
        printHeader("管理员主页");

        printOption(1, "导入学生信息");
        printOption(2, "导入教师信息");
        printOption(3, "显示当前所有学生信息");
        printOption(4, "显示当前所有教师信息");
        printOption(5, "清空当前所有学生信息");
        printOption(6, "清空当前所有教师信息");
        printOption(7, "退出");

        printPrompt("我想要：");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                importStudents(studentsHead);
                saveStudentsToFile(*studentsHead, "students.txt");
                printColored(GREEN, "已成功添加一名学生\n");
                break;
            case 2:
                importTeachers(teachersHead);
                saveTeachersToFile(*teachersHead, "teachers.txt");
                printColored(GREEN, "已成功添加一名教师\n");
                break;
            case 3:
                displayStudents(*studentsHead);
                break;
            case 4:
                displayTeachers(*teachersHead);
                break;
            case 5:
                freeStudents(studentsHead);
                saveStudentsToFile(*studentsHead, "students.txt");
                break;
            case 6:
                freeTeachers(teachersHead);
                saveTeachersToFile(*teachersHead, "teachers.txt");
                break;
            case 7:
                exit = 1;
                break;
            default:
                break;
        }
    }
}
