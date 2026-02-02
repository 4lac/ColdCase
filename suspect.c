/**
 * suspect.c — Test File for ColdCase
 *
 * This file is NOT part of the main ColdCase tool.
 * It exists only for testing and demonstration purposes.
 * ColdCase uses this file to detect:
 *  - TODO comments
 *  - FIXME notes
 *  - Exposed passwords
 *  - Risky functions like eval
 *  - Deprecated or unused code
 *
 * Do NOT include this file in the main build.
 * Designed for testing by Reyof.
 */

// suspect.c 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: refactor this entire file
// FIXME: memory leak in login()

char *password = "hunter2"; // password exposed

void login() {
    char user[50];
    printf("Enter username: ");
    gets(user); // FIXME: unsafe function
    printf("Welcome, %s\n", user);
}

void run_eval() {
    eval("dangerous_code()"); // risky use of eval
}

void legacy_function() {
    // TODO: remove deprecated logic
    printf("Legacy mode activated\n");
    // FIXME: this function is never called
}

void unused_function() {
    // TODO: implement this
    // FIXME: still empty
}

int main() {
    login();
    run_eval();
    legacy_function();
    // TODO: add error handling
    // password = get_env("ADMIN_PASS"); // password exposure again
    return 0;

}

