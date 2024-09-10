#ifndef VAR4_GRADE_CONTROLLER_H
#define VAR4_GRADE_CONTROLLER_H

#include "../models/grade.h"

Grade **get_student_grades(int student_id, int *count);

void free_grade_list(Grade **grades, int count);

#endif // VAR4_GRADE_CONTROLLER_H
