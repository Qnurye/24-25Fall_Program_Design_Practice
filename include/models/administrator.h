#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "student.h"
#include "teacher.h"

typedef struct Administrator {
    char id[20];
    char name[50];
    char gender[5];
    int role;
    struct Administrator *next;
} Administrator;

Administrator *loadAdministratorsFromFile(const char *filename);

void addAdministrator(Administrator **head, const char *id, const char *name, int role, const char *gender);

Administrator *findAdministratorByID(Administrator *head, const char *id);

#endif
