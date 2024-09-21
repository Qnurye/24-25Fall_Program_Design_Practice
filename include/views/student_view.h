#ifndef STUDENT_H
#define STUDENT_H

#include "models/student.h"
#include "models/grade.h"

void displayStudentHomepage(Student *currentStudent, Grade *gradesHead);

void displayStudentInfo(Student *student);

void displayImportStudentPrompt(void);

void displayImportStudentError(int error_code);

void displayGrades(Grade *grades);

#endif
