#include "queue.h"

//initializing the queue
struct Queue {
	struct QueueNode *front, *rear;
};

//function that creates a new node
struct QueueNode* newNode(struct node* param)
{
	struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
	temp->tempNode = param;
	temp->next = NULL;
	return temp;
}

//function that creates an empty queue
struct Queue* createQueue()
{
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = q->rear = NULL;
	return q;
}

//function that adds a node into the queue
void enQueue(struct Queue* q, struct node* param)
{
	struct QueueNode* temp = newNode(param);

    //if queue is empty
	if (q->rear == NULL) {
		q->front = q->rear = temp;
		return;
	}

    //add to end of queue and make it the rear node
	q->rear->next = temp;
	q->rear = temp;
}

//function that removes values from the queue
void deQueue(struct Queue* q)
{
	//if queue is empty
    if (q->front == NULL)
		return;

    //assigns new front node and stores old front 
	struct QueueNode* temp = q->front;
	q->front = q->front->next;

    //if queue becomes empty
	if (q->front == NULL)
		q->rear = NULL;
	free(temp);
}