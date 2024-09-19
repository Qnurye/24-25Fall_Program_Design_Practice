#ifndef STUDENT_H
#define STUDENT_H

#include "models/student.h"

void Stu_Home(void);
void displayStudents(Student *head);
void displayImportStudentPrompt();
void displayImportStudentSuccess();
void displayImportStudentError(int error_code);
void displayFreeStudentsSuccess();

#endif
