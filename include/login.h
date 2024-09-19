#ifndef LOGIN_H
#define LOGIN_H

#include "entities.h"

void Login_Screen(void);

int login(Student *students, Teacher *teachers, Administrator *administrators, const char *id, const char *password);

#endif
