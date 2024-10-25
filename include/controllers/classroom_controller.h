//
// Created by qnurye on 10/25/24.
//

#ifndef VAR4_CLASSROOM_CONTROLLER_H
#define VAR4_CLASSROOM_CONTROLLER_H

#include "models/classroom.h"
#include "models/course_schedule.h"
#include <stdio.h>
#include <malloc.h>
#include "models/timetable.h"

ClassroomAvailableTimeList *queryClassroomAvailableTimes(Classroom *classrooms, CourseSchedule *schedules);

#endif //VAR4_CLASSROOM_CONTROLLER_H
