/*
 ============================================================================
 Name        : operating-systems-project-3.c
 Author      : James Kieley, Alexis Montiel
 ============================================================================
 */

#ifndef tcb_h
#define tcb_h

#include <ucontext.h>

typedef struct TCB_t {
    struct TCB_t     *next;
    struct TCB_t     *prev;
    const char       *name;
    ucontext_t      context;
} TCB_t;



void init_TCB (TCB_t *tcb, void *function, void *stackP, int stack_size, const char * name)
{
    memset(tcb, '\0', sizeof(TCB_t));       // wash, rinse
    getcontext(&tcb->context);              // have to get parent context, else snow forms on hell
    tcb->context.uc_stack.ss_sp = stackP;
    tcb->context.uc_stack.ss_size = (size_t) stack_size;
    makecontext(&tcb->context, function, 0);// context is now cooked
    tcb->name = name;
}


#endif /* tcb_h */
