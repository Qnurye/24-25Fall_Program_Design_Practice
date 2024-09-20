#include "views/student.h"
#include "utils/display.h"

void Stu_Home(void) {
    clearScreen();
    printHeader("学生主页");

    printOption(1, "查询个人信息");
    printOption(2, "查询成绩");
    printOption(3, "查询通知");
    printOption(4, "退出");

    printPrompt("请选择一个选项（输入对应的数字后按回车键）：");
}

void displayStudents(Student *head) {
    clearScreen();
    Student *current = head;
    if (current == NULL) {
        printColored(RED, "No students to display.\n");
    } else {
        printColored(CYAN, "学号\t姓名\t性别\n");
        printColored(CYAN, "-----------------------------\n");
        while (current != NULL) {
            printf("%s\t%s\t%s\n", current->id, current->name, current->gender);
            current = current->next;
        }
    }
    printPrompt("按 1 返回主菜单：");
}

void displayImportStudentPrompt(void) {
    printf("请输入学生信息（学号 姓名 男/女）：(输入“返回”可返回主菜单）\n");
}

void displayImportStudentSuccess(void) {
    printf("已成功添加一名学生\n");
}

void displayImportStudentError(int error_code) {
    if (error_code == 0) {
        printf("性别输入错误，请输入'男'或'女'。\n");
    } else {
        printf("输入错误，请重试。\n");
    }
}

void displayFreeStudentsSuccess(void) {
    printf("已成功清除所有学生信息\n1.返回\n");
}
