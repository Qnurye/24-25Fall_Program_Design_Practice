#ifndef LOGIN_VIEW_H
#define LOGIN_VIEW_H

#include <gtk/gtk.h>

GtkWidget* create_login_view(void);
void set_login_callback(void (*callback)(const char*, const char*));

#endif // LOGIN_VIEW_H
