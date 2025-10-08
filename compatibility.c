#include <string.h>
#include "compatibility.h"

int checkBloodCompatibility(const char donorBlood[], const char patientBlood[]){
    if(strcmp(donorBlood, "O-") == 0) return 1; // universal donor
    if(strcmp(donorBlood, patientBlood) == 0) return 1;
    return 0;
}

int isCompatible(Donor donor, Patient patient){
    return strcmp(donor.organ, patient.organNeeded) == 0 &&
           checkBloodCompatibility(donor.bloodGroup, patient.bloodGroup);
}
