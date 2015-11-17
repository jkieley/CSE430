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

int main(void) {

	InitQueue(&RunQ);
	InitSem(&sem, 0);

    printf("\nstarting...\n");
    const char * loop1Name = "loop1";
    start_thread(*loop1, loop1Name);

    const char * loop2Name = "loop2";
    start_thread(*loop2, loop2Name);

    const char * loop3Name = "loop3";
    start_thread(*loop3, loop3Name);

    const char * loop4Name = "loop4";
    start_thread(*loop4, loop4Name);
    
    const char * loop5Name = "loop5";
    start_thread(*loop5, loop5Name);

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
        printf("\nloop1! %d",i);
        //printf("globalCounter! %d\n",globalCounter);
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
        printf("\nloop2! %d",i);
        //printf("globalCounter! %d\n",globalCounter);
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
        printf("\nloop3! %d",i);
        //printf("globalCounter! %d\n",globalCounter);
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
        printf("\nloop4! %d",i);
        //printf("globalCounter! %d\n",globalCounter);
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
        printf("\nloop5! %d",i);
        //printf("globalCounter! %d\n",globalCounter);
        V(&sem);
    }
}


