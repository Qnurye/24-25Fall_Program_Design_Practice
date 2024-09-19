//
// Created by qnurye on 24-9-20.
//

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "models/teacher.h"

void addTeacher(Teacher **head, const char *id, const char *name, int role, const char *gender) {
    Teacher *newTeacher = (Teacher *) malloc(sizeof(Teacher));
    if (!newTeacher) return; // 内存分配失败  

    strcpy(newTeacher->id, id);
    strcpy(newTeacher->name, name);
    newTeacher->role = role;
    strcpy(newTeacher->gender, gender);
    newTeacher->next = NULL;

    if (*head == NULL) {
        *head = newTeacher;
    } else {
        Teacher *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTeacher;
    }
}

void importTeachers(Teacher **head) {
    char id[20], name[50], gender[5];
    int role = 2;

    while (1) {
        printf("请输入教师信息（工号 姓名 男/女）：(输入“返回”可返回主菜单）\n");
        scanf("%19s", id);
        if (strcmp(id, "返回") == 0) break;
        scanf("%49s %4s", name, gender);
        if (strcmp(gender, "男") != 0 && strcmp(gender, "女") != 0) {
            printf("性别输入错误，请输入'男'或'女'。\n");
            continue; // 跳过当前循环迭代  
        }
        addTeacher(head, id, name, role, gender);
        printf("已成功添加一名教师\n");
    }
}

Teacher *loadTeachersFromFile(const char *filename) {
    Teacher *head = NULL;
    Teacher **tail = &head;

    FILE *file = fopen(filename, "r");
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

void freeTeachers(Teacher **head) {
    Teacher *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next; // 移动头指针到下一个节点
        free(temp); // 释放当前节点的内存
    }
    printf("已成功清除所有教师信息\n1.返回\n");
}

Teacher *findTeacherByID(Teacher *head, const char *id) {
    Teacher *current = head;
    while (current != NULL) {
        if (strcmp(current->id, id) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}


void saveTeachersToFile(Teacher *head, const char *filename) {}
