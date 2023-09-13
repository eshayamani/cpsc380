/**
 * list data structure containing the tasks in the system
 */

#include "task.h"

struct node {
    Task *task;
    struct node *next;
};

//different operations
void insert(struct node **head, Task *task);
//insert at the end
void insertTail(struct node **tail, struct node **head, Task *task);
void delete(struct node **head, Task *task);
void traverse(struct node *head);
