
#include "coldcase.h"


// ColdCase begins its forensic sweep — gathering metadata from the file system
void fill_metadata( ColdCaseFile *case_file){
    struct stat info;

// Attempt to access the file’s metadata — size, timestamps, and more 
if(stat(case_file->filename, &info)==0){

// Evidence secured: file size and last modification time recorded
case_file->file_size = info.st_size;
case_file->last_modified = info.st_mtime;

// Calculate file age in days — how long since it was last touched
time_t now = time(NULL);
case_file->file_age=(now - info.st_mtime)/(60*60*24);

// Interpret the metadata and assign a poetic status verdict
get_file_status(case_file->status, case_file->file_age, case_file->issue_count);
case_file->read_success = 1;
}
else
{
     // The file resisted access — metadata unavailable, investigation halted
    printf("\033[5;31mFailed to read the file: %s\033[0m\n",case_file->filename);
   strcpy(case_file->status, "Unreadable - unable to access file metadata.");
   case_file->read_success = 0;
 
}
};





