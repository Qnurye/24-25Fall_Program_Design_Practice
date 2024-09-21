#ifndef TEACHER_CONTROLLER_H
#define TEACHER_CONTROLLER_H

#include "models/teacher.h"
#include "models/student.h"
#include "models/grade.h"

// 处理教师菜单的控制器函数
void handleTeacherMenuController(Teacher **currentTeacher, Student **studentsHead, Grade **gradesHead);

#endif // TEACHER_CONTROLLER_H
