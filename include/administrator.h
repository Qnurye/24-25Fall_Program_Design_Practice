#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "entities.h"

void Adm_Home(void);

void addAdministrator(Administrator **head, const char *id, const char *name, int role, const char *gender);

void addStudent(Student **head, const char *id, const char *name, int role, const char *gender);

void importStudents(Student **head);

void displayStudents(Student *head);

void freeStudents(Student **head);

void addTeacher(Teacher **head, const char *id, const char *name, int role, const char *gender);

void importTeachers(Teacher **head);

void displayTeachers(Teacher *head);

void freeTeachers(Teacher **head);

#endif
