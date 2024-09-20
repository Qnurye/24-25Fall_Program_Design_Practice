#ifndef STUDENT_H
#define STUDENT_H

#include "models/student.h"

void Stu_Home(void);
void displayStudents(Student *head);
void displayImportStudentPrompt(void);
void displayImportStudentSuccess(void);
void displayImportStudentError(int error_code);
void displayFreeStudentsSuccess(void);

#endif
