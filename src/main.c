#include <gtk/gtk.h>
#include "views/login_view.h"
#include "controllers/auth_controller.h"
#include "database/database.h"

static void on_login(const char *username, const char *password) {
    AuthResult *result = sign_in(username, password);
    if (result->user) {
        g_print("Login successful for user: %s\n", result->user->name);
        // TODO))
    } else {
        g_print("Login failed: %s\n", result->error_message);
        // TODO))
    }
    free_auth_result(result);
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "教务管理系统");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

    GtkWidget *login_view = create_login_view();
    set_login_callback(on_login);

    gtk_window_set_child(GTK_WINDOW(window), login_view);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv) {
    g_print("Connecting to DB\n");
    if (!db_connect()) {
        g_print("Connecting failed\n");
    }
    GtkApplication *app = gtk_application_new("com.Var4.system", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    g_print("Disconnecting from DB");
    db_disconnect();
    
    return status;
}
