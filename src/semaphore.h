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

semaphore_t * sem;

void InitSem(semaphore_t ** semaphore, int value)
{
	*semaphore = (semaphore_t *) malloc(sizeof(semaphore_t));
	(*semaphore)->count = value;
    InitQueue(&(*semaphore)->que);
}

void P(semaphore_t **  semaphore)
{
	TCB_t * this;
	(*semaphore)->count--;
	if((*semaphore)->count < 0){
		this = DelQueue(&RunQ);
		AddQueue(&(*semaphore)->que,&this);
		swapcontext(&this->context,&RunQ->context);
	}
}

void V(semaphore_t **  semaphore)
{
	TCB_t * this;
	(*semaphore)->count++;
	if((*semaphore)->count < 0){
		this = DelQueue(&(*semaphore)->que);
		AddQueue(&RunQ,&this);
		yield();
	}

}


#endif /* tcb_h */
