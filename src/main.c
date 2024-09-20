#include <stdio.h>
#include "views/student.h"
#include "views/teacher.h"
#include "models/administrator.h"
#include "controllers/login.h"
#include "views/administrator.h"
#include "views/login.h"
#include "utils/seed.h"

#define MAX_ID_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

void handleStudentMenu(void);
void handleTeacherMenu(void);
void handleAdministratorMenu(Student **studentsHead, Teacher **teachersHead);

int main(void) {
    seedData();

    Student *studentsHead = loadStudentsFromFile("students.txt");
    Teacher *teachersHead = loadTeachersFromFile("teachers.txt");
    Administrator *administratorsHead = loadAdministratorsFromFile("administrators.txt");

    while (1) {
        char id[MAX_ID_LENGTH], password[MAX_PASSWORD_LENGTH];
        display_login_screen();
        scanf("%s %s", id, password);

        int role = login(studentsHead, teachersHead, administratorsHead, id, password);
        if (!role) continue;

        switch (role) {
            case 1:
                handleStudentMenu();
                break;
            case 2:
                handleTeacherMenu();
                break;
            case 3:
                handleAdministratorMenu(&studentsHead, &teachersHead);
                break;
            default:
                break;
        }
    }

    freeStudents(&studentsHead);
    freeTeachers(&teachersHead);
    freeAdministrators(&administratorsHead);
    return 0;
}

void handleStudentMenu(void) {
    while (1) {
        int choice;
        Stu_Home();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
                break;
            default:
                break;
        }
    }
}

void handleTeacherMenu(void) {
    while (1) {
        int choice;
        Tea_Home();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
                break;
            default:
                break;
        }
    }
}

void handleAdministratorMenu(Student **studentsHead, Teacher **teachersHead) {
    while (1) {
        int choice;
        Adm_Home();
        scanf("%d", &choice);
        if (choice == 7) break;
        switch (choice) {
            case 1:
                importStudents(studentsHead);
                saveStudentsToFile(*studentsHead, "students.txt");
                break;
            case 2:
                importTeachers(teachersHead);
                saveTeachersToFile(*teachersHead, "teachers.txt");
                break;
            case 3:
                displayStudents(*studentsHead);
                break;
            case 4:
                displayTeachers(*teachersHead);
                break;
            case 5:
                freeStudents(studentsHead);
                saveStudentsToFile(*studentsHead, "students.txt");
                break;
            case 6:
                freeTeachers(teachersHead);
                saveTeachersToFile(*teachersHead, "teachers.txt");
                break;
            default:
                break;
        }
        printf("Press 1 to continue: ");
        scanf("%d", &choice);
    }
}
