#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "models/course_schedule_selection.h"

void addCourseSelection(CourseScheduleSelection **head, int schedule_id, const char *student_id) {
    CourseScheduleSelection *newSelection = (CourseScheduleSelection *) malloc(sizeof(CourseScheduleSelection));
    if (!newSelection) {
        perror("Failed to allocate memory for new course selection");
        return;
    }

    static int next_id = 1;
    newSelection->selection_id = next_id++;
    newSelection->schedule_id = schedule_id;
    strncpy(newSelection->student_id, student_id, sizeof(newSelection->student_id) - 1);
    newSelection->student_id[sizeof(newSelection->student_id) - 1] = '\0';


    newSelection->next = *head;

    *head = newSelection;
}

void removeCourseSelection(CourseScheduleSelection **head, int selection_id) {
    CourseScheduleSelection *current = *head;
    CourseScheduleSelection *prev = NULL;

    while (current != NULL && current->selection_id != selection_id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) return; // Selection not found

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

CourseScheduleSelection *findCourseSelectionsByStudentId(CourseScheduleSelection *head, const char *student_id) {
    CourseScheduleSelection *result = NULL;
    CourseScheduleSelection *current = head;

    while (current != NULL) {
        if (strcmp(current->student_id, student_id) == 0) {
            CourseScheduleSelection *newNode = (CourseScheduleSelection *) malloc(sizeof(CourseScheduleSelection));
            if (!newNode) {
                perror("Failed to allocate memory for course selection");
                return result;
            }
            *newNode = *current;
            newNode->next = result;
            result = newNode;
        }
        current = current->next;
    }

    return result;
}

int hasSelectedCourse(CourseScheduleSelection *head, const char *student_id, int schedule_id) {
    CourseScheduleSelection *current = head;

    while (current != NULL) {
        if (strcmp(current->student_id, student_id) == 0 && current->schedule_id == schedule_id) {
            return 1; // Course already selected
        }
        current = current->next;
    }

    return 0; // Course not selected
}

CourseScheduleSelection *loadCourseSelectionsFromFile(const char *filename) {
    CourseScheduleSelection *head = NULL;
    CourseScheduleSelection **tail = &head;

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open course selections file");
        return NULL;
    }

    int selection_id, schedule_id;
    char student_id[20];
    while (fscanf(file, "%d %d %19s\n", &selection_id, &schedule_id, student_id) == 3) {
        CourseScheduleSelection *newSelection = (CourseScheduleSelection *) malloc(sizeof(CourseScheduleSelection));
        if (!newSelection) {
            perror("Failed to allocate memory for course selection");
            fclose(file);
            freeCourseSelections(&head);
            return NULL;
        }

        newSelection->selection_id = selection_id;
        newSelection->schedule_id = schedule_id;
        strncpy(newSelection->student_id, student_id, sizeof(newSelection->student_id) - 1);
        newSelection->student_id[sizeof(newSelection->student_id) - 1] = '\0';
        newSelection->next = NULL;

        *tail = newSelection;
        tail = &newSelection->next;
    }

    fclose(file);
    return head;
}

void saveCourseSelectionsToFile(CourseScheduleSelection *head, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open course selections file for writing");
        return;
    }

    CourseScheduleSelection *current = head;
    while (current != NULL) {
        fprintf(file, "%d %d %s\n", current->selection_id, current->schedule_id, current->student_id);
        current = current->next;
    }

    fclose(file);
}

void freeCourseSelections(CourseScheduleSelection **head) {
    CourseScheduleSelection *current = *head;
    while (current != NULL) {
        CourseScheduleSelection *next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}
