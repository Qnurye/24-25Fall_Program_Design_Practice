#include "user.h"
#include <stdlib.h>
#include <string.h>

User *create_user(const char *password, const char *sid, UserRole role, const char *name) {
    User *user = malloc(sizeof(User));
    if (user == NULL) {
        return NULL;
    }

    strncpy(user->password, password, sizeof(user->password) - 1);
    user->password[sizeof(user->password) - 1] = '\0';

    strncpy(user->sid, sid, sizeof(user->sid) - 1);
    user->sid[sizeof(user->sid) - 1] = '\0';

    user->role = role;

    strncpy(user->name, name, sizeof(user->name) - 1);
    user->name[sizeof(user->name) - 1] = '\0';

    user->created_at = time(NULL);

    return user;
}

void free_user(User *user) {
    if (user != NULL) {
        free(user);
    }
}
