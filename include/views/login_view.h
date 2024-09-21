#ifndef LOGIN_VIEW_H
#define LOGIN_VIEW_H

#include "models/student.h"
#include "models/teacher.h"
#include "models/administrator.h"
#include "models/grade.h"

#define MAX_ID_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

void displayLoginSuccess(const char *role);

void displayLoginFailure(const char *reason);

void handleLogin(Student **studentsHead, Teacher **teachersHead, Administrator **administratorsHead, Grade **gradesHead);

#endif