#include "views/student.h"
#include "views/teacher.h"
#include "views/login.h"
#include "utils/seed.h"


int main(void) {
    seedData();

    Student *studentsHead = loadStudentsFromFile("students.txt");
    Teacher *teachersHead = loadTeachersFromFile("teachers.txt");
    Administrator *administratorsHead = loadAdministratorsFromFile("administrators.txt");

    handleLogin(&studentsHead, &teachersHead, &administratorsHead);

    freeStudents(&studentsHead);
    freeTeachers(&teachersHead);
    freeAdministrators(&administratorsHead);
    return 0;
}
