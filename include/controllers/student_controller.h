#ifndef STUDENT_CONTROLLER_H
#define STUDENT_CONTROLLER_H

#include "../models/student.h"
#include "../models/grade.h"
#include "../models/notification.h"

void handleStudentMenuController(Student *currentStudent, Grade *gradesHead, Notification *notificationsHead);

#endif
