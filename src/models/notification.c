#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "models/notification.h"

void addNotification(Notification **head, const char *title, const char *content, const char *teacher_name) {
    Notification *newNotification = (Notification *) malloc(sizeof(Notification));
    if (!newNotification) return; // 内存分配失败

    strncpy(newNotification->title, title, sizeof(newNotification->title) - 1);
    newNotification->title[sizeof(newNotification->title) - 1] = '\0';

    strncpy(newNotification->content, content, sizeof(newNotification->content) - 1);
    newNotification->content[sizeof(newNotification->content) - 1] = '\0';

    strncpy(newNotification->teacher_name, teacher_name, sizeof(newNotification->teacher_name) - 1);
    newNotification->teacher_name[sizeof(newNotification->teacher_name) - 1] = '\0';

    // 获取当前日期
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf(newNotification->date, sizeof(newNotification->date), "%04d-%02d-%02d",
             tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    newNotification->next = NULL;

    if (*head == NULL) {
        *head = newNotification;
    } else {
        Notification *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNotification;
    }
}

Notification *loadNotificationsFromFile(const char *filename) {
    Notification *head = NULL;
    Notification **tail = &head;

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open notification file");
        return NULL;
    }

    char title[100];
    char content[500];
    char date[20];
    char teacher_name[50];
    while (fscanf(file, " %[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", title, content, teacher_name, date) == 4) {
        Notification *newNotification = (Notification *) malloc(sizeof(Notification));
        if (!newNotification) continue;

        strncpy(newNotification->title, title, sizeof(newNotification->title) - 1);
        newNotification->title[sizeof(newNotification->title) - 1] = '\0';

        strncpy(newNotification->content, content, sizeof(newNotification->content) - 1);
        newNotification->content[sizeof(newNotification->content) - 1] = '\0';

        strncpy(newNotification->teacher_name, teacher_name, sizeof(newNotification->teacher_name) - 1);
        newNotification->teacher_name[sizeof(newNotification->teacher_name) - 1] = '\0';

        strncpy(newNotification->date, date, sizeof(newNotification->date) - 1);
        newNotification->date[sizeof(newNotification->date) - 1] = '\0';

        newNotification->next = NULL;
        *tail = newNotification;
        tail = &newNotification->next;
    }

    fclose(file);
    return head;
}

void saveNotificationsToFile(Notification *head, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open notification file for writing");
        return;
    }

    Notification *current = head;
    while (current != NULL) {
        fprintf(file, "%s\t%s\t%s\t%s\n", current->title, current->content, current->teacher_name, current->date);
        current = current->next;
    }

    fclose(file);
}

void freeNotifications(Notification **head) {
    Notification *current = *head;
    while (current != NULL) {
        Notification *next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}
