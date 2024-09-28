#ifndef STUDENT_H
#define STUDENT_H

#include "models/course_schedule_selection.h"
#include "../models/course_schedule.h"
#include "../models/notification.h"
#include "../models/grade.h"
#include "../models/student.h"
#include "models/student.h"
#include "models/grade.h"
#include "models/notification.h"
#include "models/course_schedule.h"
#include "models/classroom.h"
#include "models/teacher.h"

// 现有函数声明
void displayStudentMenu(void);

void displayStudentInfo(Student *student);

void displayImportStudentPrompt(void);

void displayImportStudentError(int error_code);

void displayGrades(Grade *grades);

void displayStudentNotifications(Notification *notificationsHead);

void displayCourseScheduleForStudents(CourseSchedule *schedules, const char *student_id, Classroom *classrooms,
                                      CourseScheduleSelection *courseSelectionsHead, Teacher *teachers);

void handleCourseSelection(Student *currentStudent, CourseSchedule *courseSchedulesHead,
                           CourseScheduleSelection **courseSelectionsHead, Classroom *classroomsHead,
                           Teacher *teachers);

#endif
