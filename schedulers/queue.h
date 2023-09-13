#include <stdio.h>
#include <stdlib.h>

struct QueueNode {
    struct node* tempNode;
	struct QueueNode* next;
};

//different operations of the queue
//creates a new node
struct QueueNode* newNode(struct node* param);
//creates a new empty queue
struct Queue* createQueue();
//adds to queue
void enQueue(struct Queue* q, struct node* param);
//removes from queue
void deQueue(struct Queue* q);