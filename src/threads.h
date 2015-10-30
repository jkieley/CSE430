#ifndef THREADS_H_
#define THREADS _H_

#include <stdlib.h>
#include "q.h"

void start_thread(void(*function)(void));
void run();
void yield();

void start_thread(void(*function)(void))
{ // begin pseudo code
	
	//allocate a stack(via malloc) of a certain size(choose 8192)
	void *s = malloc(8192);
	//allocate a TCB(via malloc)
	TCB_t * item = (TCB_t*)malloc(sizeof(TCB_t));
	//call init_TCB with appropriate arguments
	init_TCB(item, function, s, 8192);
	//call addQ to add this TCB into the “RunQ” which is a global header pointer
	RunQ->addQueue(RunQ, item)
	//end pseudo code
}

void run()
{   // real code
	ucontext_t parent;     // get a place to store the main context, for faking
	getcontext(&parent);   // magic sauce
	swapcontext(&parent, &(RunQ->conext));  // start the first thread
}

void yield() // similar to run
{
	rotate the run Q;
	swap the context, from previous thread to the thread pointed to by RunQ
}


#endif