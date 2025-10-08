#include <stdio.h>
#include <string.h>
#include "history.h"

void addHistory(HistoryEntry history[], int *count, Donor donor, Patient patient){
    strcpy(history[*count].donorName, donor.name);
    strcpy(history[*count].patientName, patient.name);
    strcpy(history[*count].organ, donor.organ);
    (*count)++;
    printf("History updated: Donor %s -> Patient %s | Organ: %s\n",
           donor.name, patient.name, donor.organ);
}

void printHistory(HistoryEntry history[], int count){
    if(count == 0){
        printf(" No transplant history.\n");
        return;
    }
    printf("\n --- Transplant History ---\n");
    for(int i=0;i<count;i++){
        printf("%d. Donor: %s -> Patient: %s | Organ: %s\n",
               i+1, history[i].donorName, history[i].patientName, history[i].organ);
    }
}
