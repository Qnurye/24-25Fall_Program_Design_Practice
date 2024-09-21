#ifndef NOTIFICATION_CONTROLLER_H
#define NOTIFICATION_CONTROLLER_H

#include "models/notification.h"

void
publishNotification(Notification **notificationsHead, const char *title, const char *content, const char *teacher_name);

void displayNotifications(Notification *notificationsHead);

#endif // NOTIFICATION_CONTROLLER_H
