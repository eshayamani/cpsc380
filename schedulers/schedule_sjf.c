#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "schedulers.h"
#include "list.h"
#include "cpu.h"

//Shortest Job First
//chedules tasks in order of the length of the tasks’ next CPU burst

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
        struct task* tempQuick = tempTask;

        //while loop to find the shortest job
        while (tempHead->next != NULL) {
            //temp store
            tempHead = tempHead->next;
            tempTask = tempHead->task;
            //compare with current shortest task
            if (tempTask->burst < tempQuick->burst) {
                tempQuick = tempTask;
            }
        }

        //run shortest job
        run(tempQuick, tempQuick->burst);
        //delete from list
        delete(&head, tempQuick);
        //contine in while loop till empty
    }
}