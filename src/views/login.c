#include <stdio.h>
#include "views/login.h"

void display_login_screen(void) {
    printf("\n");
    printf("*********************************************************************\n");
    printf("***                    欢迎登录教务信息管理系统                   ***\n");
    printf("*********************************************************************\n");
    printf("\n");
    printf("*** 请输入您的学/工号（按回车键后输入密码）：                     ***\n");
    printf("\n");
}

void display_login_success(const char *role) {
    printf("登录成功（%s）\n", role);
}

void display_login_failure(const char *reason) {
    printf("%s\n", reason);
}
