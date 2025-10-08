#include <stdio.h>
#include <string.h>
#include "donor.h"

void addDonor(Donor donors[], int *donorCount){
    printf("\n Adding new donor...\n");
    printf("Enter Donor Name: ");
    getchar(); // consume leftover newline
    fgets(donors[*donorCount].name, MAX_NAME, stdin);
    donors[*donorCount].name[strcspn(donors[*donorCount].name, "\n")] = 0;

    printf("Enter Blood Group: ");
    scanf("%s", donors[*donorCount].bloodGroup);

    printf("Enter Organ: ");
    scanf("%s", donors[*donorCount].organ);

    printf("Enter Expiry Time (hours): ");
    scanf("%d", &donors[*donorCount].expiryTime);

    printf("Enter Hospital ID: ");
    scanf("%d", &donors[*donorCount].hospitalId);

    printf(" Donor added: %s | Blood: %s | Organ: %s | Expiry: %d | Hospital: %d\n",
           donors[*donorCount].name, donors[*donorCount].bloodGroup,
           donors[*donorCount].organ, donors[*donorCount].expiryTime,
           donors[*donorCount].hospitalId);

    (*donorCount)++;
}

void showDonors(Donor donors[], int donorCount){
    if(donorCount == 0){
        printf(" No donors added.\n");
        return;
    }
    printf("\n --- Donors List ---\n");
    for(int i=0;i<donorCount;i++){
        printf("%d. %s | Blood: %s | Organ: %s | Expiry: %d | Hospital: %d\n",
               i+1, donors[i].name, donors[i].bloodGroup, donors[i].organ,
               donors[i].expiryTime, donors[i].hospitalId);
    }
}
