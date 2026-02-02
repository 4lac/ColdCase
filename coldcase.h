#ifndef COLDCASE_H
#define COLDCASE_H
/**
 * ColdCase — Digital Forensics Tool
 * Designed and narrated by Ruyuf.
 */
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <limits.h>



#define MAX_ISSUES 100
#define LINE_BUFFER_SIZE 1024

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif


/**
 * @brief This function scans each line like a detective,
 * searching for traces of unfinished work—those lingering TODOs
 * left behind in the rush of code.
 */
typedef enum {
    ISSUE_TODO, // Unfinished task
    ISSUE_PASSWORD, // Sensitive data
    ISSUE_EVAL, // Risky function
    ISSUE_FIXME,// Known bug
    ISSUE_UNKNOWN,// Unclassified issue
}IssueType_t;

/**
 * @brief Represents a single suspicious line found during file investigation.
 *
 * Each Issue_t is a digital clue—captured from a specific line in the file,
 * classified by type (TODO, password, eval, FIXME), and stored with its full content.
 * It contributes to the forensic profile of the file, helping ColdCase build its report.
 *
 * @field line_number The line in the file where the issue was found.
 * @field type Classification of the issue (e.g., TODO, password exposure).
 * @field content The full text of the suspicious line.
 */
typedef struct  {
    int line_number;
    IssueType_t type;      
    char content[1024]; 
     // 0 = fail, 1 = success

}Issue_t;


/**
 * ColdCaseFile - A digital case folder.
 * @brief It holds every suspicious line, every forgotten trace,
 * waiting to be reopened and investigated.
 */
typedef struct {
char filename[PATH_MAX];
int file_size;
int file_age;
time_t last_modified;
int issue_count;
char status[100];
Issue_t issues[MAX_ISSUES]; 
int read_success;


}ColdCaseFile;
#include "scanner.h"
#include "metadata.h"
#include "status.h"
#include "report.h"

#endif


