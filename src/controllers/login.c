#include <string.h>
#include "controllers/login.h"
#include "views/login.h"

int login(Student *students, Teacher *teachers, Administrator *administrators, const char *id, const char *password) {
    Student *student = findStudentByID(students, id);
    if (student) {
        if (strcmp(password, "123456") != 0) {
            display_login_failure("密码错误");
            return 0;
        } else {
            display_login_success("学生");
            return student->role;
        }
    }

    Teacher *teacher = findTeacherByID(teachers, id);
    if (teacher) {
        if (strcmp(password, "123456") != 0) {
            display_login_failure("密码错误");
            return 0;
        } else {
            display_login_success("教师");
            return teacher->role;
        }
    }

    Administrator *administrator = findAdministratorByID(administrators, id);
    if (administrator) {
        if (strcmp(password, "123456") != 0) {
            display_login_failure("密码错误");
            return 0;
        } else {
            display_login_success("管理员");
            return administrator->role;
        }
    }

    display_login_failure("用户不存在");
    return 0;
}
