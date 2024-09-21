#include "controllers/student_controller.h"
#include "views/student_view.h"
#include "controllers/notification_controller.h"
#include "utils/display.h"
#include "controllers/grade_controller.h"
#include "models/classroom.h"

void handleStudentMenuController(Student *currentStudent, Grade *gradesHead, Notification *notificationsHead, CourseSchedule *courseSchedulesHead, Classroom *classroomsHead) {
    int exit = 0;
    int choice;
    while (!exit) {
        displayStudentMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayStudentInfo(currentStudent);
                break;
            case 2:
                displayStudentGrades(currentStudent->id, gradesHead);
                break;
            case 3:
                displayStudentNotifications(notificationsHead);
                break;
            case 4:
                displayCourseSchedule(courseSchedulesHead, currentStudent->id, classroomsHead);
                break;
            case 5:
                // 实现空教室查询
                printColored(BLUE, "功能尚未实现。\n");
                anyKey();
                break;
            case 6:
                exit = 1;
                break;
            default:
                printColored(RED, "无效的选项，请重试。\n");
                anyKey();
                break;
        }
    }
}
