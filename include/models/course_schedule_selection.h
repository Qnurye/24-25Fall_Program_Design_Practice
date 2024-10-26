#ifndef COURSE_SCHEDULE_SELECTION_H
#define COURSE_SCHEDULE_SELECTION_H

#include "course_schedule.h"
#include "student.h"

typedef struct CourseScheduleSelection {
    int selection_id;
    int schedule_id;
    char student_id[20];
    struct CourseScheduleSelection *next;
} CourseScheduleSelection;

void addCourseSelection(CourseScheduleSelection **head, int schedule_id, const char *student_id);

void removeCourseSelection(CourseScheduleSelection **head, int selection_id);

CourseScheduleSelection *findCourseSelectionsByStudentId(CourseScheduleSelection *head, const char *student_id);

int hasSelectedCourse(CourseScheduleSelection *head, const char *student_id, int schedule_id);

CourseScheduleSelection *loadCourseSelectionsFromFile(const char *filename);

void saveCourseSelectionsToFile(CourseScheduleSelection *head, const char *filename);

void freeCourseSelections(CourseScheduleSelection **head);

int checkSelectable(CourseScheduleSelection *head, CourseSchedule *schedule, CourseSchedule *allSchedules);

#endif // COURSE_SCHEDULE_SELECTION_H
