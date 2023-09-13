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

#include "checksum.cpp"
#include "producer.h"
using namespace std;

//producer function
void* producer() {
    //struct args* arg = (struct args*) args;
    //struct shmid_ds buffer;
    struct HUH temp;

    //int shmid = arg -> shmid;
    //int num_items = arg -> num_items;

    //HUH* ptr = (HUH*)arg -> ptr;
    unsigned short curr_checksum;

    for (int i = 0; i < 50; i++) {
        //writting data to buffer
        //for (int j = 0; j < 50; j++) {
        temp.data[i] = (u_int8_t)(rand() % 256);
        //}

        cout << "Data Written by Producer" << endl;

        //calculating the checksum value
        curr_checksum = checksum(&temp.data[0], 50);

        //critical section
        sem_wait(&empty1);
        pthread_mutex_lock(&mutex1);

        //copying checksum
        memcpy(&temp.curr_checksum, &curr_checksum, 2);
        //adding the temp item
        shm_ptr[i] = temp;

        //closing critical section
        pthread_mutex_unlock(&mutex1);
        sem_post(&full1);
    }

    return NULL;
}
