#ifndef CONSUMER_H
#define CONSUMER_H
#include <sys/types.h>
#include <semaphore.h>

//method declaration
//with num_items as a parameter
void* consumer(int num_items);
#endif