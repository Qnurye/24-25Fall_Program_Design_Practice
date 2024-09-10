#ifndef VAR4_AUTH_CONTROLLER_H
#define VAR4_AUTH_CONTROLLER_H

#include "../models/user.h"

typedef struct {
    User *user;
    char *error_message;
} AuthResult;

AuthResult *sign_in(const char *sid, const char *password);

void free_auth_result(AuthResult *result);

#endif
