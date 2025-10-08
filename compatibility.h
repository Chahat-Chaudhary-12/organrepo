#ifndef COMPATIBILITY_H
#define COMPATIBILITY_H

#include "common.h"

int checkBloodCompatibility(const char donorBlood[], const char patientBlood[]);
int isCompatible(Donor donor, Patient patient);

#endif
