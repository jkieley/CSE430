#ifndef semaphore_h
#define semaphore_h

#include "threads.h"

void InitSem(sempahore_t ** semaphore, int value);
void P(sempahore_t **  semaphore);
void V(sempahore_t ** semaphore);

typedef struct sempahore_t {
	int count;
    struct TCB_t *que;
} sempahore_t;

sempahore_t * sempahore;

void InitSem(sempahore_t ** semaphore, int value)
{
	*semaphore->count = value;
	*semaphore->que = NULL;
}

void P(sempahore_t **  semaphore)
{
	TCB_t * this;
	semaphore->count--;
	if(semaphore->count < 0){
		this = DelQueue(&semaphore->que);
		AddQ(&this,&semaphore->que);
		swapcontext(&this->context,&semaphore->que->context);
	}
}

void V(sempahore_t **  semaphore)
{
	TCB_t * this;
	semaphore->count++;
	if(semaphore->count < 0){
		this = DelQueue(&semaphore->que);
		AddQ(&this,&(*semaphore->que));
		yield();
	}

}


#endif /* tcb_h */
