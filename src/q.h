// The functions that you implement are:
// item = NewItem(); // returns a pointer to a new q-element
// InitQueue( &head) // creates a empty queue, pointed to by the variable head.
// AddQueue(&head, item) // adds a queue item, pointed to by “item”, to the queue pointed to by head.
// item = DelQueue(&head) // deletes an item from head and returns a pointer to the deleted item
// RotateQ(&head) // Moves the header pointer to the next element in the queue. This is equivalent to AddQ(&head, DeleteQ(&head)), but is simpler to use and more efficient to implement.
// Note: All the routines work on pointers. They do not copy q-elements. Also they to not allocate/deallocate space (except NewItem()). You may choose to implement a FreeItem(item) function – optional.

#ifndef q
#define q


#include <stdlib.h>
#include "tcb.h"


TCB_t * RunQ;


// Required Functions
TCB_t * NewItem();
void InitQueue(TCB_t **);
void AddQueue(TCB_t **, TCB_t **);
TCB_t * DelQueue(TCB_t **);
void RotateQ(TCB_t **);

// Helper Functions
void AddToEnd(TCB_t ** current, TCB_t ** toAdd);


// Implementations:
TCB_t * NewItem()
{
	TCB_t * item = (TCB_t *) malloc(sizeof(TCB_t));
	return item;
}

void InitQueue(TCB_t ** head)
{
	*head = NULL;
}

void AddQueue(TCB_t ** head, TCB_t ** toAdd)
{
	if(*head == NULL){
		*head = *toAdd;
	}else{
		AddToEnd(head,toAdd);
	}
}

void AddToEnd(TCB_t ** current, TCB_t ** toAdd)
{
	if((*current)->next == NULL){
		(*current)->next = *toAdd;
	}else{
		AddToEnd(&((*current)->next),toAdd);
	}
}

TCB_t * DelQueue(TCB_t ** head)
{
	TCB_t * deleted = *head;
    
    if ((*head)->next != NULL) {
        (*head)->next->prev = NULL;
    }

    *head = (*head)->next;

	return deleted;
}

void RotateQ(TCB_t ** head)
{
	TCB_t * prevHead = *head;
	if((*head)->next != NULL){
		(*head)->next->prev = NULL;
		*head = (*head)->next;
		AddToEnd(head,&prevHead);
	}
}


#endif /* q */
