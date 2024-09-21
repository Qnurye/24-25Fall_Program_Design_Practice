#include "controllers/teacher_controller.h"
#include "models/teacher.h"
#include "models/student.h"
#include "models/grade.h"
#include "utils/display.h"
#include "views/teacher_view.h"
#include "controllers/notification_controller.h"

void handleTeacherMenuController(Teacher **currentTeacher, Student **studentsHead, Grade **gradesHead,
                                 Notification **notificationsHead) {
    int exit = 0;
    while (!exit) {
        displayTeacherMenu();
        int choice = getTeacherMenuChoice();

        switch (choice) {
            case 1:
                displayTeacherInfo(*currentTeacher);
                break;
            case 2:
                handleUploadGradeView(*studentsHead, gradesHead);
                saveGradesToFile(*gradesHead, "grades.txt");
                break;
            case 3:
                handlePublishNotification(*currentTeacher, notificationsHead);
                break;
            case 4:
                printColored(BLUE, "功能尚未实现。\n");
                anyKey();
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

    freeGrades(gradesHead);
}
