/*
 ============================================================================
 Name        : operating-systems-project-3.c
 Author      : James Kieley, Alexis Montiel
 ============================================================================
 */


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
	// printf("\n *******P******* semaphore inc count: %d", (*semaphore)->count);
	if((*semaphore)->count < 0){
	//if(0){

		// printf("\nbefore");
		//  printf("\n::Semaphore Que::");
		//  printQue(&(*semaphore)->que);
		//  printf("\n::Run Que::");
		//  printQue(&RunQ);


		this = DelQueue(&RunQ);
		AddQueue(&(*semaphore)->que,&this);

		// printf("\nS length: %d", getLength(&(*semaphore)->que));
		// printf("\nR length: %d", getLength(&RunQ));


		// if(RunQ == NULL){
		// 	printf("breaks here?");
		// 	return;
		// }

		// printf("\nafter");
		// printf("\n::Semaphore Que::");
		// printQue(&(*semaphore)->que);
		// printf("\n::Run Que::");
		// printQue(&RunQ);

//		printf("from: %s, to: %s\n", this->name, RunQ->name);
		swapcontext(&this->context,&RunQ->context);
	}

}

void V(semaphore_t **  semaphore)
{
	TCB_t * this;
	(*semaphore)->count++;
	// printf("\n *******V******* semaphore dec count: %d", (*semaphore)->count);
	if((*semaphore)->count <= 0){
//	if(1){

		 // printf("\nbefore");
		 // printf("\n::Semaphore Que::");
		 // printQue(&(*semaphore)->que);
		 // printf("\n::Run Que::");
		 // printQue(&RunQ);


		this = DelQueue(&(*semaphore)->que);
		AddQueue(&RunQ,&this);

		// printf("\nS length: %d", getLength(&(*semaphore)->que));
		// printf("\nR length: %d", getLength(&RunQ));

		// printf("\nafter");
		// printf("\n::Semaphore Que::");
		// printQue(&(*semaphore)->que);
		// printf("\n::Run Que::");
		// printQue(&RunQ);


	}
	yield();
}


#endif /* tcb_h */
