#ifndef TEACHER_H
#define TEACHER_H

#include "models/teacher.h"

void Tea_Home(void);

void displayTeachers(Teacher *head);

void displayImportTeacherPrompt(void);
void displayImportTeacherSuccess(void);
void displayImportTeacherError(int error_code);
void displayFreeTeachersSuccess(void);

#endif
