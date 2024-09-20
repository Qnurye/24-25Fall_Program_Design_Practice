#ifndef LOGIN_VIEW_H
#define LOGIN_VIEW_H

void display_login_screen(void);
void display_password_prompt(void);
void display_login_success(const char *role);
void display_login_failure(const char *reason);
void end_password_input(void);

#endif
