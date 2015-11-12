/*
 ============================================================================
 Name        : operating-systems-project-1.c
 Author      : James Kieley, Alexis Montiel
 Version     :
 Copyright   : Your copyright notice
 Description : Contains the main() function as intructed for Project 2. Please ensure that only 
               one main function is included at compile and run time. 
 ============================================================================
 */

#include <stdio.h>
#include "threads.h"
#include "q.h"
#include "tcb.h"
#include <ucontext.h>
#include "semaphore.h"

void loop1();
void loop2();
void loop3();
void loop4();
void loop5();

int globalCounter = 0;
semaphore_t * sem;

int main(void) {

	InitQueue(&RunQ);
	InitSem(&sem, 0);

    printf("\nstarting...\n");
    start_thread(*loop1);
    start_thread(*loop2);
    start_thread(*loop3);
    start_thread(*loop4);
    start_thread(*loop5);
    
    run();
    return EXIT_SUCCESS;
}

void loop1(){

	int i=0;
    while (1) {
    	P(&sem);
    	//start of CS
        if(i > 100){
            i = 0;
        }

        if(globalCounter > 1000){
            globalCounter = 0;
        }

        i++; // local variable
        globalCounter++; // global variable
        printf("loop1! %d\n",i);
        printf("globalCounter! %d\n",globalCounter);
        V(&sem);
        //ending CS
        printf("Sleep1");
        V(&sem);
    }
}

void loop2(){

	int i=0;
    while (1) {
    	P(&sem);
    	//start of CS
        if(i > 100){
            i = 0;
        }

        if(globalCounter > 1000){
            globalCounter = 0;
        }

        i++; // local variable
        globalCounter++; // global variable
        printf("loop2! %d\n",i);
        printf("globalCounter! %d\n",globalCounter);
        V(&sem);
        //ending CS
        printf("Sleep2");
        V(&sem);
    }
}

void loop3(){

	int i=0;
    while (1) {
    	P(&sem);
    	//start of CS
        if(i > 100){
            i = 0;
        }

        if(globalCounter > 1000){
            globalCounter = 0;
        }

        i++; // local variable
        globalCounter++; // global variable
        printf("loop3! %d\n",i);
        printf("globalCounter! %d\n",globalCounter);
        V(&sem);
        //ending CS
        printf("Sleep3");
        V(&sem);
    }
}

void loop4(){

	int i=0;
    while (1) {
    	P(&sem);
    	//start of CS
        if(i > 100){
            i = 0;
        }

        if(globalCounter > 1000){
            globalCounter = 0;
        }

        i++; // local variable
        globalCounter++; // global variable
        printf("loop4! %d\n",i);
        printf("globalCounter! %d\n",globalCounter);
        V(&sem);
        //ending CS
        printf("Sleep4");
        V(&sem);
    }
}

void loop5(){

	int i=0;
    while (1) {
    	P(&sem);
    	//start of CS
        if(i > 100){
            i = 0;
        }

        if(globalCounter > 1000){
            globalCounter = 0;
        }

        i++; // local variable
        globalCounter++; // global variable
        printf("loop5! %d\n",i);
        printf("globalCounter! %d\n",globalCounter);
        V(&sem);
        //ending CS
        printf("Sleep5");
        V(&sem);
    }
}


