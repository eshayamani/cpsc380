#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int cylinders = 1000;

//function needed for algorithm 2, finds the next shortest distance
//compares with each index in the list 
int find_shortest(int requests[], int curr_head) {
    int index = 0;
    int curr_index = 0;
    int limit = INT32_MAX;
    //while we are within the list
    while (curr_index < cylinders) {
        if (requests[curr_index] < 0) {
            curr_index++;
            continue;
        }
        //calculating the difference
        int difference = abs(curr_head - requests[curr_index]);
        //replacing the limit if shorter distnace is found
        if (difference < limit) {
            limit = difference;
            index = curr_index;
        }
        curr_index++;
    }
    return index;
}


//function needed for algorithms 3 and 4
//finds the closest value that is smaller (moving to the left)
int find_shortest_min(int requests[], int curr_head) {
    int index = 0;
    int curr_index = 0;
    int limit = INT32_MAX;
    //while we are within the list
    while (curr_index < cylinders) {
        //or if the value is greater than the current request
        //because we want a number smaller
        if(requests[curr_index] < 0 || requests[curr_index] > curr_head) {
            curr_index++;
            continue;
        } 
        //calculating the difference
        int difference = abs(curr_head - requests[curr_index]);
        //replacing the limit if a shorter distance is found
        if (difference < limit) {
            limit = difference;
            index = curr_index;
        }
        curr_index++;
    }
    if (index == INT32_MAX) {
        index = -1;
    }
    return index;
}


//function needed for algorithms 3 and 4
//finds the closest value that is larger (moving to the right)
int find_shortest_max(int requests[], int curr_head) {
    int index = 0;
    int curr_index = 0;
    int limit = INT32_MAX;
    //while we are within the list
    while (curr_index < cylinders) {
        //or if the value is smaller than the current request
        //because we want a number greater
        if(requests[curr_index] < 0 || requests[curr_index] < curr_head) {
            curr_index++;
            continue;
        } 
        //calculating the difference
        int difference = abs(curr_head - requests[curr_index]);
        //replacing the limit if a shorter distance is found
        if (difference < limit) {
            limit = difference;
            index = curr_index;
        }
        curr_index++;
    }
    if (index == INT32_MAX) {
        index = -1;
    }
    return index;
}
