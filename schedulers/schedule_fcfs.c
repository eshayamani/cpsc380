#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "schedulers.h"
#include "list.h"
#include "cpu.h"

//First Come First Serve
//schedules tasks in the order in which they request the CPU

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
        //assigns head (first task)
        struct node* tempHead = head;
        struct task* tempTask = tempHead->task;

        run(tempTask, tempTask->burst);
        //delete task after it runs
        delete(&head, tempTask);
    }
}