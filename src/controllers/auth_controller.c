#include "auth_controller.h"
#include "../database/database.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

AuthResult *sign_in(const char *sid, const char *password) {
    AuthResult *result = malloc(sizeof(AuthResult));
    result->user = NULL;
    result->error_message = NULL;

    if (sid == NULL || password == NULL || strlen(sid) == 0 || strlen(password) == 0) {
        result->error_message = strdup("Invalid input: SID and password are required.");
        return result;
    }

    char query[512];
    snprintf(query, sizeof(query), "SELECT * FROM users WHERE sid = '%s' LIMIT 1", sid);
    
    MYSQL_RES *db_result = db_fetch_results(query);
    if (db_result == NULL) {
        result->error_message = strdup("Database error occurred.");
        return result;
    }

    MYSQL_ROW row = mysql_fetch_row(db_result);
    if (row == NULL) {
        result->error_message = strdup("User not found.");
        mysql_free_result(db_result);
        return result;
    }

    // Verify password (Note: In a real application, use secure password hashing)
    if (strcmp(row[1], password) != 0) {
        result->error_message = strdup("Incorrect password.");
        mysql_free_result(db_result);
        return result;
    }

    // Create a user object
    UserRole role = strcmp(row[3], "teacher") == 0 ? ROLE_TEACHER : ROLE_STUDENT;
    result->user = create_user(row[1], row[2], role, row[4]);

    mysql_free_result(db_result);
    return result;
}

void free_auth_result(AuthResult *result) {
    if (result) {
        if (result->user) {
            free_user(result->user);
        }
        if (result->error_message) {
            free(result->error_message);
        }
        free(result);
    }
}
