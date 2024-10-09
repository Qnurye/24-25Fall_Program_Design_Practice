#include "controllers/student_controller.h"
#include "views/student_view.h"
#include "controllers/notification_controller.h"
#include "utils/display.h"
#include "controllers/grade_controller.h"
#include "models/classroom.h"
#include "models/course_schedule_selection.h"

void handleStudentMenuController(Student *currentStudent, Grade *gradesHead, Notification *notificationsHead,
                                 CourseSchedule *courseSchedulesHead, Classroom *classroomsHead,
                                 CourseScheduleSelection **courseSelectionsHead, Teacher *teachers) {
    int exit = 0;
    int choice;
    while (!exit) {
        displayStudentMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayStudentInfo(currentStudent);
                break;
            case 2:
                displayStudentGrades(currentStudent->id, gradesHead);
                break;
            case 3:
                displayStudentNotifications(notificationsHead);
                break;
            case 4:
                displayCourseScheduleForStudents(courseSchedulesHead, currentStudent->id, classroomsHead,
                                                 *courseSelectionsHead,
                                                 teachers);
                break;
            case 5:
                // 实现空教室查询
                printColored(BLUE, "Function not implemented yet.\n");
                anyKey();
                break;
            case 6:
                handleCourseSelection(currentStudent, courseSchedulesHead, courseSelectionsHead, classroomsHead,
                                      teachers);
                break;
            case 7:
                exit = 1;
                break;
            default:
                printColored(RED, "Invalid option, please try again.\n");
                anyKey();
                break;
        }
    }
}

