#ifndef STATUS_H
#define STATUS_H

/**
 * @brief Assigns a poetic forensic status to the investigated file.
 *
 * ColdCase reviews the file’s age and the number of issues found,
 * then crafts a temperature-based classification—Hot, Warm, Cold, or Frozen—
 * paired with a risk assessment. The result is a status string that reads
 * like a forensic verdict: colored, expressive, and emotionally intelligent.
 *
 * @param status Output buffer where the final status string will be stored.
 * @param age Number of days since the file was last modified.
 * @param issue_count Total number of suspicious lines found during investigation.
 */
void get_file_status(char *status, int age, int issue_count);

#endif