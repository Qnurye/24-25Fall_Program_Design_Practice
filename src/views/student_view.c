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
    printOption(4, "查询课程表");
    printOption(5, "查询空教室");
    printOption(6, "选课");
    printOption(7, "退选课程");
    printOption(8, "修改密码");
    printOption(9, "退出");

    printPrompt("我想要:");
}

void printStudentRow(void *data, char *row) {
    Student *student = (Student *) data;
    snprintf(row, 100, "%s\t%s\t%s", student->id, student->name, student->gender);
}

void displayStudents(Student *head) {
    clearScreen();
    if (head == NULL) {
        printColored(RED, "没有学生信息可显示。\n");
    } else {
        const char *header = "ID\t姓名\t性别";
        const char *separator = "-----------------------------";
        printTable(header, separator, printStudentRow, head);
    }
    anyKey();
}

void displayImportStudentPrompt(void) {
    printf("请输入学生信息 (ID 姓名 男/女): (输入 'back' 返回主菜单)\n");
}

void displayImportStudentError(int error_code) {
    if (error_code == 0) {
        printf("性别输入错误，请输入 '男' 或 '女'。\n");
    } else {
        printf("输入错误，请重试。\n");
    }
}

void displayStudentInfo(Student *student) {
    clearScreen();
    printHeader("个人信息");

    printPrompt("ID: ");
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
    printHeader("查询成绩");

    if (grades == NULL) {
        printColored(RED, "没有成绩可显示。\n");
    } else {
        const char *header = "课程名称\t平时成绩\t期末成绩\t平时成绩占比";
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
    printPromptNoNewLine("请输入要查看的通知编号 (或输入 0 返回): ");
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
    printPrompt("发布者: ");
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
    clearScreen();
    printHeader("查询课程表");

    int resultCount = 0;

    char border[] = "--------------------------------------------------------------------------";
    centerColorPrint(border, CYAN, "%-3s %-10s %-27s %-8s %-10s %-10s\n", "ID", "星期", "课程名称", "教师",
                     "教室", "时间");
    centerColorPrint(border, MAGENTA, "%s\n", border);

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

        centerPrint(border, "%-3d %-10s %-27s %-8s %-10s %-10s\n",
                    current->schedule_id, dayName, current->course_name,
                    findTeacherByID(teachers, current->teacher_id)->name,
                    findClassroomById(classrooms, current->classroom_id)->name,
                    timeRange);
        current = current->next;
    }
    if (resultCount == 0) {
        centerColorPrint(border, RED, "没有课程可显示。\n");
    }
}

void handleCourseSelection(Student *currentStudent, CourseSchedule *courseSchedulesHead,
                           CourseScheduleSelection **courseSelectionsHead, Classroom *classroomsHead,
                           Teacher *teachers) {

    displayCourseScheduleForStudents(courseSchedulesHead, NULL, classroomsHead, *courseSelectionsHead, teachers);

    char border[] = "--------------------------------------------------------------------------";

    int scheduleId;
    printPrompt("课程ID:");
    char buffer[10];
    getInput(buffer, 10);
    scheduleId = (int) strtol(buffer, NULL, 10);

    if (scheduleId == 0) {
        return;
    }

    CourseSchedule *selectedCourse = findCourseScheduleById(courseSchedulesHead, scheduleId);
    if (selectedCourse == NULL) {
        centerColorPrint(border, RED, "无效的课程ID，请重试。\n");
        anyKey();
        return;
    }

    if (hasSelectedCourse(*courseSelectionsHead, currentStudent->id, scheduleId)) {
        centerColorPrint(border, RED, "您已选择过该课程。\n");
        anyKey();
        return;
    }

    if (!checkSelectable(*courseSelectionsHead, selectedCourse, courseSchedulesHead)) {
        centerColorPrint(border, RED, "您选择的课程与当前课程表冲突。\n");
        anyKey();
        return;
    }

    addCourseSelection(courseSelectionsHead, scheduleId, currentStudent->id);
    centerColorPrint(border, GREEN, "选课成功。\n");
    anyKey();
}

void handleCourseUnselecting(Student *currentStudent, CourseSchedule *courseSchedulesHead,
                             CourseScheduleSelection **courseSelectionsHead, Classroom *classroomsHead,
                             Teacher *teachers) {

    displayCourseScheduleForStudents(courseSchedulesHead, currentStudent->id, classroomsHead,
                                     *courseSelectionsHead, teachers);

    char border[] = "--------------------------------------------------------------------------";

    int scheduleId;
    printPrompt("课程ID:");
    char buffer[10];
    getInput(buffer, 10);
    scheduleId = (int) strtol(buffer, NULL, 10);

    if (scheduleId == 0) {
        return;
    }

    CourseSchedule *selectedCourse = findCourseScheduleById(courseSchedulesHead, scheduleId);
    if (selectedCourse == NULL) {
        centerColorPrint(border, RED, "无效的课程ID，请重试。\n");
        anyKey();
        return;
    }

    if (!hasSelectedCourse(*courseSelectionsHead, currentStudent->id, scheduleId)) {
        centerColorPrint(border, RED, "您未选择该课程。\n");
        anyKey();
        return;
    }

    removeCourseSelection(courseSelectionsHead, scheduleId, currentStudent->id);
    centerColorPrint(border, GREEN, "退课成功。\n");
    anyKey();
}

void printAvailableWeekDays(void) {
    clearScreen();
    printHeader("学生主页");
    printOption(1, "星期一");
    printOption(2, "星期二");
    printOption(3, "星期三");
    printOption(4, "星期四");
    printOption(5, "星期五");
    printOption(6, "星期六");
    printOption(7, "星期日");

    printPrompt("查看:");
}

void printEmptyRoomsSubmenu(void) {
    clearScreen();
    printHeader("学生主页");

    printOption(1, "按星期查询");
    printOption(2, "按教室名称查询");

    printPrompt("我想要:");
}
