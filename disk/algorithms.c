#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "supplements.c"

//algorithm 1: FCFS
//first come first serve
//processes requests in the order they come
void FCFS(int requests[], int initial_head) {
    //required variables
    int total_requests = 0;
    int total_distance = 0;
    //dummy variable
    int curr_head = initial_head;
    //while we are within the list
    while (total_requests < cylinders) {
        //calculate the difference 
        int difference = abs(curr_head - requests[total_requests]);
        //add it to the total head movement
        total_distance += difference;
        //change current to the next request
        curr_head = requests[total_requests];
        //increment the number of requests
        total_requests++;
    }
    printf("total # of cylinder requests: %i\n",total_requests);
    printf("total amount of head movement: %i\n",total_distance);
}

//algorithm 2: SSTF
//shortest seek time first
//processes requests based on the head movement
//in order of shorter head movement
void SSTF(int requests[], int initial_head) {
    //make a copy of the requests list (to be able to remove)
    int* requests2 = malloc(sizeof(*requests));
    for (int i = 0; i < cylinders; ++i) {
        requests2[i] = requests[i];
    }
    int total_requests = 0;
    int total_distance = 0;
    int curr_head = initial_head;
    int index;
    //while we are within the list
    while (total_requests < cylinders) {
        //use function to find the shortest path
        index = find_shortest(requests2, curr_head);
        //calculate head movement to that request
        int difference = abs(curr_head - requests2[index]);
        //add difference to the total head movement required
        total_distance += difference;
        //change current to the next request
        curr_head = requests2[index];
        //remove from the list
        requests2[index] = -1;
        //increment the number of requests
        total_requests++;
    } 
    printf("total # of cylinder requests: %i\n",total_requests);
    printf("total amount of head movement: %i\n",total_distance);
}

//algorithm 3: SCAN
//processes requests in one direction first
//when it reaches the end it moves and processes in the other direction
void SCAN(int requests[], int initial_head) {
    //make a copy of the requests list (to be able to remove)
    int* requests2 = malloc(sizeof(*requests));
    for (int i = 0; i < cylinders; ++i) {
        requests2[i] = requests[i];
    }
    int total_requests = 0;
    int total_distance = 0;
    int curr_head = initial_head;
    int index = 0;
    //to make sure we move in the same direction
    //if decreasing is 1, then we are moving towards 0
    //process requests on the way and then swap directions
    int decreasing = 1; 
    //while within the list
    while (total_requests < cylinders) {
        if (decreasing == 1) {
            //find the next closest request thats smaller
            index = find_shortest_min(requests2, curr_head);
            if (index == -1) {
                //swap directions when there are no more requests
                decreasing = 0;
            }
        }
        else {
            //find closest request thats greater 
            index = find_shortest_max(requests2, curr_head);
        }
        //calculate the difference
        int difference = abs(curr_head - requests2[index]);
        //add difference to the total head movement
        total_distance += difference;
        //change current head to the next request
        curr_head = requests2[index];
        //remove the request
        requests2[index] = -1;
        //increment the number of requests
        total_requests++;
    }
    printf("total # of cylinder requests: %i\n",total_requests);
    printf("total amount of head movement: %i\n",total_distance);
}

//algorithm 4: C-SCAN
//processes requests in increasing direction
//jumps back to 0 when it reaches the end
//doesnt process requests on the way back
void CSCAN(int requests[], int initial_head) {
    //make a copy of the reqtests list (to be able to remove)
    int* requests2 = malloc(sizeof(*requests) );
    for (int i = 0; i < cylinders; ++i) {
        requests2[i] = requests[i];
    }
    int total_requests = 0;
    int total_distance = 0;
    int curr_head = initial_head;
    int index = 0;
    //while we are within the list
    while (total_requests < cylinders) {
        //find the closest request thats greater
        index = find_shortest_max(requests2, curr_head);
        if (index == -1) {
            curr_head = 0;
            continue;
        }
        //calculate the difference
        int difference = abs(curr_head - requests2[index]);
        //add difference to the total head movement
        total_distance += difference;
        //change current head to the next request
        curr_head = requests2[index];
        //remove the request
        requests2[index] = -1;
        //increment the number of requests
        total_requests++;
    }
    printf("total # of cylinder requests: %i\n",total_requests);
    printf("total amount of head movement: %i\n",total_distance);
}
