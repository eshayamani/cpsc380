#ifndef CHECKSUM_H
#define CHECKSUM_H
#include <vector>
#include <semaphore.h>
#include <sys/types.h>

//method declarations
uint16_t checksum(uint8_t *address, u_int32_t count);

//arguments
struct args;

typedef struct HUH BUFFER;

//semaphores and mutex declaration
sem_t full1;
sem_t empty1;
pthread_mutex_t mutex1;

#endif