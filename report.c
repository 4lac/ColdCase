#include <stdio.h>
#include "coldcase.h"
#include "scanner.h"

// ColdCase begins presenting the final investigation report
void print_report(const ColdCaseFile *case_file) {
    //printf("\033[5;31mColdCase Investigation Report\n\033[0m");
    printf("\033[38;5;123m ICE Tools - ColdCase Report\n\033[0m");
    // Basic metadata — the file’s identity and history
    printf("\033[38;5;123m File:\033[0m%s\n ", case_file->filename);
    printf("\033[38;5;123mSize:\033[0m %d bytes\n", case_file->file_size);
    printf("\033[38;5;123m Last Modified:\033[0m %s", ctime(&case_file->last_modified));
    printf("\033[38;5;123m Issues Found:\033[0m %d\n", case_file->issue_count);
    printf("\033[38;5;123m Status:\033[0m %s\n", case_file->status);
    printf("____________________________________________\n");

// Loop through each issue and narrate its details
    for (int i = 0; i < case_file->issue_count; i++) {
        
        const Issue_t *issue = &case_file->issues[i];

        const char *type_str = "";

        switch (issue->type) {
            case ISSUE_TODO:     type_str = "TODO"; break;
            case ISSUE_PASSWORD: type_str = "Password Exposure"; break;
            case ISSUE_EVAL:     type_str = "Use of eval"; break;
            case ISSUE_FIXME:    type_str = "FIXME"; break;
            default:             type_str = "Unknown"; break;
        }

    
        const char *color = "\033[0m"; // Reset
         if (issue->type == ISSUE_TODO)       color = "\033[38;5;153m"; // Ice Blue
          else if (issue->type == ISSUE_PASSWORD) color = "\033[1;34m"; // Deep Freeze
          else if (issue->type == ISSUE_EVAL)     color = "\033[1;35m"; // Magenta
          else if (issue->type == ISSUE_FIXME)    color = "\033[1;36m"; // Cyan
        // Color-coded presentation based on severity
        printf("%sIssue #%d\n", color, i + 1);
        printf("Line: %d\n", issue->line_number);
        printf("Type: %s\n", type_str);
        printf("Content: %s\033[0m\n", issue->content); 
        // Reset formatting after each issue
        printf("____________________________________________\n");
    }
        // Final verdict — either clean or documented
    if (case_file->issue_count == 0) {
    printf("\033[38;5;123m No anomalies detected. File integrity preserved.\033[0m\n");
    printf("\n\033[1;36mCase frozen by RUYUF.\033[0m\n");
} else {
    printf("\033[1;33mEnd of report. %d issue(s) documented.\033[0m\n", case_file->issue_count);
    printf("\n\033[1;36mCase closed.\nDigital signature: ICE Tools Division..\033[0m\n");
}
};