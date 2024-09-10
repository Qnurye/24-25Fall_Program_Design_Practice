#include <gtk/gtk.h>

static void (*login_callback)(const char*, const char*);

static void on_login_button_clicked(GtkWidget *widget, gpointer data) {
    GtkEntry *username_entry = GTK_ENTRY(g_object_get_data(G_OBJECT(widget), "username_entry"));
    GtkEntry *password_entry = GTK_ENTRY(g_object_get_data(G_OBJECT(widget), "password_entry"));

    const char *username = gtk_editable_get_text(GTK_EDITABLE(username_entry));
    const char *password = gtk_editable_get_text(GTK_EDITABLE(password_entry));

    if (login_callback) {
        login_callback(username, password);
    }
}

GtkWidget* create_login_view(void) {
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_widget_set_margin_start(vbox, 20);
    gtk_widget_set_margin_end(vbox, 20);
    gtk_widget_set_margin_top(vbox, 20);
    gtk_widget_set_margin_bottom(vbox, 20);

    GtkWidget *logo_label = gtk_label_new("Var4 System");
    PangoAttrList *attr_list = pango_attr_list_new();
    PangoAttribute *attr = pango_attr_weight_new(PANGO_WEIGHT_BOLD);
    pango_attr_list_insert(attr_list, attr);
    attr = pango_attr_scale_new(1.5);
    pango_attr_list_insert(attr_list, attr);
    gtk_label_set_attributes(GTK_LABEL(logo_label), attr_list);
    pango_attr_list_unref(attr_list);
    gtk_box_append(GTK_BOX(vbox), logo_label);

    GtkWidget *spacer = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_size_request(spacer, -1, 20);
    gtk_box_append(GTK_BOX(vbox), spacer);

    GtkWidget *username_entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(username_entry), "学/工号");
    gtk_box_append(GTK_BOX(vbox), username_entry);

    GtkWidget *password_entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(password_entry), "密码");
    gtk_entry_set_visibility(GTK_ENTRY(password_entry), FALSE);
    gtk_box_append(GTK_BOX(vbox), password_entry);

    GtkWidget *login_button = gtk_button_new_with_label("登录");
    gtk_box_append(GTK_BOX(vbox), login_button);

    g_object_set_data(G_OBJECT(login_button), "username_entry", username_entry);
    g_object_set_data(G_OBJECT(login_button), "password_entry", password_entry);

    g_signal_connect(login_button, "clicked", G_CALLBACK(on_login_button_clicked), NULL);

    return vbox;
}

void set_login_callback(void (*callback)(const char*, const char*)) {
    login_callback = callback;
}
