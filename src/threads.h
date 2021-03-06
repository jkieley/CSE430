/*
 ============================================================================
 Name        : operating-systems-project-3.c
 Author      : James Kieley, Alexis Montiel
 ============================================================================
 */

#ifndef THREADS_H_
#define THREADS_H_

#include <stdlib.h>
#define _XOPEN_SOURCE 600
#include <ucontext.h>
#include "q.h"


void start_thread(void(*function)(void), const char *);
void run();
void yield();

void start_thread(void(*function)(void), const char * name)
{ // begin pseudo code
	
	//allocate a stack(via malloc) of a certain size(choose 8192)
	void *s = malloc(8192);
	//allocate a TCB(via malloc)
    TCB_t * item = NewItem();

    //call init_TCB with appropriate arguments
	init_TCB(item, function, s, 8192,name);
	//call addQ to add this TCB into the �RunQ� which is a global header pointer
    AddQueue(&RunQ, &item);
    printQue(&RunQ);
	//end pseudo code
}

void run()
{   // real code
	ucontext_t parent;     // get a place to store the main context, for faking
	getcontext(&parent);   // magic sauce
	swapcontext(&parent, &(RunQ->context));  // start the first thread
    
}

void yield() // similar to run
{
    ucontext_t * current;
    ucontext_t * next;
    
    current = &RunQ->context;
    
//	rotate the run Q;
    RotateQ(&RunQ);
//	swap the context, from previous thread to the thread pointed to by RunQ
    next = &RunQ->context;
    swapcontext(current,next);
}


#endif
