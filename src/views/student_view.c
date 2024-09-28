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
    printHeader("学生主页");

    printOption(1, "查询个人信息");
    printOption(2, "查询成绩");
    printOption(3, "查询通知");
    printOption(4, "课表查询");
    printOption(5, "空教室查询");
    printOption(6, "选课");
    printOption(7, "退出");

    printPrompt("我想要：");
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
        printColored(RED, "没有通知可显示。\n");
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
        printColored(RED, "内存分配失败。\n");
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
    printHeader("通知列表");

    for (int i = 0; i < count; i++) {
        char content[400];
        snprintf((char *) &content, 400, "%s (发布于 %s)\n", notificationsArray[i]->title,
                 notificationsArray[i]->date);
        printOption(i + 1, content);
    }

    printf("\n");
    printPromptNoNewLine("请输入要查看的通知编号（或输入0返回）：");
    int choice;
    scanf("%d", &choice);

    if (choice == 0) {
        free(notificationsArray);
        return;
    }

    if (choice < 1 || choice > count) {
        printColored(RED, "无效的编号，请重试。\n");
        anyKey();
        free(notificationsArray);
        return;
    }

    // 显示选中的通知详情
    Notification *selected = notificationsArray[choice - 1];
    clearScreen();
    printHeader(selected->title);
    printPrompt("发布教师: ");
    printf("%s", selected->teacher_name);
    printPrompt("日期: ");
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
    printHeader("课表查询");

    int resultCount = 0;

    printf("%-10s %-10s %-10s %-10s %-10s %-10s\n", "课程ID", "星期", "课程名称", "教师", "教室", "时间");
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
                dayName = "星期一";
                break;
            case Tue:
                dayName = "星期二";
                break;
            case Wed:
                dayName = "星期三";
                break;
            case Thu:
                dayName = "星期四";
                break;
            case Fri:
                dayName = "星期五";
                break;
            case Sat:
                dayName = "星期六";
                break;
            case Sun:
                dayName = "星期日";
                break;
            default:
                dayName = "未知";
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
        printColored(RED, "没有课程可显示。\n");
    }
    anyKey();
}

void handleCourseSelection(Student *currentStudent, CourseSchedule *courseSchedulesHead,
                           CourseScheduleSelection **courseSelectionsHead, Classroom *classroomsHead,
                           Teacher *teachers) {

    displayCourseScheduleForStudents(courseSchedulesHead, NULL, classroomsHead, *courseSelectionsHead, teachers);

    int scheduleId;
    printf("请输入要选的课程的课表ID（或输入0取消）：");
    scanf("%d", &scheduleId);

    if (scheduleId == 0) {
        return;
    }

    CourseSchedule *selectedCourse = findCourseScheduleById(courseSchedulesHead, scheduleId);
    if (selectedCourse == NULL) {
        printf("无效的课表ID，请重试。\n");
        anyKey();
        return;
    }

    if (hasSelectedCourse(*courseSelectionsHead, currentStudent->id, scheduleId)) {
        printf("你已经选了这门课。\n");
        anyKey();
        return;
    }

    addCourseSelection(courseSelectionsHead, scheduleId, currentStudent->id);
    printf("选课成功。\n");
    anyKey();
}
