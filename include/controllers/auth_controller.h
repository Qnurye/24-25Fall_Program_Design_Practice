#ifndef LOGIN_CONTROLLER_H
#define LOGIN_CONTROLLER_H

#include "models/student.h"
#include "models/teacher.h"
#include "models/administrator.h"

int login(Student *students, Teacher *teachers, Administrator *administrators, const char *id, const char *password);

int changePassword(Student *students, Teacher *teachers, Administrator *administrators, const char *id,
                   const char *oldPassword, const char *newPassword);

#endif
