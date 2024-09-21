//
// Created by qnurye on 24-9-20.
//
#include "views/teacher_view.h"
#include "controllers/grade_controller.h"
#include "models/student.h"
#include "models/grade.h"
#include "utils/display.h"
#include <string.h>
#include "controllers/notification_controller.h"

void displayTeacherInfo(Teacher *teacher) {
    clearScreen();
    printHeader("个人信息");

    printPrompt("工号: ");
    printf("%s", teacher->id);

    printPrompt("姓名: ");
    printf("%s", teacher->name);

    printPrompt("性别: ");
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
        const char *header = "工号\t姓名\t性别";
        const char *separator = "-----------------------------";
        printTable(header, separator, printTeacherRow, head);
    }
    anyKey();
}

void displayImportTeacherPrompt(void) {
    clearScreen();
    printColored(YELLOW, "请输入教师信息（工号 姓名 男/女）：\n");
    printColored(BLUE, "(输入'返回'可返回主菜单）\n");
}

void displayImportTeacherError(int error_code) {
    if (error_code == 0) {
        printColored(RED, "性别输入错误，请输入'男'或'女'。\n");
    } else {
        printColored(RED, "输入错误，请重试。\n");
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
        printColored(YELLOW, "上传成绩（输入 '返回' 以返回主菜单）\n");

        printPrompt("请输入学生学号：");
        scanf("%s", student_id);
        if (strcmp(student_id, "返回") == 0) {
            return;
        }

        printPromptNoNewLine("请输入课程名称：");
        scanf("%s", course_name);

        printPrompt("请输入平时分：");
        scanf("%d", &usual_grade);

        printPromptNoNewLine("请输入期末分：");
        scanf("%d", &final_grade);

        printPromptNoNewLine("请输入平时分占比（例如 0.4 表示40%）：");
        scanf("%f", &usual_grade_proportion);

        processUploadGrade(studentsHead, gradesHead, student_id, course_name, usual_grade, final_grade,
                           usual_grade_proportion);
        anyKey();
    }
}

void displayTeacherMenu(void) {
    clearScreen();
    printHeader("教师主页");

    printOption(1, "查询个人信息");
    printOption(2, "上传成绩");
    printOption(3, "发布通知");
    printOption(4, "课表查询");
    printOption(5, "查看发布的通知");
    printOption(6, "退出");

    printPrompt("我想要：");
}

int getTeacherMenuChoice(void) {
    int choice;
    scanf("%d", &choice);
    return choice;
}

void handlePublishNotification(Teacher *currentTeacher, Notification **notificationsHead) {
    clearScreen();
    printHeader("发布通知");

    char title[100];
    char content[500];

    printPrompt("请输入通知标题：");
    scanf(" %[^\n]", title);

    printPrompt("请输入通知内容：");
    scanf(" %[^\n]", content);

    publishNotification(notificationsHead, title, content, currentTeacher->name);
}
