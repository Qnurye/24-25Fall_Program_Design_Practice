#include "views/login_view.h"
#include "models/grade.h"
#include "utils/seed.h"
#include "models/notification.h"
#include "models/course_schedule.h"
#include "models/classroom.h"
#include "models/course_schedule_selection.h"

int main(void) {
    seedData();

    Student *studentsHead = loadStudentsFromFile("data/students.txt");
    Teacher *teachersHead = loadTeachersFromFile("data/teachers.txt");
    Administrator *administratorsHead = loadAdministratorsFromFile("data/administrators.txt");
    Grade *gradesHead = loadGradesFromFile("data/grades.txt");
    Notification *notificationsHead = loadNotificationsFromFile("data/notifications.txt");
    Classroom *classroomsHead = loadClassroomsFromFile("data/classrooms.txt");
    CourseSchedule *courseSchedulesHead = loadCourseSchedulesFromFile("data/course_schedules.txt");
    CourseScheduleSelection *courseSelectionsHead = loadCourseSelectionsFromFile("data/course_selections.txt");

    handleLogin(&studentsHead, &teachersHead, &administratorsHead, &gradesHead, &notificationsHead,
                &courseSchedulesHead, &classroomsHead, &courseSelectionsHead);

    saveCourseSchedulesToFile(courseSchedulesHead, "course_schedules.txt");
    freeCourseSchedules(&courseSchedulesHead);

    saveCourseSelectionsToFile(courseSelectionsHead, "course_selections.txt");
    freeCourseSelections(&courseSelectionsHead);

    freeStudents(&studentsHead);
    freeTeachers(&teachersHead);
    freeAdministrators(&administratorsHead);
    freeGrades(&gradesHead);
    freeNotifications(&notificationsHead);
    return 0;
}
