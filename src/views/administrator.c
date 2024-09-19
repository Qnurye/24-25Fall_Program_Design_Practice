#include <stdio.h>
#include "views/administrator.h"

void Adm_Home(void) {
    printf("\n");
    printf("*****************************************\n");
    printf("***            管理员主页             ***\n");
    printf("*****************************************\n");
    printf("\n");
    printf("    1. 导入学生信息\n");
    printf("    2. 导入教师信息\n");
    printf("    3. 显示当前所有学生信息\n");
    printf("    4. 显示当前所有教师信息\n");
    printf("    5. 清空当前所有学生信息\n");
    printf("    6. 清空当前所有教师信息\n");
    printf("    7. 退出\n");
    printf("\n");
    printf("请选择一个选项（输入对应的数字后按回车键）：");
}
