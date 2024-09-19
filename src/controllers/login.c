#include <stdio.h>
#include <string.h>
#include "controllers/login.h"

void Login_Screen(void) {
    printf("\n");
    printf("*********************************************************************\n");
    printf("***                    欢迎登录教务信息管理系统                   ***\n");
    printf("*********************************************************************\n");
    printf("\n");
    printf("*** 请输入您的学/工号（按回车键后输入密码）：                     ***\n");
    printf("\n");
}

int login(Student *students, Teacher *teachers, Administrator *administrators, const char *id, const char *password) {
    Student *student = findStudentByID(students, id);
    if (student) {
        if (strcmp(password, "123456") != 0) {
            printf("密码错误\n");
            return 0; // 登录失败  
        } else {
            printf("登录成功（学生）\n");
            return student->role; // 登录成功  
        }

    }

    Teacher *teacher = findTeacherByID(teachers, id);
    if (teacher) {
        if (strcmp(password, "123456") != 0) {
            printf("密码错误\n");
            return 0; // 登录失败  
        } else {
            printf("登录成功（教师）\n");
            return teacher->role; // 登录成功  
        }

    }

    Administrator *administrator = findAdministratorByID(administrators, id);
    if (administrator) {
        if (strcmp(password, "123456") != 0) {
            printf("密码错误\n");
            return 0; // 登录失败  
        } else {
            printf("登录成功（管理员）\n");
            return administrator->role; // 登录成功  
        }

    }

    printf("用户不存在\n");
    return 0; // 登录失败  
}
