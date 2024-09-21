#include <stdio.h>
#include <string.h>
#include "../src/models/administrator.c"

// Test function for adding an administrator
void test_addAdministrator(void) {
    Administrator *head = NULL;
    addAdministrator(&head, "A001", "管理员", 3, "男", "adminpass");

    if (head != NULL && strcmp(head->id, "A001") == 0 && strcmp(head->name, "管理员") == 0) {
        printf("test_addAdministrator passed\n");
    } else {
        printf("test_addAdministrator failed\n");
    }

    freeAdministrators(&head);
}

// Test function for loading administrators from a file
void test_loadAdministratorsFromFile(void) {
    FILE *file = fopen("test_administrators.txt", "w");
    fprintf(file, "A001 管理员 男 adminpass 3\n");
    fclose(file);

    Administrator *head = loadAdministratorsFromFile("test_administrators.txt");

    if (head != NULL && strcmp(head->id, "A001") == 0 && strcmp(head->name, "管理员") == 0) {
        printf("test_loadAdministratorsFromFile passed\n");
    } else {
        printf("test_loadAdministratorsFromFile failed\n");
    }

    freeAdministrators(&head);
    remove("test_administrators.txt");
}

int main(void) {
    test_addAdministrator();
    test_loadAdministratorsFromFile();
    return 0;
}
