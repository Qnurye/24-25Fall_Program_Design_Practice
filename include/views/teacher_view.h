#ifndef TEACHER_H
#define TEACHER_H

#include "models/teacher.h"
#include "models/student.h"
#include "models/grade.h"
#include "models/notification.h"
#include "models/course_schedule.h"
#include "models/classroom.h"

void displayTeacherInfo(Teacher *teacher);

void displayImportTeacherPrompt(void);

void displayImportTeacherError(int error_code);

void handleUploadGradeView(Student *studentsHead, Grade **gradesHead);

void displayTeacherMenu(void);

int getTeacherMenuChoice(void);

void handlePublishNotification(Teacher *currentTeacher, Notification **notificationsHead);

void displayCourseScheduleForTeacher(CourseSchedule *schedules, const char *teacher_id, Classroom *classrooms, Teacher *teachers);

#endif
