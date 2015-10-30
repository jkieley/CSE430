// The functions that you implement are:
// item = NewItem(); // returns a pointer to a new q-element
// InitQueue( &head) // creates a empty queue, pointed to by the variable head.
// AddQueue(&head, item) // adds a queue item, pointed to by “item”, to the queue pointed to by head.
// item = DelQueue(&head) // deletes an item from head and returns a pointer to the deleted item
// RotateQ(&head) // Moves the header pointer to the next element in the queue. This is equivalent to AddQ(&head, DeleteQ(&head)), but is simpler to use and more efficient to implement.
// Note: All the routines work on pointers. They do not copy q-elements. Also they to not allocate/deallocate space (except NewItem()). You may choose to implement a FreeItem(item) function – optional.

#include <stdlib.h>

// Structures
typedef struct Item {
	struct Item * prev;
	struct Item * next;
	int payload;
} Item;


// Required Functions
Item * NewItem();
void InitQueue(Item *);
void AddQueue(Item *, Item *);
Item * DelQueue(Item *);
void RotateQ(Item *);

// Helper Functions
void AddToEnd(Item * current, Item * toAdd);


// Implementations:
Item * NewItem()
{
	Item * item = (Item*)malloc(sizeof(Item));
	return item;
}

void InitQueue(Item * head)
{
	head = NULL;
}

void AddQueue(Item * head, Item * toAdd)
{
	if(head == NULL){
		head = toAdd;
	}else{
		AddToEnd(head,toAdd);
	}
}

void AddToEnd(Item * current, Item * toAdd)
{
	if(current->next == NULL){
		current->next = toAdd;
	}else{
		AddToEnd(current->next,toAdd);
	}
}

Item * DelQueue(Item * head)
{
	Item * deleted = head;

	head->next->prev = NULL;
	head = head->next;

	return deleted;
}

void RotateQ(Item * head)
{
	Item * prevHead = head;
	head->next->prev = NULL;
	head = head->next;
	AddToEnd(head,prevHead);
}
