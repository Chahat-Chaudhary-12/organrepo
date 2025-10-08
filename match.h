#ifndef MATCH_H
#define MATCH_H

#include "common.h"
#include "history.h"

void matchDonorsPatients(Donor donors[], int donorCount, Patient patients[], int patientCount,
                         HospitalGraph* graph, HistoryEntry history[], int *historyCount);

#endif
