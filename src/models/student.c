//
// Created by qnurye on 24-9-20.
//
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "models/student.h"
#include "views/student.h"

void addStudent(Student **head, const char *id, const char *name, int role, const char *gender, const char *password) {
    Student *newStudent = (Student *) malloc(sizeof(Student));
    if (!newStudent) return; // 内存分配失败  

    strcpy(newStudent->id, id);
    strcpy(newStudent->name, name);
    newStudent->role = role;
    strcpy(newStudent->gender, gender);
    strcpy(newStudent->password, password);
    newStudent->next = NULL;

    if (*head == NULL) {
        *head = newStudent;
    } else {
        Student *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

Student *loadStudentsFromFile(const char *filename) {
    Student *head = NULL;
    Student **tail = &head;

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    char id[20], name[50], gender[5], password[50];
    int role;
    while (fscanf(file, "%s %s %s %s %d\n", id, name, gender, password, &role) == 5) {
        addStudent(tail, id, name, role, gender, password);
        tail = &(*tail)->next;
    }

    fclose(file);
    return head;
}

int importStudents(Student **head) {
    char id[20], name[50], gender[5], password[50];
    int role = 1;

    while (1) {
        displayImportStudentPrompt();
        scanf("%s", id);
        if (strcmp(id, "返回") == 0) break;
        scanf("%s %s %s", name, gender, password);
        if (strcmp(gender, "男") != 0 && strcmp(gender, "女") != 0) {
            displayImportStudentError(0);
            continue; // 跳过当前循环迭代
        }
        addStudent(head, id, name, role, gender, password);
        displayImportStudentSuccess();
    }
    return 1;
}

void freeStudents(Student **head) {
    Student *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next; // 移动头指针到下一个节点
        free(temp); // 释放当前节点的内存
    }
}

Student *findStudentByID(Student *head, const char *id) {
    Student *current = head;
    while (current != NULL) {
        if (strcmp(current->id, id) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void saveStudentsToFile(Student *head, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    Student *current = head;
    while (current != NULL) {
        fprintf(file, "%s %s %s %s %d\n", current->id, current->name, current->gender, current->password,
                current->role);
        current = current->next;
    }

    fclose(file);
}
