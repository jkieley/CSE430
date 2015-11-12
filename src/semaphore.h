#ifndef semaphore_h
#define semaphore_h

#include "threads.h"
#include "q.h"

typedef struct sempahore_t {
	int count;
    struct TCB_t * que;
} semaphore_t;

void InitSem(semaphore_t ** semaphore, int value);
void P(semaphore_t **  semaphore);
void V(semaphore_t ** semaphore);

void InitSem(semaphore_t ** semaphore, int value)
{
	(*semaphore)->count = value;
    (*semaphore)->que = NULL;
}

void P(semaphore_t **  semaphore)
{
	TCB_t * this;
	(*semaphore)->count--;
	if((*semaphore)->count < 0){
		this = DelQueue(&(*semaphore)->que);
		AddQueue(&this,&(*semaphore)->que);
		swapcontext(&this->context,&(*semaphore)->que->context);
	}
}

void V(semaphore_t **  semaphore)
{
	TCB_t * this;
	(*semaphore)->count++;
	if((*semaphore)->count < 0){
		this = DelQueue(&(*semaphore)->que);
		AddQueue(&this,&(*semaphore)->que);
		yield();
	}

}


#endif /* tcb_h */