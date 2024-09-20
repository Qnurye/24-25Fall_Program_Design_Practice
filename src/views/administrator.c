#include "views/administrator.h"
#include "utils/display.h"

void Adm_Home(void) {
    clearScreen();
    printHeader("管理员主页");

    printOption(1, "导入学生信息");
    printOption(2, "导入教师信息");
    printOption(3, "显示当前所有学生信息");
    printOption(4, "显示当前所有教师信息");
    printOption(5, "清空当前所有学生信息");
    printOption(6, "清空当前所有教师信息");
    printOption(7, "退出");

    printPrompt("请选择一个选项（输入对应的数字后按回车键）：");
}

// Add other administrator-related view functions here if needed
