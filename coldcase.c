#include <stdio.h>
#include <string.h>
#include "coldcase.h"

int main() {
    ColdCaseFile case_file;
    char input_filename[PATH_MAX];

  // The investigation begins—ColdCase prompts the user for a target file
    printf("\033[1;36mEnter the name of the file to investigate: \033[0m");
    if (fgets(input_filename, sizeof(input_filename), stdin) == NULL) {
        // Input failed—case dismissed before it even began
        fprintf(stderr, "\033[1;31mError: Failed to read input. Investigation aborted.\033[0m\n");
        return 1;
    }

   // Clean the filename—strip trailing newline
    input_filename[strcspn(input_filename, "\n")] = '\0';

    // Prepare the case folder with the suspect file
    strcpy(case_file.filename, input_filename);
    case_file.issue_count = 0;

    // Retrieve metadata—size, age, and last known activity
    fill_metadata(&case_file);
    if (!case_file.read_success) {

    // File resisted access—ColdCase cannot proceed
        printf("\033[1;31mColdCase Error: Unable to access file '%s'. Investigation aborted.\033[0m\n", case_file.filename);
        return 1;
    }
    // Begin forensic sweep—scan for anomalies line by line
    scan_file_for_issues(&case_file);

    // Present the final report—findings, verdict, and closure
    print_report(&case_file);

    return 0;
}