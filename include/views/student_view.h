#ifndef STUDENT_H
#define STUDENT_H

#include "models/student.h"
#include "models/grade.h"
#include "models/notification.h"
#include "models/course_schedule.h"
#include "models/classroom.h"

// 现有函数声明
void displayStudentMenu(void);

void displayStudentInfo(Student *student);

void displayImportStudentPrompt(void);

void displayImportStudentError(int error_code);

void displayGrades(Grade *grades);

void displayStudentNotifications(Notification *notificationsHead);

void displayCourseSchedule(CourseSchedule *schedules, const char *student_id, Classroom *classrooms);

#endif
