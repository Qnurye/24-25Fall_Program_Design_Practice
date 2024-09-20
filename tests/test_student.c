#include <stdio.h>
#include <string.h>
#include "../src/models/student.c"

// Test function for adding a student
void test_addStudent() {
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
void test_loadStudentsFromFile() {
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

int main() {
    test_addStudent();
    test_loadStudentsFromFile();
    return 0;
}
