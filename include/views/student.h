#ifndef STUDENT_H
#define STUDENT_H

#include "models/student.h"

void displayStudentHomepage(Student *currentStudent);
void displayStudentInfo(Student *student);
void displayImportStudentPrompt(void);
void displayImportStudentError(int error_code);

#endif
