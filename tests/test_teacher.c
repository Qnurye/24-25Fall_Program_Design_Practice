#include <stdio.h>
#include <string.h>
#include "../src/models/teacher.c"

// Test function for adding a teacher
void test_addTeacher() {
    Teacher *head = NULL;
    addTeacher(&head, "T001", "赵老师", 2, "女", "teacherpass1");

    if (head != NULL && strcmp(head->id, "T001") == 0 && strcmp(head->name, "赵老师") == 0) {
        printf("test_addTeacher passed\n");
    } else {
        printf("test_addTeacher failed\n");
    }

    freeTeachers(&head);
}

// Test function for loading teachers from file
void test_loadTeachersFromFile() {
    FILE *file = fopen("test_teachers.txt", "w");
    fprintf(file, "T001 赵老师 女 teacherpass1 2\n");
    fclose(file);

    Teacher *head = loadTeachersFromFile("test_teachers.txt");

    if (head != NULL && strcmp(head->id, "T001") == 0 && strcmp(head->name, "赵老师") == 0) {
        printf("test_loadTeachersFromFile passed\n");
    } else {
        printf("test_loadTeachersFromFile failed\n");
    }

    freeTeachers(&head);
    remove("test_teachers.txt");
}

int main() {
    test_addTeacher();
    test_loadTeachersFromFile();
    return 0;
}
