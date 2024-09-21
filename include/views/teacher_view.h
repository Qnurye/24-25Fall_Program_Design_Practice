#ifndef TEACHER_H
#define TEACHER_H

#include "models/teacher.h"
#include "models/student.h"
#include "models/grade.h"

void handleTeacherMenu(Teacher *currentTeacher, Student *studentsHead, Grade *gradesHead);
void displayTeacherInfo(Teacher *teacher);
void displayImportTeacherPrompt(void);
void displayImportTeacherError(int error_code);
void handleUploadGradeView(Student *studentsHead, Grade **gradesHead);
void displayTeacherMenu(void);
int getTeacherMenuChoice(void);

#endif
