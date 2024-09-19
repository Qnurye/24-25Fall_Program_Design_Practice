#ifndef VAR4_SCHEDULE_CONTROLLER_H
#define VAR4_SCHEDULE_CONTROLLER_H

#include "../models/course_schedule.h"

CourseSchedule **get_student_schedule(int student_id, int *count);

void free_schedule_list(CourseSchedule **schedules, int count);
void schedule_write();

#endif // VAR4_SCHEDULE_CONTROLLER_H
