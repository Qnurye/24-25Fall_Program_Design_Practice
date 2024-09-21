#ifndef TEACHER_CONTROLLER_H
#define TEACHER_CONTROLLER_H

#include "models/teacher.h"
#include "models/student.h"
#include "models/grade.h"
#include "models/notification.h"

void handleTeacherMenuController(Teacher **currentTeacher, Student **studentsHead, Grade **gradesHead,
                                 Notification **notificationsHead);

void handlePublishNotification(Teacher *currentTeacher, Notification **notificationsHead);

#endif // TEACHER_CONTROLLER_H
