#ifndef STUDENT_CONTROLLER_H
#define STUDENT_CONTROLLER_H

#include "models/student.h"
#include "models/grade.h"
#include "models/notification.h"
#include "models/course_schedule.h"
#include "models/classroom.h"
#include "models/course_schedule_selection.h"
#include "models/teacher.h"
#include "models/administrator.h"

void handleStudentMenuController(Student *currentStudent, Grade *gradesHead, Notification *notificationsHead,
                                 CourseSchedule *courseSchedulesHead, Classroom *classroomsHead,
                                 CourseScheduleSelection **courseSelectionsHead, Teacher *teachers, Student *students,
                                 Administrator *administrators);

#endif
