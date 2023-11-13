#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 5
#define MAX_USERNAME_LENGTH 10
#define MAX_PASSWORD_LENGTH 10

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    union {
        int flag;
        struct {
            unsigned int active: 1;
        };
    };
};

struct User users[MAX_USERS];
int Count = 0;

void registe() {
    if (Count >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    printf("Enter a username: ");
    scanf("%s", users[Count].username);

    printf("Enter a password: ");
    scanf("%s", users[Count].password);

    printf("Enter 1 for active or 0 for inactive: ");
    scanf("%d", users[Count].active);

    Count++;

    printf("You registered successfully.\n");
}

void login() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    int i = 0;
    while (i < Count) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            if (users[i].active) {
                printf("Login successful.\n");
            } else {
                printf("Account is inactive. Please contact support.\n");
            }
            return;
        }
        i++;
    }

    printf("Invalid Try Again!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            registe();
        } else if (choice == 2) {
            login();
        } else if (choice == 3) {
            printf("Exiting.\n");
            break; // انهاء البرنامج
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
