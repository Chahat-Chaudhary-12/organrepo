#include <stdio.h>
#include <string.h>
#include "patient.h"

void addPatient(Patient patients[], int *patientCount){
    int urgency;
    printf("\n Adding new patient...\n");
    printf("Enter Patient Name: ");
    getchar(); // consume leftover newline
    fgets(patients[*patientCount].name, MAX_NAME, stdin);
    patients[*patientCount].name[strcspn(patients[*patientCount].name, "\n")] = 0;

    printf("Enter Blood Group: ");
    scanf("%s", patients[*patientCount].bloodGroup);

    printf("Enter Organ Needed: ");
    scanf("%s", patients[*patientCount].organNeeded);

    do {
        printf("Enter Urgency Level (1-10, lower=high): ");
        scanf("%d", &urgency);
        if(urgency < 1 || urgency > 10){
            printf(" Invalid urgency. Enter 1-10.\n");
        }
    } while(urgency < 1 || urgency > 10);

    patients[*patientCount].urgencyLevel = urgency;

    printf("Enter Hospital ID: ");
    scanf("%d", &patients[*patientCount].hospitalId);

    printf(" Patient added: %s | Blood: %s | Organ Needed: %s | Urgency: %d | Hospital: %d\n",
           patients[*patientCount].name, patients[*patientCount].bloodGroup,
           patients[*patientCount].organNeeded, patients[*patientCount].urgencyLevel,
           patients[*patientCount].hospitalId);

    (*patientCount)++;
}

void showPatients(Patient patients[], int patientCount){
    if(patientCount == 0){
        printf(" No patients added.\n");
        return;
    }
    printf("\n--- Patients List ---\n");
    for(int i=0;i<patientCount;i++){
        printf("%d. %s | Blood: %s | Organ Needed: %s | Urgency: %d | Hospital: %d\n",
               i+1, patients[i].name, patients[i].bloodGroup, patients[i].organNeeded,
               patients[i].urgencyLevel, patients[i].hospitalId);
    }
}
