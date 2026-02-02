#include "coldcase.h"


void scan_file_for_issues( ColdCaseFile *case_file){
    
    // ColdCase enters the digital scene, opening the file like the door to an interrogation room

    FILE *opfile = fopen(case_file->filename, "r");

    // If the door is locked, the investigation halts and the lead detective is notified

if (opfile == NULL) {
    fprintf(stderr, "\033[1;31mColdCase Error: Unable to access file '%s'. Investigation aborted.\033[0m\n", case_file->filename);
    return;
}

// The investigation begins line by line—each line could be evidence or just noise

    char line[LINE_BUFFER_SIZE];
    int current_line_number = 1;

     while(fgets(line,sizeof(line),opfile)){
        IssueType_t type = ISSUE_UNKNOWN;

         // Searching for suspicious traces: TODOs, exposed passwords, or risky eval instructions

        if (strstr(line,"TODO")){
            type=ISSUE_TODO;
        }else if(strstr(line,"password")){
            type=ISSUE_PASSWORD;
        }else if(strstr(line,"eval")){
            type=ISSUE_EVAL;
        }else if(strstr(line,"FIXME")){
            type=ISSUE_FIXME;
        }
        // If evidence is found, it’s logged into the case file with its line number and classification

        if(type!=ISSUE_UNKNOWN && case_file->issue_count<MAX_ISSUES){

            Issue_t *issue = &case_file->issues[case_file->issue_count];
            issue->line_number = current_line_number;
            issue->type = type;
            strcpy(issue->content, line);
            case_file->issue_count++;
        }
        // Move to the next line—the investigation continues

        current_line_number++;
    }
// The investigation concludes. ColdCase closes the file and exits the scene

    fclose(opfile);
};
