#ifndef COMMON_H
#define COMMON_H

#define MAX_HOSPITALS 10
#define MAX_NAME 50
#define INF 9999
#define MAX_HISTORY 100

typedef struct {
    char name[MAX_NAME];
    char bloodGroup[4];
    char organ[MAX_NAME];
    int expiryTime;       // in hours
    int hospitalId;
} Donor;

typedef struct {
    char name[MAX_NAME];
    char bloodGroup[4];
    char organNeeded[MAX_NAME];
    int urgencyLevel;     // lower = higher urgency
    int hospitalId;
} Patient;

typedef struct {
    int numHospitals;
    int adjMatrix[MAX_HOSPITALS][MAX_HOSPITALS];
} HospitalGraph;

typedef struct {
    char donorName[MAX_NAME];
    char patientName[MAX_NAME];
    char organ[MAX_NAME];
} HistoryEntry;

#endif
