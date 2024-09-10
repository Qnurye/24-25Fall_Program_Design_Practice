#ifndef VAR4_CLASSROOM_CONTROLLER_H
#define VAR4_CLASSROOM_CONTROLLER_H

#include "../models/classroom.h"

Classroom **get_empty_classrooms(const char *day_of_week, int start_lesson_id, int end_lesson_id, int *count);

void free_classroom_list(Classroom **classrooms, int count);

#endif // VAR4_CLASSROOM_CONTROLLER_H
