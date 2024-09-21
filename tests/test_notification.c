#include <stdio.h>
#include <string.h>
#include "../src/models/notification.c"

// 测试添加通知功能
void test_addNotification(void) {
    Notification *head = NULL;
    addNotification(&head, "测试标题", "测试内容", "赵老师");

    if (head != NULL && strcmp(head->title, "测试标题") == 0 && strcmp(head->content, "测试内容") == 0 &&
        strcmp(head->teacher_name, "赵老师") == 0) {
        printf("test_addNotification passed\n");
    } else {
        printf("test_addNotification failed\n");
    }

    freeNotifications(&head);
}

// 测试从文件加载通知
void test_loadNotificationsFromFile(void) {
    FILE *file = fopen("test_notifications.txt", "w");
    fprintf(file, "测试标题\t测试内容\t赵老师\t2024-04-27\n");
    fclose(file);

    Notification *head = loadNotificationsFromFile("test_notifications.txt");

    if (head != NULL && strcmp(head->title, "测试标题") == 0 && strcmp(head->content, "测试内容") == 0 &&
        strcmp(head->teacher_name, "赵老师") == 0 && strcmp(head->date, "2024-04-27") == 0) {
        printf("test_loadNotificationsFromFile passed\n");
    } else {
        printf("test_loadNotificationsFromFile failed\n");
    }

    freeNotifications(&head);
    remove("test_notifications.txt");
}

int main(void) {
    test_addNotification();
    test_loadNotificationsFromFile();
    return 0;
}
