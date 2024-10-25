#include "views/administrator_view.h"
#include "utils/display.h"
#include "controllers/auth_controller.h"
#include "views/login_view.h"

void handleAdministratorMenu(Administrator **currentAdministrator, Student **studentsHead, Teacher **teachersHead,
                             Administrator **administratorsHead) {
    int exit = 0;
    char choice[1];
    while (!exit) {
        clearScreen();
        printHeader("Administrator Homepage");

        printOption(1, "Import Student Information");
        printOption(2, "Import Teacher Information");
        printOption(3, "Display Current All Students Information");
        printOption(4, "Display Current All Teachers Information");
        printOption(5, "Clear Current All Students Information");
        printOption(6, "Clear Current All Teachers Information");
        printOption(7, "Change Password");
        printOption(8, "Exit");

        printPrompt("I want to: ");
        getInput(choice, 1);

        switch (choice[0]) {
            case '1':
                importStudents(studentsHead);
                saveStudentsToFile(*studentsHead, "students.txt");
                printColored(GREEN, "Successfully added a student\n");
                break;
            case '2':
                importTeachers(teachersHead);
                saveTeachersToFile(*teachersHead, "teachers.txt");
                printColored(GREEN, "Successfully added a teacher\n");
                break;
            case '3':
                displayStudents(*studentsHead);
                break;
            case '4':
                displayTeachers(*teachersHead);
                break;
            case '5':
                freeStudents(studentsHead);
                saveStudentsToFile(*studentsHead, "students.txt");
                break;
            case '6':
                freeTeachers(teachersHead);
                saveTeachersToFile(*teachersHead, "teachers.txt");
                break;
            case '7':
                printPrompt("Enter old password: ");
                char oldPassword[MAX_PASSWORD_LENGTH];
                getInput(oldPassword, MAX_PASSWORD_LENGTH);

                printPromptNoNewLine("Enter new password: ");
                char newPassword[MAX_PASSWORD_LENGTH];
                getPassword(newPassword, MAX_PASSWORD_LENGTH);

                int result = changePassword(*studentsHead, *teachersHead, *administratorsHead,
                                            (*currentAdministrator)->id, oldPassword, newPassword);

                switch (result) {
                    case -1:
                        printColored(RED, "\nOld password is incorrect\n");
                        break;
                    case 1:
                        printColored(GREEN, "\nPassword changed successfully\n");
                        break;
                    default:
                        break;
                }

                anyKey();
                break;
            case '8':
                exit = 1;
                break;
            default:
                break;
        }
    }
}
