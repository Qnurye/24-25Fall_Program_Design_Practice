#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "models/administrator.h"

void addAdministrator(Administrator **head, const char *id, const char *name, int role, const char *gender, const char *password) {
    Administrator *newAdministrator = (Administrator *) malloc(sizeof(Administrator));
    if (!newAdministrator) return; // 内存分配失败  

    strcpy(newAdministrator->id, id);
    strcpy(newAdministrator->name, name);
    newAdministrator->role = role;
    strcpy(newAdministrator->gender, gender);
    strcpy(newAdministrator->password, password);
    newAdministrator->next = NULL;

    if (*head == NULL) {
        *head = newAdministrator;
    } else {
        Administrator *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newAdministrator;
    }
}

Administrator *loadAdministratorsFromFile(const char *filename) {
    Administrator *head = NULL;
    Administrator **tail = &head;

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    char id[20], name[50], gender[5], password[50];
    int role;
    while (fscanf(file, "%s %s %s %s %d\n", id, name, gender, password, &role) == 5) {
        addAdministrator(tail, id, name, role, gender, password);
        tail = &(*tail)->next;
    }

    fclose(file);
    return head;
}

Administrator *findAdministratorByID(Administrator *head, const char *id) {
    Administrator *current = head;
    while (current != NULL) {
        if (strcmp(current->id, id) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void freeAdministrators(Administrator **head) {
    Administrator *current = *head;
    while (current != NULL) {
        Administrator *next = current->next;
        free(current);
        current = next;
    }
}
