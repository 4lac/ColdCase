#ifndef REPORT_H
#define REPORT_H

#include "coldcase.h"

/**
 * @brief Prints a full forensic report based on the scanned file.
 *
 * This function acts as the narrator of the investigation.
 * After all evidence has been collected—issues, metadata, and status—
 * `print_report()` steps in to present the findings in a clear, expressive format.
 *
 * It color-codes each issue based on severity, labels the file’s condition,
 * and walks the user through every anomaly found. If no issues are present,
 * it declares the file clean. Otherwise, it closes with a final verdict.
 *
 * @param case_file Pointer to the ColdCaseFile structure containing all investigation data.
 */
void print_report(const ColdCaseFile *case_file);

#endif