#ifndef SCANNER_H
#define SCANNER_H

#include "coldcase.h"
/**
 * @brief Opens the file and conducts a forensic sweep, line by line.
 *
 * ColdCase steps into the file like a digital investigator—quietly scanning each line
 * for signs of unfinished work, exposed secrets, and risky logic. It searches for known
 * patterns such as TODOs, password leaks, eval usage, and FIXMEs.
 *
 * Each anomaly is documented with its line number, classification, and full content,
 * forming the evidence trail that will later be presented in the final report.
 *
 * @param case_file Pointer to the ColdCaseFile structure containing metadata and issue records.
 */
void scan_file_for_issues(ColdCaseFile *case_file);

#endif
