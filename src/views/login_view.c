#include "views/login_view.h"
#include "utils/display.h"
#include "controllers/auth_controller.h"
#include "views/administrator_view.h"
#include "models/grade.h"
#include "controllers/teacher_controller.h"
#include "controllers/student_controller.h"
#include "controllers/notification_controller.h"
#include "models/classroom.h"

void displayLoginSuccess(const char *role) {
    clearScreen();
    printColored(GREEN, "登录成功 ( %s )\n", role);
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
        printHeader("欢迎使用教育管理系统");
        printPrompt("学生/教师ID: ");
        getInput(id, MAX_ID_LENGTH);
        printPromptNoNewLine("密码: ");
        getPassword(password, MAX_PASSWORD_LENGTH);

        int role = login(*studentsHead, *teachersHead, *administratorsHead, id, password);

        if (role > 0) signedIn = 1;

        switch (role) {
            case -1:
                displayLoginFailure("密码错误");
                break;
            case 0:
                displayLoginFailure("用户不存在");
                break;
            case 1:
                displayLoginSuccess("学生");
                handleStudentMenuController(findStudentByID(*studentsHead, id), *gradesHead, *notificationsHead,
                                            *courseSchedulesHead, *classroomsHead, courseSelectionsHead,
                                            *teachersHead, *studentsHead, *administratorsHead);
                break;
            case 2:
                displayLoginSuccess("教师");
                Teacher *currentTeacher = findTeacherByID(*teachersHead, id);
                handleTeacherMenuController(&currentTeacher, studentsHead, gradesHead, notificationsHead, courseSchedulesHead,
                                            classroomsHead, teachersHead, administratorsHead);
                break;
            case 3:
                displayLoginSuccess("管理员");
                Administrator *currentAdministrator = findAdministratorByID(*administratorsHead, id);
                handleAdministratorMenu(&currentAdministrator, studentsHead, teachersHead, administratorsHead);
                break;
            default:
                break;
        }
    }
}
