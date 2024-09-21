#include <stdio.h>
#include "controllers/notification_controller.h"
#include "utils/display.h"

void publishNotification(Notification **notificationsHead, const char *title, const char *content,
                         const char *teacher_name) {
    addNotification(notificationsHead, title, content, teacher_name);
    saveNotificationsToFile(*notificationsHead, "notifications.txt");
    printColored(GREEN, "通知已成功发布。\n");
}

void displayNotifications(Notification *notificationsHead) {
    clearScreen();
    printHeader("发布的通知");

    if (notificationsHead == NULL) {
        printColored(RED, "没有发布的通知。\n");
    } else {
        Notification *current = notificationsHead;
        while (current != NULL) {
            printf("标题: %s\n", current->title);
            printf("内容: %s\n", current->content);
            printf("发布教师: %s\n", current->teacher_name);
            printf("日期: %s\n", current->date);
            printf("-----------------------------\n");
            current = current->next;
        }
    }
    anyKey();
}
