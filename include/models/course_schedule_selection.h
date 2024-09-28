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

// Function to add a new course selection
void addCourseSelection(CourseScheduleSelection **head, int schedule_id, const char *student_id);

// Function to remove a course selection
void removeCourseSelection(CourseScheduleSelection **head, int selection_id);

// Function to find course selections for a specific student
CourseScheduleSelection *findCourseSelectionsByStudentId(CourseScheduleSelection *head, const char *student_id);

// Function to check if a student has already selected a specific course
int hasSelectedCourse(CourseScheduleSelection *head, const char *student_id, int schedule_id);

// Function to load course selections from file
CourseScheduleSelection *loadCourseSelectionsFromFile(const char *filename);

// Function to save course selections to file
void saveCourseSelectionsToFile(CourseScheduleSelection *head, const char *filename);

// Function to free the course selections list
void freeCourseSelections(CourseScheduleSelection **head);

#endif // COURSE_SCHEDULE_SELECTION_H
