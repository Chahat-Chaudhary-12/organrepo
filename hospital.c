#include <stdio.h>
#include "hospital.h"

void inputHospitalGraph(HospitalGraph *graph){
    printf("\n Input hospital graph...\n");
    printf("Enter number of hospitals: ");
    scanf("%d", &graph->numHospitals);

    for(int i=0;i<graph->numHospitals;i++){
        for(int j=0;j<graph->numHospitals;j++){
            if(i==j) graph->adjMatrix[i][j] = 0;
            else {
                printf("Enter travel time from Hospital %d to %d (9999 if no path): ", i, j);
                scanf("%d", &graph->adjMatrix[i][j]);
            }
        }
    }

    printf(" Hospital graph matrix:\n");
    for(int i=0;i<graph->numHospitals;i++){
        for(int j=0;j<graph->numHospitals;j++){
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}
