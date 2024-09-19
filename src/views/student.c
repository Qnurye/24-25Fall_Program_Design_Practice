#include <stdio.h>
#include "models/student.h"

void Stu_Home(void) {
    printf("\n");
    printf("********************************************\n");
    printf("***               学生主页               ***\n");
    printf("********************************************\n");
    printf("\n");

    printf("    1. 查询个人信息\n");
    printf("    2. 查询成绩\n");
    printf("    3. 查询通知\n");
    printf("    4. 退出\n");

    printf("\n");
    printf("请选择一个选项（输入对应的数字后按回车键）：");
}

void displayStudents(Student *head) {
    Student *current = head;
    if (current == NULL) {
        printf("No students to display.\n");
    }

    while (current != NULL) {
        printf("学号: %s, 姓名: %s,性别: %s\n",
               current->id, current->name, current->gender);

        current = current->next;
    }
    printf("1.返回\n");
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
