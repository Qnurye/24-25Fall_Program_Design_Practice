#include "user.h"
#include "../database/database.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

User *create_user(const char *password, const char *sid, UserRole role, const char *name, time_t created_at) {
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

    user->created_at = created_at;

    return user;
}

void free_user(User *user) {
    if (user != NULL) {
        free(user);
    }
}

User *get_user_by_sid(const char *sid) {
    char query[512];
    snprintf(query, sizeof(query), "SELECT * FROM users WHERE sid = '%s' LIMIT 1", sid);

    MYSQL_RES *db_result = db_fetch_results(query);
    if (db_result == NULL) {
        return NULL;
    }

    MYSQL_ROW row = mysql_fetch_row(db_result);
    if (row == NULL) {
        mysql_free_result(db_result);
        return NULL;
    }

    char *endPtr;
    long created_at = strtol(row[4], &endPtr, 10);
    if (*endPtr != '\0' || created_at < 0) {
        mysql_free_result(db_result);
        return NULL;
    }

    UserRole role = strcmp(row[3], "teacher") == 0 ? ROLE_TEACHER : ROLE_STUDENT;
    User *user = create_user(row[1], row[2], role, row[4], (time_t) created_at);

    mysql_free_result(db_result);
    return user;
}
