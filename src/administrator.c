#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/entities.h"
#include "../include/administrator.h"

void Adm_Home(void) {
    printf("\n");
    printf("*****************************************\n");
    printf("***            管理员主页             ***\n");
    printf("*****************************************\n");
    printf("\n");

    printf("    1. 导入学生信息\n");
    printf("    2. 导入教师信息\n");
    printf("    3. 显示当前所有学生信息\n");
    printf("    4. 显示当前所有教师信息\n");
    printf("    5. 清空当前所有学生信息\n");
    printf("    6. 清空当前所有教师信息\n");
    printf("    7. 退出\n");

    printf("\n");
    printf("请选择一个选项（输入对应的数字后按回车键）：");
}

void addAdministrator(Administrator **head, const char *id, const char *name, int role, const char *gender) {
    Administrator *newAdministrator = (Administrator *) malloc(sizeof(Administrator));
    if (!newAdministrator) return; // 内存分配失败  

    strcpy(newAdministrator->id, id);
    strcpy(newAdministrator->name, name);
    newAdministrator->role = role;
    strcpy(newAdministrator->gender, gender);
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

void displayStudents(Student *head) {
    Student *current = head;
    if (current == NULL) {
        printf("No students to display.\n");
    }

    while (current != NULL) {
        printf("学号: %s, 姓名: %s,性别: %s\n",
               current->id, current->name, current->gender);

        current = current->next;
    }
    printf("1.返回\n");
}

void displayTeachers(Teacher *head) {
    Teacher *current = head;
    if (current == NULL) {
        printf("No Teachers to display.\n");
    }

    while (current != NULL) {
        printf("工号: %s, 姓名: %s,性别: %s\n",
               current->id, current->name, current->gender);

        current = current->next;
    }
    printf("1.返回\n");
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

void freeTeachers(Teacher **head) {
    Teacher *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next; // 移动头指针到下一个节点  
        free(temp); // 释放当前节点的内存  
    }
    printf("已成功清除所有教师信息\n1.返回\n");
}
