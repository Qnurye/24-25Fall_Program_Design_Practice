#ifndef TEACHER_H
#define TEACHER_H

#include "models/teacher.h"


void displayImportTeacherPrompt(void);

void displayImportTeacherError(int error_code);


void displayTeacherInfo(Teacher *teacher);
void handleTeacherMenu(Teacher *currentTeacher);

#endif
