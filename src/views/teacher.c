//
// Created by qnurye on 24-9-20.
//
#include <stdio.h>
#include "models/teacher.h"

void Tea_Home(void) {
    printf("\n");
    printf("********************************************\n");
    printf("***               教师主页               ***\n");
    printf("********************************************\n");
    printf("\n");

    printf("    1. 查询信息\n");
    printf("    2. 上传成绩\n");
    printf("    3. 发布通知\n");
    printf("    4. 退出\n");

    printf("\n");
    printf("请选择一个选项（输入对应的数字后按回车键）：");
}

void displayTeachers(Teacher *head) {
    Teacher *current = head;
    if (current == NULL) {
        printf("No Teachers to display.\n");
    }

    while (current != NULL) {
        printf("工号: %s, 姓名: %s,性别: %s\n",
               current->id, current->name, current->gender);

        current = current->next;
    }
    printf("1.返回\n");
}

void displayImportTeacherPrompt() {
    printf("请输入教师信息（工号 姓名 男/女）：(输入“返回”可返回主菜单）\n");
}

void displayImportTeacherSuccess() {
    printf("已成功添加一名教师\n");
}

void displayImportTeacherError(int error_code) {
    if (error_code == 0) {
        printf("性别输入错误，请输入'男'或'女'。\n");
    } else {
        printf("输入错误，请重试。\n");
    }
}

void displayFreeTeachersSuccess() {
    printf("已成功清除所有教师信息\n1.返回\n");
}
