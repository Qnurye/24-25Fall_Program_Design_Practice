#include "views/login.h"
#include "utils/display.h"

void display_login_screen(void) {
    clearScreen();
    printHeader("欢迎登录教务信息管理系统");
    printPrompt("请输入您的学/工号：");
}

void display_password_prompt(void) {
    printPromptNoNewLine("请输入您的密码：");
}

void display_login_success(const char *role) {
    clearScreen();
    printColored(GREEN, "登录成功（%s）\n", role);
}

void display_login_failure(const char *reason) {
    clearScreen();
    printColored(RED, "%s\n", reason);
}

void end_password_input(void) {
    // TODO)) Password redacted
}
