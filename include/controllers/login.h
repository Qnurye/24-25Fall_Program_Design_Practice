#ifndef LOGIN_H
#define LOGIN_H

#include "models/student.h"
#include "models/teacher.h"
#include "models/administrator.h"

int login(Student *students, Teacher *teachers, Administrator *administrators, const char *id, const char *password);

#endif
