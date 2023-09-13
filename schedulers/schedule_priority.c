#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "schedulers.h"
#include "list.h"
#include "cpu.h"

//Priority Scheduler
//chedules tasks based on priority

struct node* head;

//function to add a task to the list
void add(char *name, int priority, int burst) {

    struct task* temp = malloc(sizeof(struct task));
   
    //adding from temp values  
    temp->name = name;
    temp->priority = priority;
    temp->burst = burst;

    //insert at the front
    insert(&head, temp);
}


void schedule() {
    //while list is not empty
    while (head != NULL) {
        //assign temp values from list
        struct node* tempHead = head;
        struct task* tempTask = head->task;
        struct task* tempPri = tempTask;

        //while loop to find highest priority
        while (tempHead->next != NULL) {
            tempHead = tempHead->next;
            tempTask = tempHead->task;
            //compares with current highest value
            //same as sjf but change burst to priority
            if (tempTask->priority > tempPri->priority) {
                tempPri = tempTask;
            }
        }

        //runs task with highest priority
        run(tempPri, tempPri->burst);
        //deletes from list
        delete(&head, tempPri);
        //continues with while loop until empty
    }
}