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


int main(void) {
    
    InitQueue(&RunQ);
    
    start_thread(*loop1);
    start_thread(*loop2);
    start_thread(*loop3);
    start_thread(*loop4);
    start_thread(*loop5);
    
    
    return EXIT_SUCCESS;
}

void loop1(){
    int i=0;
    while (1) {
        if(i > 100){
            i = 0;
        }
        yield();
        i++;
        printf("loop1! %d",i);
    }
}

void loop2(){
    int i=0;
    while (1) {
        if(i > 100){
            i = 0;
        }
        yield();
        i++;
        printf("loop2! %d",i);
    }
}

void loop3(){
    int i=0;
    while (1) {
        if(i > 100){
            i = 0;
        }
        yield();
        i++;
        printf("loop3! %d",i);
    }
}

void loop4(){
    int i=0;
    while (1) {
        if(i > 100){
            i = 0;
        }
        yield();
        i++;
        printf("loop4! %d",i);
    }
}

void loop5(){
    int i=0;
    while (1) {
        if(i > 100){
            i = 0;
        }
        yield();
        i++;
        printf("loop5! %d",i);
    }
}


