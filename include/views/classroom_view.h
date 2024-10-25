//
// Created by qnurye on 10/25/24.
//

#ifndef VAR4_CLASSROOM_VIEW_H
#define VAR4_CLASSROOM_VIEW_H

#include "controllers/classroom_controller.h"
#include <stdio.h>
#include "models/timetable.h"
#include "controllers/classroom_controller.h"
#include "utils/display.h"
#include <string.h>

void displayClassroomWeeklyAvailability(const char *classroomName, ClassroomAvailableTimeList availableTimes);

void displayAvailableClassroomsByPeriod(DayOfWeek day, ClassroomAvailableTimeList availableTimes);

void displayClassrooms(Classroom *head);

#endif //VAR4_CLASSROOM_VIEW_H
