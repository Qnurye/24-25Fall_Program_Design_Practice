#include "views/administrator_view.h"
#include "utils/display.h"

void handleAdministratorMenu(Student **studentsHead, Teacher **teachersHead) {
    int exit = 0;
    int choice;
    while (!exit) {
        clearScreen();
        printHeader("Administrator Homepage");

        printOption(1, "Import Student Information");
        printOption(2, "Import Teacher Information");
        printOption(3, "Display Current All Students Information");
        printOption(4, "Display Current All Teachers Information");
        printOption(5, "Clear Current All Students Information");
        printOption(6, "Clear Current All Teachers Information");
        printOption(7, "Exit");

        printPrompt("I want to: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                importStudents(studentsHead);
                saveStudentsToFile(*studentsHead, "students.txt");
                printColored(GREEN, "Successfully added a student\n");
                break;
            case 2:
                importTeachers(teachersHead);
                saveTeachersToFile(*teachersHead, "teachers.txt");
                printColored(GREEN, "Successfully added a teacher\n");
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
            case 7:
                exit = 1;
                break;
            default:
                break;
        }
    }
}
