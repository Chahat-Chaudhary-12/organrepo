#include <stdio.h>
#include "common.h"
#include "donor.h"
#include "patient.h"
#include "hospital.h"
#include "match.h"
#include "history.h"

int main(){
    Donor donors[50];
    Patient patients[50];
    HistoryEntry history[MAX_HISTORY];
    HospitalGraph graph;
    int donorCount = 0, patientCount = 0, historyCount = 0;
    int choice;

    do {
        printf("\n--- Organ Transplant System ---\n");
        printf("1. Input Hospital Graph\n");
        printf("2. Add Donor\n");
        printf("3. Add Patient\n");
        printf("4. Show All Donors\n");
        printf("5. Show All Patients\n");
        printf("6. Show Transplant History\n");
        printf("7. Match Donors to Patients\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar(); // consume leftover newline

        switch(choice){
            case 1:
                inputHospitalGraph(&graph);
                break;
            case 2:
                addDonor(donors, &donorCount);
                break;
            case 3:
                addPatient(patients, &patientCount);
                break;
            case 4:
                showDonors(donors, donorCount);
                break;
            case 5:
                showPatients(patients, patientCount);
                break;
            case 6:
                printHistory(history, historyCount);
                break;
            case 7:
                matchDonorsPatients(donors, donorCount, patients, patientCount, &graph, history, &historyCount);
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf(" Invalid choice. Please enter a number 0-7.\n");
        }

    } while(choice != 0);

    return 0;
}
