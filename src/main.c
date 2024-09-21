#include "views/login_view.h"
#include "models/grade.h"
#include "utils/seed.h"
#include "models/notification.h"
#include "models/course_schedule.h"
#include "models/classroom.h"

int main(void) {
    seedData();

    Student *studentsHead = loadStudentsFromFile("students.txt");
    Teacher *teachersHead = loadTeachersFromFile("teachers.txt");
    Administrator *administratorsHead = loadAdministratorsFromFile("administrators.txt");
    Grade *gradesHead = loadGradesFromFile("grades.txt");
    Notification *notificationsHead = loadNotificationsFromFile("notifications.txt");
    Classroom *classroomsHead = loadClassroomsFromFile("classrooms.txt");
    CourseSchedule *courseSchedulesHead = loadCourseSchedulesFromFile("course_schedules.txt");

    handleLogin(&studentsHead, &teachersHead, &administratorsHead, &gradesHead, &notificationsHead, &courseSchedulesHead, &classroomsHead);

    saveCourseSchedulesToFile(courseSchedulesHead, "course_schedules.txt");
    freeCourseSchedules(&courseSchedulesHead);

    freeStudents(&studentsHead);
    freeTeachers(&teachersHead);
    freeAdministrators(&administratorsHead);
    freeGrades(&gradesHead);
    freeNotifications(&notificationsHead);
    return 0;
}
