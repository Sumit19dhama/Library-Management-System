#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char username[100];
    char password[100];
    int booksIssued;
    struct User* next;
};

typedef struct User User;
int identificationuser(const char* username, const char* password);

int identificationuser(const char* username, const char* password) {
    // Replace these with your actual student credentials
    const char* validUsername = "user";
    const char* validPassword = "pass";

    if (strcmp(username, validUsername) == 0 && strcmp(password, validPassword) == 0) {
        return 1; // Authentication successful
    } else {
        return 0; // Authentication failed
    }
}