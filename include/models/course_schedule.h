#ifndef COURSE_SCHEDULE_H
#define COURSE_SCHEDULE_H

#include <stdbool.h>

typedef enum {
    Mon = 0, Tue, Wed, Thu, Fri, Sat, Sun
} DayOfWeek;

typedef struct CourseSchedule {
    int schedule_id;
    char course_name[50];
    int classroom_id;
    DayOfWeek day_of_week;
    int start_lesson_id;
    int end_lesson_id;
    char teacher_id[20];
    struct CourseSchedule *next;
} CourseSchedule;

CourseSchedule *loadCourseSchedulesFromFile(const char *filename);

void saveCourseSchedulesToFile(CourseSchedule *head, const char *filename);

void addCourseSchedule(CourseSchedule **head, const char *course_name, int classroom_id,
                       DayOfWeek day_of_week, int start_lesson_id, int end_lesson_id, const char *teacher_id);

CourseSchedule *findCourseScheduleById(CourseSchedule *head, int schedule_id);

void freeCourseSchedules(CourseSchedule **head);

#endif // COURSE_SCHEDULE_H
