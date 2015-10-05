// The functions that you implement are:
// item = NewItem(); // returns a pointer to a new q-element
// InitQueue( &head) // creates a empty queue, pointed to by the variable head.
// AddQueue(&head, item) // adds a queue item, pointed to by “item”, to the queue pointed to by head.
// item = DelQueue(&head) // deletes an item from head and returns a pointer to the deleted item
// RotateQ(&head) // Moves the header pointer to the next element in the queue. This is equivalent to AddQ(&head, DeleteQ(&head)), but is simpler to use and more efficient to implement.
// Note: All the routines work on pointers. They do not copy q-elements. Also they to not allocate/deallocate space (except NewItem()). You may choose to implement a FreeItem(item) function – optional.


typedef struct Item {
	struct Item * prev;
	struct Item * next;
	int payload;
} Item;

typedef struct Que {
	Item * head;
} Que;


Item * NewItem();
Que * InitQueue(Item *);
void AddQueue(Item *, Item *);
Item * DelQueue(Item *);
void RotateQ(Item *);
