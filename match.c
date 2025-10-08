#include <stdio.h>
#include <string.h>
#include "match.h"
#include "compatibility.h"
#include "history.h"

void dijkstra(HospitalGraph* graph, int src, int dist[]){
    int n = graph->numHospitals;
    int visited[MAX_HOSPITALS] = {0};

    for(int i=0;i<n;i++)
        dist[i] = graph->adjMatrix[src][i];
    dist[src] = 0;
    visited[src] = 1;

    for(int count=1; count<n; count++){
        int minDist = INF, u=-1;
        for(int i=0;i<n;i++){
            if(!visited[i] && dist[i]<minDist){
                minDist = dist[i];
                u=i;
            }
        }
        if(u==-1) break;
        visited[u] = 1;

        for(int v=0;v<n;v++){
            if(!visited[v] && graph->adjMatrix[u][v]!=INF){
                if(dist[u]+graph->adjMatrix[u][v]<dist[v]){
                    dist[v]=dist[u]+graph->adjMatrix[u][v];
                }
            }
        }
    }
}

void matchDonorsPatients(Donor donors[], int donorCount, Patient patients[], int patientCount,
                         HospitalGraph* graph, HistoryEntry history[], int *historyCount){
    int dist[MAX_HOSPITALS];
    for(int i=0;i<donorCount;i++){
        printf("\n Matching Donor: %s | Organ: %s | Blood: %s | Expiry: %d | Hospital: %d\n",
               donors[i].name, donors[i].organ, donors[i].bloodGroup,
               donors[i].expiryTime, donors[i].hospitalId);

        dijkstra(graph, donors[i].hospitalId, dist);

        int bestPatient=-1;
        int minDistance=INF;

        for(int j=0;j<patientCount;j++){
            printf("   Checking Patient: %s | Organ Needed: %s | Blood: %s | Urgency: %d | Hospital: %d\n",
                   patients[j].name, patients[j].organNeeded, patients[j].bloodGroup,
                   patients[j].urgencyLevel, patients[j].hospitalId);

            int compatible = 1;

            if(strcmp(donors[i].organ, patients[j].organNeeded)!=0){
                printf("    -> Reject: Organ mismatch (needs %s)\n", patients[j].organNeeded);
                compatible = 0;
            }
            else if(!checkBloodCompatibility(donors[i].bloodGroup, patients[j].bloodGroup)){
                printf("    -> Reject: Blood mismatch (patient %s requires %s)\n", patients[j].name, patients[j].bloodGroup);
                compatible = 0;
            }
            else{
                int travelTime = dist[patients[j].hospitalId];
                if(travelTime > donors[i].expiryTime){
                    printf("    -> Reject: Travel time too long (%d > %d)\n", travelTime, donors[i].expiryTime);
                    compatible = 0;
                } else {
                    printf("    -> Travel time OK (%d <= %d)\n", travelTime, donors[i].expiryTime);
                    if(bestPatient==-1 || patients[j].urgencyLevel < patients[bestPatient].urgencyLevel){
                        bestPatient = j;
                        minDistance = travelTime;
                    }
                }
            }
        }

        if(bestPatient != -1){
            printf("\n Donor %s MATCHED with Patient %s | Urgency: %d | Travel: %d\n",
                   donors[i].name, patients[bestPatient].name,
                   patients[bestPatient].urgencyLevel, minDistance);
            addHistory(history, historyCount, donors[i], patients[bestPatient]);
        } else {
            printf("\n Donor %s could NOT match any patient.\n", donors[i].name);
        }
    }
}
