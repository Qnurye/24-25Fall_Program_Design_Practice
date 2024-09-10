#ifndef VAR4_NOTIFICATION_H
#define VAR4_NOTIFICATION_H

typedef struct {
    int notification_id;
    char title[200];
    char *content;
    int teacher_id;
    int class_id;
    char created_at[20];
} Notification;

Notification *create_notification(const char *title, const char *content, int teacher_id, int class_id);

void free_notification(Notification *notification);

int save_notification(Notification *notification);

Notification *get_notification_by_id(int notification_id);

int update_notification(Notification *notification);

int delete_notification(int notification_id);

#endif // VAR4_NOTIFICATION_H
