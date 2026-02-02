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