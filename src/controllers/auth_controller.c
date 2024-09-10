#include "auth_controller.h"
#include <string.h>
#include <stdlib.h>

AuthResult *sign_in(const char *sid, const char *password) {
    AuthResult *result = malloc(sizeof(AuthResult));
    result->user = NULL;
    result->error_message = NULL;

    if (sid == NULL || password == NULL || strlen(sid) == 0 || strlen(password) == 0) {
        result->error_message = strdup("Invalid input: SID and password are required.");
        return result;
    }

    User user = *get_user_by_sid(sid);

    if (strcmp(user.password, password) != 0) {
        result->error_message = strdup("Incorrect password.");
        free_user(&user);
        return result;
    }

    result->user = &user;
    free_user(&user);
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
