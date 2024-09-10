#ifndef VAR4_USER_H
#define VAR4_USER_H

#include <time.h>

typedef enum {
    ROLE_TEACHER,
    ROLE_STUDENT
} UserRole;

typedef struct {
    int user_id;
    char password[256];
    char sid[11];
    UserRole role;
    char name[101];
    time_t created_at;
} User;

User *create_user(const char *password, const char *sid, UserRole role, const char *name);

void free_user(User *user);

int save_user(User *user);

User *get_user_by_id(int user_id);

User *get_user_by_sid(const char *sid);

int update_user(User *user);

int delete_user(int user_id);

#endif //VAR4_USER_H
