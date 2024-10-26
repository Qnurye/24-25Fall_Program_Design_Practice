#include <stdio.h>
#include "controllers/notification_controller.h"
#include "utils/display.h"

void publishNotification(Notification **notificationsHead, const char *title, const char *content,
                         const char *teacher_name) {
    addNotification(notificationsHead, title, content, teacher_name);
    saveNotificationsToFile(*notificationsHead, "data/notifications.txt");
    printColored(GREEN, "Notification published successfully.\n");
}

void displayNotifications(Notification *notificationsHead) {
    clearScreen();
    printHeader("Published Notifications");

    if (notificationsHead == NULL) {
        printColored(RED, "No notifications published.\n");
    } else {
        Notification *current = notificationsHead;
        while (current != NULL) {
            printf("Title: %s\n", current->title);
            printf("Content: %s\n", current->content);
            printf("Published by: %s\n", current->teacher_name);
            printf("Date: %s\n", current->date);
            printf("-----------------------------\n");
            current = current->next;
        }
    }
    anyKey();
}
