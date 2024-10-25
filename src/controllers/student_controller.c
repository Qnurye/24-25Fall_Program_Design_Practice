#include "controllers/student_controller.h"
#include "views/student_view.h"
#include "controllers/notification_controller.h"
#include "utils/display.h"
#include "controllers/grade_controller.h"
#include "models/classroom.h"
#include "models/course_schedule_selection.h"
#include "views/login_view.h"
#include "controllers/auth_controller.h"
#include "views/classroom_view.h"
#include "controllers/classroom_controller.h"
#include <stdlib.h>

void handleStudentMenuController(Student *currentStudent, Grade *gradesHead, Notification *notificationsHead,
                                 CourseSchedule *courseSchedulesHead, Classroom *classroomsHead,
                                 CourseScheduleSelection **courseSelectionsHead, Teacher *teachers, Student *students,
                                 Administrator *administrators) {
    int exit = 0;
    char choice[1];
    ClassroomAvailableTimeList availableTimes;
    while (!exit) {
        displayStudentMenu();
        getInput(choice, 1);
        switch (choice[0]) {
            case '1':
                displayStudentInfo(currentStudent);
                break;
            case '2':
                displayStudentGrades(currentStudent->id, gradesHead);
                break;
            case '3':
                displayStudentNotifications(notificationsHead);
                break;
            case '4':
                displayCourseScheduleForStudents(courseSchedulesHead, currentStudent->id, classroomsHead,
                                                 *courseSelectionsHead,
                                                 teachers);
                break;
            case '5':
                availableTimes = *queryClassroomAvailableTimes(classroomsHead, courseSchedulesHead);

                printEmptyRoomsSubmenu();
                char typeChoice[2];
                getInput(typeChoice, 1);
                switch (typeChoice[0]) {
                    case '1':
                        printAvailableWeekDays();
                        char weekdayChoice[2];
                        getInput(weekdayChoice, 1);
                        DayOfWeek day = (DayOfWeek) (weekdayChoice[0] - '0' - 1);
                        displayAvailableClassroomsByPeriod(day, availableTimes);
                        break;
                    case '2':
                        displayClassrooms(classroomsHead);
                        char classroomChoice[3];
                        getInput(classroomChoice, 3);
                        long classroomId = strtol(classroomChoice, NULL, 10);
                        Classroom cur = *findClassroomById(classroomsHead, (int) classroomId);
                        displayClassroomWeeklyAvailability(cur.name, availableTimes);
                        break;
                }
                anyKey();
                break;
            case '6':
                handleCourseSelection(currentStudent, courseSchedulesHead, courseSelectionsHead, classroomsHead,
                                      teachers);
                break;
            case '7':
                printPrompt("Enter old password: ");
                char oldPassword[MAX_PASSWORD_LENGTH];
                getInput(oldPassword, MAX_PASSWORD_LENGTH);

                printPromptNoNewLine("Enter new password: ");
                char newPassword[MAX_PASSWORD_LENGTH];
                getPassword(newPassword, MAX_PASSWORD_LENGTH);

                int result = changePassword(students, teachers, administrators,
                                            (*currentStudent).id, oldPassword, newPassword);

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
                printColored(RED, "Invalid option, please try again.\n");
                anyKey();
                break;
        }
    }
}

