#ifndef GRADE_CONTROLLER_H
#define GRADE_CONTROLLER_H

#include "models/grade.h"
#include "models/student.h"

// 上传成绩的控制器函数
void processUploadGrade(Student *studentsHead, Grade **gradesHead, 
                        const char *student_id, const char *course_name, 
                        int usual_grade, int final_grade, float usual_grade_proportion);

// 显示学生的所有成绩
void displayStudentGrades(const char *student_id, Grade *gradesHead);

#endif // GRADE_CONTROLLER_H
