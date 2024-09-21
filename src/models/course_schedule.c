#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "models/course_schedule.h"

CourseSchedule *loadCourseSchedulesFromFile(const char *filename) {
    CourseSchedule *head = NULL;
    CourseSchedule **tail = &head;

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open course schedule file");
        return NULL;
    }

    int schedule_id, classroom_id, day_of_week, start_lesson_id, end_lesson_id;
    char course_name[50];
    while (fscanf(file, "%d %49s %d %d %d %d\n", &schedule_id, course_name, &classroom_id, &day_of_week,
                  &start_lesson_id, &end_lesson_id) == 6) {
        CourseSchedule *newSchedule = (CourseSchedule *) malloc(sizeof(CourseSchedule));
        if (!newSchedule) {
            perror("Failed to allocate memory for course schedule");
            fclose(file);
            freeCourseSchedules(&head);
            return NULL;
        }

        newSchedule->schedule_id = schedule_id;
        strncpy(newSchedule->course_name, course_name, sizeof(newSchedule->course_name) - 1);
        newSchedule->course_name[sizeof(newSchedule->course_name) - 1] = '\0';
        newSchedule->classroom_id = classroom_id;
        newSchedule->classroom_id = classroom_id;
        newSchedule->day_of_week = (DayOfWeek) day_of_week;
        newSchedule->start_lesson_id = start_lesson_id;
        newSchedule->end_lesson_id = end_lesson_id;
        newSchedule->next = NULL;

        *tail = newSchedule;
        tail = &newSchedule->next;
    }

    fclose(file);
    return head;
}

void saveCourseSchedulesToFile(CourseSchedule *head, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open course schedule file for writing");
        return;
    }

    CourseSchedule *current = head;
    while (current != NULL) {
        fprintf(file, "%d %s %d %d %d %d\n", current->schedule_id, current->course_name,
                current->classroom_id, current->day_of_week, current->start_lesson_id, current->end_lesson_id);
        current = current->next;
    }

    fclose(file);
}

void addCourseSchedule(CourseSchedule **head, const char *course_name, int classroom_id,
                       DayOfWeek day_of_week, int start_lesson_id, int end_lesson_id) {
    CourseSchedule *newSchedule = (CourseSchedule *) malloc(sizeof(CourseSchedule));
    if (!newSchedule) {
        perror("Failed to allocate memory for new course schedule");
        return;
    }

    newSchedule->schedule_id = (*head == NULL) ? 1 : (*head)->schedule_id + 1;
    strncpy(newSchedule->course_name, course_name, sizeof(newSchedule->course_name) - 1);
    newSchedule->course_name[sizeof(newSchedule->course_name) - 1] = '\0';
    newSchedule->classroom_id = classroom_id;
    newSchedule->classroom_id = classroom_id;
    newSchedule->day_of_week = day_of_week;
    newSchedule->start_lesson_id = start_lesson_id;
    newSchedule->end_lesson_id = end_lesson_id;
    newSchedule->next = *head;

    *head = newSchedule;
}

CourseSchedule *findCourseScheduleById(CourseSchedule *head, int schedule_id) {
    CourseSchedule *current = head;
    while (current != NULL) {
        if (current->schedule_id == schedule_id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void freeCourseSchedules(CourseSchedule **head) {
    CourseSchedule *current = *head;
    while (current != NULL) {
        CourseSchedule *next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}
