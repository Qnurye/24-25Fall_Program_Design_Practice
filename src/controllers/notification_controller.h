#ifndef VAR4_NOTIFICATION_CONTROLLER_H
#define VAR4_NOTIFICATION_CONTROLLER_H

#include "../models/notification.h"

typedef struct {
    int success;
    char *message;
} NotificationResult;

NotificationResult *publish_notification(int teacher_id, int class_id, const char *title, const char *content);

void free_notification_result(NotificationResult *result);

Notification **get_student_notifications(int student_id, int *count);

void free_notification_list(Notification **notifications, int count);

#endif // VAR4_NOTIFICATION_CONTROLLER_H
