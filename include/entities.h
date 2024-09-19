#ifndef ENTITIES_H
#define ENTITIES_H

typedef struct Student {
    char id[20];
    char name[50];
    char gender[5];
    int role;
    struct Student *next;
} Student;

typedef struct Teacher {
    char id[20];
    char name[50];
    char gender[5];
    int role;
    struct Teacher *next;
} Teacher;

typedef struct Administrator {
    char id[20];
    char name[50];
    char gender[5];
    int role;
    struct Administrator *next;
} Administrator;

#endif
