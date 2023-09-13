#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <cstring>
#include <stdint.h>
#include <pthread.h>
#include <unistd.h>

#include "consumer.h"
#include "checksum.h"
using namespace std;

//consumer function
void* consumer(int num_items) {
    //struct args* arg = (struct args*) args;
    //struct shmid_ds buffer;
    struct HUH temp; 

    //int shmid = arg -> shmid;
    //int num_items = arg -> num_items;

   // BUFFER* ptr = (BUFFER*)arg -> ptr;
    unsigned short checksum1, checksum2;

    for(int i = 0; i < num_items; i++) {
        //enter critical section
        sem_wait(&full1);
        pthread_mutex_lock(&mutex1);

        //reading items from buffer
        //temp = shm_ptr[i];
        cout << "Data Read by Consumer" << endl;

        //copying checksum
        memcpy(&temp, &shm_ptr[i], 2);
        
        //calculating checksum
        checksum1 = checksum(&temp.data[0], 50);
        

        //check is they match 
        if (checksum2 != shm_ptr[i].curr_checksum) {
            cout << "ERROR: checksums don't match." << endl;
            printf("Expected: %02x, Calculated: %02x \n", shm_ptr[i].curr_checksum, checksum2);
            exit(1);
        }
        else {
            cout << "SUCCESS: checksums match" << endl;
        }

        //leaving critical section
        pthread_mutex_unlock(&mutex1);
        sem_post(&empty1);
    }
    
    return NULL;
}


int main(int argc, char const *argv[]){}