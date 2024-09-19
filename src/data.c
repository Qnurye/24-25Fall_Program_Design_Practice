#include <stdio.h>

#include "../include/entities.h"
#include "../include/data.h"
#include "../include/administrator.h"

Student* loadStudentsFromFile(const char* filename) {
    Student* head = NULL;
    Student** tail = &head;

    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    char id[20], name[50], gender[5];
    int role;
    while (fscanf(file, "%19s %49s %4s %d\n", id, name, gender, &role) == 4) {
        addStudent(tail, id, name, role, gender);
        tail = &(*tail)->next;
    }

    fclose(file);
    return head;
}

Teacher* loadTeachersFromFile(const char* filename) {
    Teacher* head = NULL;
    Teacher** tail = &head;

    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    char id[20], name[50], gender[5];
    int role;
    while (fscanf(file, "%19s %49s %4s %d\n", id, name, gender, &role) == 4) {
        addTeacher(tail, id, name, role, gender);
        tail = &(*tail)->next;
    }

    fclose(file);
    return head;
}

Administrator* loadAdministratorsFromFile(const char* filename) {
    Administrator* head = NULL;
    Administrator** tail = &head;

    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    char id[20], name[50], gender[5];
    int role;
    while (fscanf(file, "%19s %49s %4s %d\n", id, name, gender, &role) == 4) {
        addAdministrator(tail, id, name, role, gender);
        tail = &(*tail)->next;
    }

    fclose(file);
    return head;
}
