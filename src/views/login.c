#include "views/login.h"
#include "utils/display.h"
#include "controllers/login.h"
#include "views/student.h"
#include "views/teacher.h"
#include "views/administrator.h"

void displayLoginSuccess(const char *role) {
    clearScreen();
    printColored(GREEN, "登录成功（%s）\n", role);
}

void displayLoginFailure(const char *reason) {
    clearScreen();
    printColored(RED, "%s\n", reason);
}

void handleLogin(Student **studentsHead, Teacher **teachersHead, Administrator **administratorsHead) {
    int signedIn = 0;
    while (!signedIn) {
        char id[MAX_ID_LENGTH], password[MAX_PASSWORD_LENGTH];
        clearScreen();
        printHeader("欢迎登录教务信息管理系统");
        printPrompt("学/工号：");
        scanf("%s", id);
        printPromptNoNewLine("密   码：");
        scanf("%s", password);

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
                displayStudentHomepage();
                break;
            case 2:
                displayLoginSuccess("教师");
                handleTeacherMenu();
                break;
            case 3:
                displayLoginSuccess("管理员");
                handleAdministratorMenu(studentsHead, teachersHead);
                break;
            default:
                break;
        }
    }
}
