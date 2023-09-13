#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "algorithms.c"

int main(int argc, char const *argv[]) {
    //make sure the correct number of command line parameters 
    if (argc < 3) {
        printf("ERROR: invalid amount of arguments \n");
        exit(1);
    } 
    //the list of requests
    int requests[cylinders];
    //the first arg is the starting head
    int intital_head = atoi(argv[1]);
    int i = 0;
    FILE *file;

    //open and read the file
    if(file = fopen(argv[2], "r")) {
        while (fscanf(file, "%d", &requests[i]) != EOF) {
            i++;
        }
        fclose(file);
    }
    else {
        printf("ERROR: invalid file");
        exit(1);
    }
    
    //algorithm 1: FCFS
    printf("FCFS: \n");
    FCFS(requests, intital_head);
    printf("\n");

    //algorithm 2: SSTF
    printf("SSTF: \n");
    SSTF(requests, intital_head);
    printf("\n");

    //algorithm 3: SCAN
    printf("SCAN: \n");
    SCAN(requests, intital_head);
    printf("\n");

    //algorithm 4:
    printf("C-SCAN: \n");
    CSCAN(requests, intital_head);
    printf("\n");

    return 0;
} 

