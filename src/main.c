#include "views/login_view.h"
#include "models/grade.h"
#include "utils/seed.h"

int main(void) {
    seedData();

    Student *studentsHead = loadStudentsFromFile("students.txt");
    Teacher *teachersHead = loadTeachersFromFile("teachers.txt");
    Administrator *administratorsHead = loadAdministratorsFromFile("administrators.txt");
    Grade *gradesHead = loadGradesFromFile("grades.txt");

    handleLogin(&studentsHead, &teachersHead, &administratorsHead, &gradesHead);

    freeStudents(&studentsHead);
    freeTeachers(&teachersHead);
    freeAdministrators(&administratorsHead);
    freeGrades(&gradesHead);
    return 0;
}
