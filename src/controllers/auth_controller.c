#include <string.h>
#include "controllers/auth_controller.h"

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

int changePassword(Student *students, Teacher *teachers, Administrator *administrators, const char *id,
                   const char *oldPassword, const char *newPassword) {
    Student *student = findStudentByID(students, id);
    if (student) {
        if (strcmp(oldPassword, student->password) != 0) {
            return -1;
        } else {
            strcpy(student->password, newPassword);
            saveStudentsToFile(students, "students.txt");
            return 1;
        }
    }

    Teacher *teacher = findTeacherByID(teachers, id);
    if (teacher) {
        if (strcmp(oldPassword, teacher->password) != 0) {
            return -1;
        } else {
            strcpy(teacher->password, newPassword);
            saveTeachersToFile(teachers, "teachers.txt");
            return 1;
        }
    }

    Administrator *administrator = findAdministratorByID(administrators, id);
    if (administrator) {
        if (strcmp(oldPassword, administrator->password) != 0) {
            return -1;
        } else {
            strcpy(administrator->password, newPassword);
            saveAdministratorsToFile(administrators, "administrators.txt");
            return 1;
        }
    }

    return 0;
}
