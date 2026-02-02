/**
 * warmcase.c — Test File for ColdCase
 *
 * This file is NOT part of the main ColdCase tool.
 * It is used only for testing how ColdCase detects:
 *  - TODO comments
 *  - FIXME notes
 *  - Simple function structures
 *  - Basic input/output patterns
 *
 * This file should NOT be included in the main build.
 * Designed for testing by Reyof.
 */
// warmcase.c 

#include <stdio.h>
#include <stdlib.h>

// TODO: improve input validation

void greet_user(const char *name) {
    printf("Welcome, %s!\n", name);
}

void process_data() {
    // FIXME: handle empty input case
    printf("Processing data...\n");
}

int main() {
    greet_user("Riyouf");
    process_data();
    return 0;

}
