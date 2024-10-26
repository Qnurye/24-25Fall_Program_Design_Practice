#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "models/classroom.h"

void addClassroom(Classroom **head, const char *name, int capacity) {
    Classroom *newClassroom = (Classroom *) malloc(sizeof(Classroom));
    if (!newClassroom) return;

    static int next_id = 1;
    newClassroom->id = next_id++;
    strncpy(newClassroom->name, name, sizeof(newClassroom->name) - 1);
    newClassroom->name[sizeof(newClassroom->name) - 1] = '\0';
    newClassroom->capacity = capacity;
    newClassroom->next = NULL;

    if (*head == NULL) {
        *head = newClassroom;
    } else {
        Classroom *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newClassroom;
    }
}

Classroom *loadClassroomsFromFile(const char *filename) {
    Classroom *head = NULL;
    Classroom **tail = &head;

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open classroom file");
        return NULL;
    }

    char name[50];
    int capacity;
    while (fscanf(file, "%49s %d\n", name, &capacity) == 2) {
        addClassroom(tail, name, capacity);
        tail = &(*tail)->next;
    }

    fclose(file);
    return head;
}

void saveClassroomsToFile(Classroom *head, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open classroom file for writing");
        return;
    }

    Classroom *current = head;
    while (current != NULL) {
        fprintf(file, "%s %d\n", current->name, current->capacity);
        current = current->next;
    }

    fclose(file);
}

Classroom *findClassroomByName(Classroom *head, const char *name) {
    Classroom *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

Classroom *findClassroomById(Classroom *head, int id) {
    Classroom *current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void freeClassrooms(Classroom **head) {
    Classroom *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
