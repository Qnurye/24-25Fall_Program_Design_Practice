#ifndef STUDENT_CONTROLLER_H
#define STUDENT_CONTROLLER_H

#include "../models/student.h"
#include "../models/grade.h"
#include "../models/notification.h"
#include "../models/course_schedule.h"
#include "models/classroom.h"

void handleStudentMenuController(Student *currentStudent, Grade *gradesHead, Notification *notificationsHead, CourseSchedule *courseSchedulesHead, Classroom *classroomsHead);

#endif
