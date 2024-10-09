#include "views/login_view.h"
#include "utils/display.h"
#include "controllers/login_controller.h"
#include "views/administrator_view.h"
#include "models/grade.h"
#include "controllers/teacher_controller.h"
#include "controllers/student_controller.h"
#include "controllers/notification_controller.h"
#include "models/classroom.h"

void displayLoginSuccess(const char *role) {
    clearScreen();
    printColored(GREEN, "Login Success ( %s )\n", role);
}

void displayLoginFailure(const char *reason) {
    clearScreen();
    printColored(RED, "%s\n", reason);
}

void handleLogin(Student **studentsHead, Teacher **teachersHead, Administrator **administratorsHead, Grade **gradesHead,
                 Notification **notificationsHead, CourseSchedule **courseSchedulesHead, Classroom **classroomsHead,
                 CourseScheduleSelection **courseSelectionsHead) {
    int signedIn = 0;
    while (!signedIn) {
        char id[MAX_ID_LENGTH], password[MAX_PASSWORD_LENGTH];
        clearScreen();
        printHeader("Welcome to the Educational Management System");
        printPrompt("Student/Teacher ID: ");
        scanf("%s", id);
        printPromptNoNewLine("Password: ");
        scanf("%s", password);

        int role = login(*studentsHead, *teachersHead, *administratorsHead, id, password);

        if (role > 0) signedIn = 1;

        switch (role) {
            case -1:
                displayLoginFailure("Wrong Password");
                break;
            case 0:
                displayLoginFailure("User does not exist");
                break;
            case 1:
                displayLoginSuccess("Student");
                handleStudentMenuController(findStudentByID(*studentsHead, id), *gradesHead, *notificationsHead,
                                            *courseSchedulesHead, *classroomsHead, courseSelectionsHead, *teachersHead);
                break;
            case 2:
                displayLoginSuccess("Teacher");
                Teacher *currentTeacher = findTeacherByID(*teachersHead, id);
                handleTeacherMenuController(&currentTeacher, studentsHead, gradesHead, notificationsHead, courseSchedulesHead,
                                            classroomsHead, teachersHead);
                break;
            case 3:
                displayLoginSuccess("Administrator");
                handleAdministratorMenu(studentsHead, teachersHead);
                break;
            default:
                break;
        }
    }
}
