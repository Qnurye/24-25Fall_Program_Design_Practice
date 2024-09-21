#ifndef NOTIFICATION_H
#define NOTIFICATION_H

typedef struct Notification {
    char title[100];
    char content[500];
    char date[20];          // 格式：YYYY-MM-DD
    char teacher_name[50];  // 发布通知的教师姓名
    struct Notification *next;
} Notification;

// 加载通知数据
Notification *loadNotificationsFromFile(const char *filename);

// 保存通知数据
void saveNotificationsToFile(Notification *head, const char *filename);

// 添加新的通知
void addNotification(Notification **head, const char *title, const char *content, const char *teacher_name);

// 释放通知链表
void freeNotifications(Notification **head);

#endif // NOTIFICATION_H
