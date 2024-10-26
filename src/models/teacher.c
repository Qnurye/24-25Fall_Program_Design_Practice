//
// Created by qnurye on 24-9-20.
//

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "models/teacher.h"
#include "views/teacher_view.h"
#include "utils/display.h"

void addTeacher(Teacher **head, const char *id, const char *name, int role, const char *gender, const char *password) {
    Teacher *newTeacher = (Teacher *) malloc(sizeof(Teacher));
    if (!newTeacher) return; // Memory allocation failed

    strcpy(newTeacher->id, id);
    strcpy(newTeacher->name, name);
    newTeacher->role = role;
    strcpy(newTeacher->gender, gender);
    strcpy(newTeacher->password, password);
    newTeacher->next = NULL;

    if (*head == NULL) {
        *head = newTeacher;
    } else {
        Teacher *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTeacher;
    }
}

int importTeachers(Teacher **head) {
    char id[20], name[50], gender[5], password[50];
    int role = 2;

    while (1) {
        displayImportTeacherPrompt();
        getInput(id, 20);
        if (strcmp(id, "back") == 0) break;
        if (scanf("%s %s %s", name, gender, password) != 3) {
            return -1;
        }
        if (strcmp(gender, "Male") != 0 && strcmp(gender, "Female") != 0) {
            displayImportTeacherError(0);
            continue;
        }
        addTeacher(head, id, name, role, gender, password);
    }
    return 1;
}

Teacher *loadTeachersFromFile(const char *filename) {
    Teacher *head = NULL;
    Teacher **tail = &head;

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    char id[10], name[50], gender[10], password[50];
    int role;
    while (fscanf(file, "%9s %49s %9s %49s %d\n", id, name, gender, password, &role) == 5) {
        addTeacher(tail, id, name, role, gender, password);
        tail = &(*tail)->next;
    }

    fclose(file);
    return head;
}

void freeTeachers(Teacher **head) {
    Teacher *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

Teacher *findTeacherByID(Teacher *head, const char *id) {
    Teacher *current = head;
    while (current != NULL) {
        if (strcmp(current->id, id) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void saveTeachersToFile(Teacher *head, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    Teacher *current = head;
    while (current != NULL) {
        fprintf(file, "%9s %49s %9s %49s %d\n", current->id, current->name, current->gender, current->password,
                current->role);
        current = current->next;
    }

    fclose(file);
}
