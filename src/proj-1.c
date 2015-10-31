/*
 ============================================================================
 Name        : operating-systems-project-1.c
 Author      : James Kieley
 Version     :
 Copyright   : Your copyright notice
 Description : Used to test on the functions created in Project 1
 ============================================================================
 */

#define _XOPEN_SOURCE 600
#include <stdio.h>
#include <stdlib.h>
#include "q.h"

typedef int bool;
#define true 1
#define false 0

int failures = 0;
int successes = 0;

// function declarations
void addResult(bool result);
void printResultes();
int countItems(TCB_t * head);

// tests
bool testNewItem();
bool testInitQueue();
bool testAddQueue();
bool testDelQueue();
bool testRotateQ();
bool testDeleteLastItem();


int main(void) {

	addResult(testNewItem());
	addResult(testInitQueue());
	addResult(testAddQueue());
 	addResult(testDelQueue());
	addResult(testRotateQ());
	addResult(testDeleteLastItem());
	printResultes();

	return EXIT_SUCCESS;
}

// The functions that you implement are:
// item = NewItem(); // returns a pointer to a new q-element
// InitQueue( &head) // creates a empty queue, pointed to by the variable head.
// AddQueue(&head, item) // adds a queue item, pointed to by “item”, to the queue pointed to by head.
// item = DelQueue(&head) // deletes an item from head and returns a pointer to the deleted item
// RotateQ(&head) // Moves the header pointer to the next element in the queue. This is equivalent to AddQ(&head, DeleteQ(&head)), but is simpler to use and more efficient to implement.
// Note: All the routines work on pointers. They do not copy q-elements. Also they to not allocate/deallocate space (except NewItem()). You may choose to implement a FreeItem(item) function – optional.


bool testNewItem()
{
	TCB_t * item = NewItem();
	return item->next == NULL;
}

bool testInitQueue()
{
	TCB_t * head = NULL;
	InitQueue(&head);
	return head == NULL;
}

bool testAddQueue()
{
	TCB_t * head = NULL;
	TCB_t * item = NewItem();
	AddQueue(&head,&item);

	return head == item;
}
bool testDelQueue(){
    bool firstCheck = false;
    bool secondCheck = false;
    bool thirdCheck = false;
    
    TCB_t * head = NULL;
    TCB_t * newItem1 = NewItem();
    TCB_t * newItem2 = NewItem();
    AddQueue(&head, &newItem1);
    AddQueue(&head, &newItem2);
    
    firstCheck = countItems(head) == 2;
    
    TCB_t * deleted = DelQueue(&head);
    secondCheck = countItems(head) == 1;
    thirdCheck = deleted == newItem1;
    
    return firstCheck && secondCheck && thirdCheck;
}
bool testRotateQ(){
    TCB_t * head = NULL;
    
    TCB_t * newItem1 = NewItem();
    TCB_t * newItem2 = NewItem();
    AddQueue(&head, &newItem1);
    AddQueue(&head, &newItem2);
    
    RotateQ(&head);
    
    return head == newItem2;
}

bool testDeleteLastItem(){
    TCB_t * head = NULL;
    TCB_t * newItem1 = NewItem();
    TCB_t * newItem2 = NewItem();
    AddQueue(&head, &newItem1);
    AddQueue(&head, &newItem2);

    TCB_t * deleted1 = DelQueue(&head);
    TCB_t * deleted2 = DelQueue(&head);
    
    return deleted2 == newItem2;
}


void addResult(bool result)
{
	if(result)
	{
		successes++;
	}else
	{
		failures++;
	}
}

void printResultes()
{
	printf("%d Failures, %d Success\n",failures, successes);
}

int countItems(TCB_t * head){
    int count = 0;
    if (head == NULL) {
        return count;
    }else{
        count++; // head is not null
        TCB_t * current = head;
        while (current->next != NULL) {
            count++;
            current = current->next;
        }
    }
    return count;
}




