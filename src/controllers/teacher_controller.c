#include "controllers/teacher_controller.h"
#include "views/teacher_view.h"
#include "controllers/notification_controller.h"
#include "utils/display.h"
#include "views/login_view.h"
#include "controllers/auth_controller.h"

void handleTeacherMenuController(Teacher **currentTeacher, Student **studentsHead, Grade **gradesHead,
                                 Notification **notificationsHead, CourseSchedule **courseSchedulesHead,
                                 Classroom **classroomsHead, Teacher **teachersHead,
                                 Administrator **administratorHead) {
    int exit = 0;
    char choice[1];
    while (!exit) {
        displayTeacherMenu();
        getInput(choice, 1);
        switch (choice[0]) {
            case '1':
                displayTeacherInfo(*currentTeacher);
                break;
            case '2':
                handleUploadGradeView(*studentsHead, gradesHead);
                break;
            case '3':
                handlePublishNotification(*currentTeacher, notificationsHead);
                break;
            case '4':
                displayCourseScheduleForTeacher(*courseSchedulesHead, (*currentTeacher)->id, *classroomsHead,
                                                *teachersHead);
                break;
            case '5':
                displayNotifications(*notificationsHead);
                break;
            case '6':
                printPrompt("Enter old password: ");
                char oldPassword[MAX_PASSWORD_LENGTH];
                getInput(oldPassword, MAX_PASSWORD_LENGTH);

                printPromptNoNewLine("Enter new password: ");
                char newPassword[MAX_PASSWORD_LENGTH];
                getPassword(newPassword, MAX_PASSWORD_LENGTH);

                int result = changePassword(*studentsHead, *teachersHead, *administratorHead,
                                            (*currentTeacher)->id, oldPassword, newPassword);

                switch (result) {
                    case -1:
                        printColored(RED, "\nOld password is incorrect\n");
                        break;
                    case 1:
                        printColored(GREEN, "\nPassword changed successfully\n");
                        break;
                    default:
                        break;
                }

                anyKey();
                break;
            case '7':
                exit = 1;
                break;
            default:
                printColored(RED, "Invalid option, please try again.\n");
                anyKey();
                break;
        }
    }
}
