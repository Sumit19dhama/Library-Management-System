#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int identification(const char* username, const char* password) {
    // Replace these with your actual student credentials
    const char* validUsername = "useradmin";
    const char* validPassword = "passadmin";

    if (strcmp(username, validUsername) == 0 && strcmp(password, validPassword) == 0) {
        return 1; // Authentication successful
    } else {
        return 0; // Authentication failed
    }
}