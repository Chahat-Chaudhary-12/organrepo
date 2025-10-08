#ifndef HISTORY_H
#define HISTORY_H

#include "common.h"

void addHistory(HistoryEntry history[], int *count, Donor donor, Patient patient);
void printHistory(HistoryEntry history[], int count);

#endif
