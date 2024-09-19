//
// Created by qnurye on 24-9-20.
//

#ifndef VAR4_STUDENT_H
#define VAR4_STUDENT_H

typedef struct Student {
    char id[20];
    char name[50];
    char gender[5];
    int role;
    struct Student *next;
} Student;

Student *loadStudentsFromFile(const char *filename);

void saveStudentsToFile(Student *head, const char *filename);

void addStudent(Student **head, const char *id, const char *name, int role, const char *gender);

void importStudents(Student **head);

void displayStudents(Student *head);

void freeStudents(Student **head);

Student *findStudentByID(Student *head, const char *id);

#endif //VAR4_STUDENT_H
