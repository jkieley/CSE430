//
//  thread_test.c
//  operating.systems
//
//  Created by James Kieley on 10/29/15.
//  Copyright © 2015 James Kieley. All rights reserved.
//

#include <stdio.h>
#include "threads.h"
#include "q.h"
#include "tcb.h"
#include <ucontext.h>

void loop1();
void loop2();
void loop3();
void loop4();
void loop5();

int globalCounter = 0;

int main(void) {
    
    InitQueue(&RunQ);
    
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
        if(i > 100){
            i = 0;
        }

        if(globalCounter > 1000){
            globalCounter = 0;
        }

        yield();
        i++; // local variable
        globalCounter++; // global variable
        printf("loop1! %d",i);
        printf("globalCounter! %d",globalCounter);
    }
}

void loop2(){
    int i=0;
    while (1) {
        if(i > 100){
            i = 0;
        }

        if(globalCounter > 1000){
            globalCounter = 0;
        }

        yield();
        i++; // local variable
        globalCounter++; // global variable
        printf("loop2! %d",i);
        printf("globalCounter! %d",globalCounter);
    }
}

void loop3(){
    int i=0;
    while (1) {
        if(i > 100){
            i = 0;
        }

        if(globalCounter > 1000){
            globalCounter = 0;
        }

        yield();
        i++; // local variable
        globalCounter++; // global variable
        printf("loop3! %d",i);
        printf("globalCounter! %d",globalCounter);
    }
}

void loop4(){
    int i=0;
    while (1) {
        if(i > 100){
            i = 0;
        }

        if(globalCounter > 1000){
            globalCounter = 0;
        }

        yield();
        i++; // local variable
        globalCounter++; // global variable
        printf("loop4! %d",i);
        printf("globalCounter! %d",globalCounter);
    }
}

void loop5(){
    int i=0;
    while (1) {
        if(i > 100){
            i = 0;
        }

        if(globalCounter > 1000){
            globalCounter = 0;
        }

        yield();
        i++; // local variable
        globalCounter++; // global variable
        printf("loop5! %d",i);
        printf("globalCounter! %d",globalCounter);
    }
}


