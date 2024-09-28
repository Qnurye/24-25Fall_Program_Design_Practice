#include "controllers/teacher_controller.h"
#include "views/teacher_view.h"
#include "controllers/notification_controller.h"
#include "utils/display.h"

void handleTeacherMenuController(Teacher **currentTeacher, Student **studentsHead, Grade **gradesHead,
                                 Notification **notificationsHead, CourseSchedule **courseSchedulesHead,
                                 Classroom **classroomsHead, Teacher **teachersHead) {
    int exit = 0;
    int choice;
    while (!exit) {
        displayTeacherMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayTeacherInfo(*currentTeacher);
                break;
            case 2:
                handleUploadGradeView(*studentsHead, gradesHead);
                break;
            case 3:
                handlePublishNotification(*currentTeacher, notificationsHead);
                break;
            case 4:
                displayCourseScheduleForTeacher(*courseSchedulesHead, (*currentTeacher)->id, *classroomsHead,
                                                *teachersHead);
                break;
            case 5:
                displayNotifications(*notificationsHead);
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
