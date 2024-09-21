#include "views/login_view.h"
#include "models/grade.h"
#include "utils/seed.h"
#include "models/notification.h"

int main(void) {
    seedData();

    Student *studentsHead = loadStudentsFromFile("students.txt");
    Teacher *teachersHead = loadTeachersFromFile("teachers.txt");
    Administrator *administratorsHead = loadAdministratorsFromFile("administrators.txt");
    Grade *gradesHead = loadGradesFromFile("grades.txt");
    Notification *notificationsHead = loadNotificationsFromFile("notifications.txt");

    handleLogin(&studentsHead, &teachersHead, &administratorsHead, &gradesHead, &notificationsHead);

    freeStudents(&studentsHead);
    freeTeachers(&teachersHead);
    freeAdministrators(&administratorsHead);
    freeGrades(&gradesHead);
    freeNotifications(&notificationsHead);
    return 0;
}
