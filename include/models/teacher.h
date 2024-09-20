//
// Created by qnurye on 24-9-20.
//

#ifndef VAR4_TEACHER_H
#define VAR4_TEACHER_H

typedef struct Teacher {
    char id[20];
    char name[50];
    char gender[5];
    char password[50];
    int role;
    struct Teacher *next;
} Teacher;

void saveTeachersToFile(Teacher *head, const char *filename);

Teacher *loadTeachersFromFile(const char *filename);

void addTeacher(Teacher **head, const char *id, const char *name, int role, const char *gender, const char *password);

int importTeachers(Teacher **head);

void displayTeachers(Teacher *head);

void freeTeachers(Teacher **head);

Teacher *findTeacherByID(Teacher *head, const char *id);

#endif //VAR4_TEACHER_H
