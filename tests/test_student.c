#include <stdio.h>
#include <string.h>
#include "../src/models/student.c"

// Test function for adding a student
void test_addStudent(void) {
    Student *head = NULL;
    addStudent(&head, "2023001", "张三", 1, "男", "password123");

    if (head != NULL && strcmp(head->id, "2023001") == 0 && strcmp(head->name, "张三") == 0) {
        printf("test_addStudent passed\n");
    } else {
        printf("test_addStudent failed\n");
    }

    freeStudents(&head);
}

// Test function for loading students from file
void test_loadStudentsFromFile(void) {
    FILE *file = fopen("test_students.txt", "w");
    fprintf(file, "2023001 张三 男 password123 1\n");
    fclose(file);

    Student *head = loadStudentsFromFile("test_students.txt");

    if (head != NULL && strcmp(head->id, "2023001") == 0 && strcmp(head->name, "张三") == 0) {
        printf("test_loadStudentsFromFile passed\n");
    } else {
        printf("test_loadStudentsFromFile failed\n");
    }

    freeStudents(&head);
    remove("test_students.txt");
}

// Test function for finding a student by ID
void test_findStudentByID(void) {
    Student *head = NULL;
    addStudent(&head, "2023001", "张三", 1, "男", "password123");
    addStudent(&head, "2023002", "李四", 1, "女", "password456");

    Student *found = findStudentByID(head, "2023001");
    if (found != NULL && strcmp(found->name, "张三") == 0) {
        printf("test_findStudentByID passed\n");
    } else {
        printf("test_findStudentByID failed\n");
    }

    found = findStudentByID(head, "2023003");
    if (found == NULL) {
        printf("test_findStudentByID (not found) passed\n");
    } else {
        printf("test_findStudentByID (not found) failed\n");
    }

    freeStudents(&head);
}

int main(void) {
    test_addStudent();
    test_loadStudentsFromFile();
    test_findStudentByID();
    return 0;
}
