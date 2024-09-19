//
// Created by qnurye on 24-9-20.
//
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "models/student.h"

void addStudent(Student **head, const char *id, const char *name, int role, const char *gender) {
    Student *newStudent = (Student *) malloc(sizeof(Student));
    if (!newStudent) return; // 内存分配失败  

    strcpy(newStudent->id, id);
    strcpy(newStudent->name, name);
    newStudent->role = role;
    strcpy(newStudent->gender, gender);
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

    char id[20], name[50], gender[5];
    int role;
    while (fscanf(file, "%19s %49s %4s %d\n", id, name, gender, &role) == 4) {
        addStudent(tail, id, name, role, gender);
        tail = &(*tail)->next;
    }

    fclose(file);
    return head;
}

void importStudents(Student **head) {
    char id[20], name[50], gender[5];
    int role = 1;

    while (1) {
        printf("请输入学生信息（学号 姓名 男/女）：(输入“返回”可返回主菜单）\n");
        scanf("%19s", id);
        if (strcmp(id, "返回") == 0) break;
        scanf("%49s %4s", name, gender);
        if (strcmp(gender, "男") != 0 && strcmp(gender, "女") != 0) {
            printf("性别输入错误，请输入'男'或'女'。\n");
            continue; // 跳过当前循环迭代
        }
        addStudent(head, id, name, role, gender);
        printf("已成功添加一名学生\n");
    }
}

void freeStudents(Student **head) {
    Student *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next; // 移动头指针到下一个节点
        free(temp); // 释放当前节点的内存
    }
    printf("已成功清除所有学生信息\n1.返回\n");
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

void saveStudentsToFile(Student *head, const char *filename) {}
