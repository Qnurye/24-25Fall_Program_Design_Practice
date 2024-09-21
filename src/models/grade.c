#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "models/grade.h"

void addGrade(Grade **head, const char *student_id, const char *course_name, int usual_grade, int final_grade,
              float usual_grade_proportion) {
    Grade *newGrade = (Grade *) malloc(sizeof(Grade));
    if (!newGrade) return; // 内存分配失败

    strcpy(newGrade->student_id, student_id);
    strcpy(newGrade->course_name, course_name);
    newGrade->usual_grade = usual_grade;
    newGrade->final_grade = final_grade;
    newGrade->usual_grade_proportion = usual_grade_proportion;
    newGrade->next = NULL;

    if (*head == NULL) {
        *head = newGrade;
    } else {
        Grade *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newGrade;
        *head = temp;
    }
}

Grade *loadGradesFromFile(const char *filename) {
    Grade *head = NULL;
    Grade **tail = &head;

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("无法打开成绩文件");
        return NULL;
    }

    char student_id[20], course_name[50];
    int usual_grade, final_grade;
    float usual_grade_proportion;
    while (fscanf(file, "%s %s %d %d %f\n", student_id, course_name, &usual_grade, &final_grade,
                  &usual_grade_proportion) == 5) {
        addGrade(tail, student_id, course_name, usual_grade, final_grade, usual_grade_proportion);
        tail = &(*tail)->next;
    }

    fclose(file);
    return head;
}

void saveGradesToFile(Grade *head, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("无法打开成绩文件进行写入");
        return;
    }

    Grade *current = head;
    while (current != NULL) {
        fprintf(file, "%s %s %d %d %.2f\n", current->student_id, current->course_name, current->usual_grade,
                current->final_grade, current->usual_grade_proportion);
        current = current->next;
    }

    fclose(file);
}

Grade *findGradeByStudentID(Grade *head, const char *student_id) {
    Grade *current = head;
    while (current != NULL) {
        if (strcmp(current->student_id, student_id) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void freeGrades(Grade **head) {
    Grade *current = *head;
    while (current != NULL) {
        Grade *next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

Grade *getAllGradesByStudentID(Grade *head, const char *student_id) {
    Grade *current = head;
    Grade *resultHead = NULL;
    Grade **tail = &resultHead;

    while (current != NULL) {
        if (strcmp(current->student_id, student_id) == 0) {
            Grade *newGrade = (Grade *) malloc(sizeof(Grade));
            if (!newGrade) return resultHead; // 内存分配失败

            strcpy(newGrade->student_id, current->student_id);
            strcpy(newGrade->course_name, current->course_name);
            newGrade->usual_grade = current->usual_grade;
            newGrade->final_grade = current->final_grade;
            newGrade->usual_grade_proportion = current->usual_grade_proportion;
            newGrade->next = NULL;

            *tail = newGrade;
            tail = &newGrade->next;
        }
        current = current->next;
    }

    return resultHead;
}
