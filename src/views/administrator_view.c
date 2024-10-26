#include "views/administrator_view.h"
#include "utils/display.h"
#include "controllers/auth_controller.h"
#include "views/login_view.h"

void handleAdministratorMenu(Administrator **currentAdministrator, Student **studentsHead, Teacher **teachersHead,
                             Administrator **administratorsHead) {
    int exit = 0;
    char choice[1];
    while (!exit) {
        clearScreen();
        printHeader("管理员主页");

        printOption(1, "导入学生信息");
        printOption(2, "导入教师信息");
        printOption(3, "显示当前所有学生信息");
        printOption(4, "显示当前所有教师信息");
        printOption(5, "清除当前所有学生信息");
        printOption(6, "清除当前所有教师信息");
        printOption(7, "修改密码");
        printOption(8, "退出");

        printPrompt("请选择操作: ");
        getInput(choice, 1);

        switch (choice[0]) {
            case '1':
                importStudents(studentsHead);
                saveStudentsToFile(*studentsHead, "data/students.txt");
                printColored(GREEN, "成功添加学生\n");
                break;
            case '2':
                importTeachers(teachersHead);
                saveTeachersToFile(*teachersHead, "data/teachers.txt");
                printColored(GREEN, "成功添加教师\n");
                break;
            case '3':
                displayStudents(*studentsHead);
                break;
            case '4':
                displayTeachers(*teachersHead);
                break;
            case '5':
                freeStudents(studentsHead);
                saveStudentsToFile(*studentsHead, "data/students.txt");
                break;
            case '6':
                freeTeachers(teachersHead);
                saveTeachersToFile(*teachersHead, "data/teachers.txt");
                break;
            case '7':
                printPrompt("输入旧密码: ");
                char oldPassword[MAX_PASSWORD_LENGTH];
                getInput(oldPassword, MAX_PASSWORD_LENGTH);

                printPromptNoNewLine("输入新密码: ");
                char newPassword[MAX_PASSWORD_LENGTH];
                getPassword(newPassword, MAX_PASSWORD_LENGTH);

                int result = changePassword(*studentsHead, *teachersHead, *administratorsHead,
                                            (*currentAdministrator)->id, oldPassword, newPassword);

                switch (result) {
                    case -1:
                        printColored(RED, "\n旧密码不正确\n");
                        break;
                    case 1:
                        printColored(GREEN, "\n密码修改成功\n");
                        break;
                    default:
                        break;
                }

                anyKey();
                break;
            case '8':
                exit = 1;
                break;
            default:
                break;
        }
    }
}
