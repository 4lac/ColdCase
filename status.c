#include <stdio.h>


void get_file_status(char *status, int age, int issue_count) {
    const char *heat = "";
    const char *risk = "";

    // ColdCase examines the file’s age to determine its temperature
  if (age <= 10)       heat = "\033[1;31mHot \033[0m";
else if (age <= 30)  heat = "\033[1;36m Active \033[0m";
else if (age <= 90)  heat = "\033[38;5;117m Warm \033[0m";
else if (age <= 180) heat = "\033[38;5;123mCold \033[0m";
else                 heat = "\033[1;34mFrozen \033[0m";

    // Based on the number of issues, ColdCase assesses the risk level
    if (issue_count == 0)
    risk = "\033[1;36mStable — no known issues.\033[0m";
else if (issue_count <= 5)
    risk = "\033[1;33mMinor anomalies detected.\033[0m";
else
    risk = "\033[1;31mPossibly risky.\033[0m";
    // ColdCase compiles the final forensic verdict into a single poetic status line
    sprintf(status, "\033[1;36m%s\033[0m", heat, age, issue_count, risk);
    //sprintf(status, "\033[1;36m%s - modified %d days ago. %d issue(s). %s\033[0m", heat, age, issue_count, risk);
};

