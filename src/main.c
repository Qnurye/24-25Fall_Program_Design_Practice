#include <stdio.h>
#include "../include/student.h"
#include "../include/teacher.h"
#include "../include/administrator.h"
#include "../include/login.h"
#include "../include/data.h"


int main(void) {
    int role;
    int choice;
    char id[20], password[10];
    Student *studentsHead = NULL;
    Teacher *teachersHead = NULL;
    Administrator *administratorsHead = NULL;
    studentsHead = loadStudentsFromFile("students.txt");
    teachersHead = loadTeachersFromFile("teachers.txt");
    administratorsHead = loadAdministratorsFromFile("administrators.txt");
    while (1) {
        Login_Screen();
        scanf("%19s %9s", id, password);
        role = login(studentsHead, teachersHead, administratorsHead, id, password);
        if (!role)continue;
        else {
            switch (role) {
                case 1:
                    while (1) {
                        Stu_Home();
                        scanf("%d", &choice);
                        switch (choice) {
                            case 1:
                                break;
                            case 2:
                                break;
                            case 3:
                                break;
                        }
                        if (choice == 4)
                            break;
                    }
                    continue;

                case 2:
                    while (1) {
                        Tea_Home();
                        scanf("%d", &choice);
                        switch (choice) {
                            case 1:
                                break;
                            case 2:
                                break;
                            case 3:
                                break;
                        }
                        if (choice == 4)
                            break;
                    }
                    continue;

                case 3:
                    while (1) {
                        Adm_Home();
                        scanf("%d", &choice);
                        switch (choice) {
                            case 1:
                                importStudents(&studentsHead);
                                saveStudentsToFile(studentsHead, "students.txt");
                                break;
                            case 2:
                                importTeachers(&teachersHead);
                                saveTeachersToFile(teachersHead, "teachers.txt");
                                break;
                            case 3:
                                displayStudents(studentsHead);
                                scanf("%d", &choice);
                                if (choice == 1)break;
                            case 4:
                                displayTeachers(teachersHead);
                                scanf("%d", &choice);
                                if (choice == 1)break;
                            case 5:
                                freeStudents(&studentsHead);
                                saveStudentsToFile(studentsHead, "students.txt");
                                scanf("%d", &choice);
                                if (choice == 1)break;
                            case 6:
                                freeTeachers(&teachersHead);
                                saveTeachersToFile(teachersHead, "teachers.txt");
                                scanf("%d", &choice);
                                if (choice == 1)break;
                        }
                        if (choice == 7)
                            break;
                    }
                    continue;
            }
        }
    }
    return 0;
}