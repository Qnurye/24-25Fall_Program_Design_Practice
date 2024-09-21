#include <string.h>
#include "controllers/login_controller.h"

int login(Student *students, Teacher *teachers, Administrator *administrators, const char *id, const char *password) {
    Student *student = findStudentByID(students, id);
    if (student) {
        if (strcmp(password, student->password) != 0) {
            return -1;
        } else {
            return student->role;
        }
    }

    Teacher *teacher = findTeacherByID(teachers, id);
    if (teacher) {
        if (strcmp(password, teacher->password) != 0) {
            return -1;
        } else {
            return teacher->role;
        }
    }

    Administrator *administrator = findAdministratorByID(administrators, id);
    if (administrator) {
        if (strcmp(password, administrator->password) != 0) {
            return -1;
        } else {
            return administrator->role;
        }
    }

    return 0;
}
