#include "views/classroom_view.h"

const char *DAY_NAMES[] = {"周一", "周二", "周三", "周四", "周五", "周六", "周日"};

void displayClassroomWeeklyAvailability(const char *classroomName, ClassroomAvailableTimeList availableTimes) {
    clearScreen();
    printHeader("教室每周可用情况");
    char border[] = "----------------------------------------------------";

    ClassroomAvailableTime *classroomTime = NULL;
    for (int i = 0; i < availableTimes.count; i++) {
        if (strcmp(availableTimes.availableTimes[i].classroom->name, classroomName) == 0) {
            classroomTime = &availableTimes.availableTimes[i];
            break;
        }
    }

    if (!classroomTime) {
        printColored(RED, "未找到教室 %s。\n", classroomName);
        anyKey();
        return;
    }

    // 打印包含星期几的标题
    centerColorPrint(border, CYAN, "%-6s %-13s", "课程", "时间");  // 为“时间”列扩展宽度
    for (int day = 0; day < 7; day++) {
        printColored(CYAN, "%-5s", DAY_NAMES[day]); // 每个星期列宽度为10个字符
    }
    printf("\n");
    centerColorPrint(border, MAGENTA, "%s\n", border);

    // 循环遍历每个时间段，显示时间和每周的可用性
    for (int period = 0; period < MAX_PERIODS; period++) {
        // 打印课程编号和固定宽度的扩展时间范围列
        centerPrint(border, "%-6d %-5s-%-7s", period + 1, TIMETABLE[period].start_time, TIMETABLE[period].end_time);

        // 打印每周每天的可用情况，宽度固定
        for (int day = 0; day < 7; day++) {
            if (classroomTime->availableLessons.lessons[day][period] == 1) {
                printColored(GREEN, "%-5s", " V");  // 可用指示器，固定宽度
            } else {
                printColored(RED, "%-5s", " X");   // 不可用指示器，固定宽度
            }
        }
        printf("\n");
    }
}


void displayAvailableClassroomsByPeriod(DayOfWeek day, ClassroomAvailableTimeList availableTimes) {
    clearScreen();
    printHeader(DAY_NAMES[day]);

    char border[] = "----------------------------------------------";

    centerColorPrint(border, CYAN, "%-15s %-15s\n", "时间段", "教室");
    centerColorPrint(border, MAGENTA, "%s\n", border);

    int resultCount = 0;

    // 循环遍历所选日期的每个时间段
    for (int period = 0; period < MAX_PERIODS; period++) {
        int periodAvailableCount = 0;
        centerPrint(border, "%-5s - %-9s", TIMETABLE[period].start_time, TIMETABLE[period].end_time);

        // 遍历每个教室，检查该时间段是否可用
        for (int i = 0; i < availableTimes.count; i++) {
            ClassroomAvailableTime *classroomTime = &availableTimes.availableTimes[i];
            Classroom *classroom = classroomTime->classroom;

            // 检查教室是否在此时间段可用（用1标记）
            if (classroomTime->availableLessons.lessons[day][period] == 1) {
                // 以绿色显示教室名称，表示可用
                if (periodAvailableCount > 0) {
                    printf(", ");  // 多个教室用逗号分隔
                }
                printColored(GREEN, "%s", classroom->name);
                periodAvailableCount++;
            }
        }

        if (periodAvailableCount == 0) {
            // 如果该时间段没有可用教室，显示消息
            printColored(RED, "没有可用教室");
        }

        printf("\n");
        resultCount += periodAvailableCount;
    }

    if (resultCount == 0) {
        printColored(RED, "所选日期没有可用的教室。\n");
    }
}

#include <stdio.h>

void displayClassrooms(Classroom *head) {
    clearScreen();
    printHeader("所有教室");
    Classroom *current = head;

    while (current != NULL) {
        printOption(current->id, current->name);
        current = current->next;
    }
    printPrompt("查看:");
}
