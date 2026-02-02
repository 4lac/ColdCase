#ifndef METADATA_H
#define METADATA_H

#include "coldcase.h"
/**
 * @brief Fills metadata for a given file, including size, last modified time, and age.
 *
 * ColdCase begins its archival sweep—gathering raw facts from the file system.
 * It records the file’s size, last known activity, and calculates its age in days.
 * Once the evidence is collected, it calls upon `get_file_status()` to interpret
 * the metadata and deliver a poetic forensic verdict.
 *
 * If the file resists access, the investigation is marked unreadable and halted.
 *
 * @param case_file Pointer to the ColdCaseFile structure to be filled.
 */
void fill_metadata(ColdCaseFile *case_file);

#endif