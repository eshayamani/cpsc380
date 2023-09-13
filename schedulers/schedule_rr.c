#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "schedulers.h"
#include "list.h"
#include "cpu.h"

//Round Robin
//each task is run for a time quantum (or for the remainder of its CPU burst)

struct node* head = NULL;
struct node* tail = NULL;

//function to add a task to the list
void add(char *name, int priority, int burst) {

    struct task* temp = malloc(sizeof(struct task));

    //adding from temp values
    temp->name = name;
    temp->priority = priority;
    temp->burst = burst;

    //insert at the end
    insertTail(&tail, &head, temp);

}

void schedule() {
    //while list is not empty
    while (head != NULL) {
        //assign temp values
        struct task* tempTask = head->task;

        //QUANTUM = 10
        int quantum = 10;
        //if the burst time is less than or equal to the given quantum
        if (tempTask->burst <= quantum) {
            //run the task and delete from list
            run(tempTask, tempTask->burst);
            delete(&head, tempTask);
        }

        //if the burst time is greater than the given quantum
        else if (tempTask->burst > quantum){
            //run the task
            run(tempTask, quantum);
            //subtract to find remainting time
            tempTask->burst -= quantum;
            //delete task and re add 
            //adds to the end of the queue
            delete(&head, tempTask);
            add(tempTask->name, tempTask->priority, tempTask->burst);
        }

    }
}