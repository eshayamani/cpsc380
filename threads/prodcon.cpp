#include <vector>
#include <iostream>
#include <stdio.h>
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

#include "producer.cpp"
#include "consumer.cpp"
#include "checksum.cpp"

#define FTOK_FILE          "ftok.file"
#define FTOK_ID            1

using namespace std;

//main method
int main(int argc, char const *argv[]) {
    //check to make sure all argumets are given
    if (argc < 2) {
        cout << "ERROR: missing required arguments" << endl;
        exit(1);
    }
    //grabbing first argument
    int num_items = atoi(argv[1]);
    srand(time(NULL));

    //limiting input 
    if (num_items < 1 || num_items > 2000) {
        cout << "ERORR: incorrect items input" << endl;
    }

    //open 
    sem_init(&full1, 0, 0);
    sem_init(&empty1, 0, num_items);
    pthread_mutex_init(&mutex1, NULL);

    //error handling -> for shared memory
    int shmid = shmget(ftok(FTOK_FILE, FTOK_ID), num_items*32, IPC_CREAT | 0666);
    if (shmid == -1) {
        cout << "ERORR: shared memory not created" << endl;
        return -1;
    }

    BUFFER* ptr = (BUFFER*)(shmat(shmid, NULL, 0));
    if (ptr == NULL) {
        cout << "ERROR: shared memory not attached" << endl;
        return -1;
    }

    //creating the threads for consumer and producer
    pthread_t producer_thread;
    pthread_t consumer_thread;

    pthread_attr_t attr;

    pthread_attr_init(&attr);
    //arguments
    //args x;
    //x.num_items = num_items;
    //x.shmid = shmid;
    //x.ptr = ptr;

    //prodcuer and consumer thread
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    //combining threads
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    shmctl(shmid, IPC_RMID, NULL);
 
    //close
    sem_destroy(&full1);
    sem_destroy(&empty1);
    pthread_mutex_destroy(&mutex1);
    return 0;
    
}
