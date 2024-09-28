#ifndef TEACHER_CONTROLLER_H
#define TEACHER_CONTROLLER_H

#include "models/teacher.h"
#include "models/student.h"
#include "models/grade.h"
#include "models/notification.h"
#include "models/course_schedule.h"
#include "models/classroom.h"

void handleTeacherMenuController(Teacher **currentTeacher, Student **studentsHead, Grade **gradesHead,
                                 Notification **notificationsHead, CourseSchedule **courseSchedulesHead,
                                 Classroom **classroomsHead, Teacher **teachersHead);

void handlePublishNotification(Teacher *currentTeacher, Notification **notificationsHead);

#endif // TEACHER_CONTROLLER_H
