//
//  main.cpp
//  producer_consumer
//
//  Created by Danilo Mendes on 10/14/15.
//  Copyright (c) 2015 Danilo Mendes. All rights reserved.
//
/*
#include <iostream>
#include "semaphore_class.h"

int items[4];

Semaphore mutex(1);
pthread_mutex_t mut;

int main(int argc, const char * argv[]) {
    
    return 0;
}
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include </usr/include/semaphore.h>
#include <inttypes.h>
#include <time.h>

// for sleep
#include <unistd.h>

#define BUFFER_SIZE   4           /* total number of slots */
#define PRODUCERS   1
#define CONSUMERS   2

pthread_mutex_t mutex;
sem_t items;
sem_t spaces;

int itens[BUFFER_SIZE], produced, consumed;


void *Producer(void *arg){
    
    int i=1, item;
    intptr_t num = (intptr_t)arg;
    
    
    while (1){
        
        /* Produce item */
        //(srand(time(NULL)));
        //item = rand() % 20 + 1;
        item = i;
        sem_wait(&spaces);

        pthread_mutex_lock(&mutex);
        
            itens[produced] = item;
            produced = (produced+1)%BUFFER_SIZE;
            printf("[P%ld] Producing %d ...\n", num, item);
        /*
        for (int j=0; j<BUFFER_SIZE; j++) {
            printf("%d\t",itens[j]);
        }puts("");
        */
            fflush(stdout);
        

        pthread_mutex_unlock(&mutex);

        sem_post(&items);
        
        /* Interleave  producer and consumer execution */
        usleep(1e+5);
        i++;
    }
    pthread_exit(0);
}

void *Consumer(void *arg)
{
    int item;
    intptr_t num = (intptr_t)arg;
    
    while (1) {
        sem_wait(&items);
        pthread_mutex_lock(&mutex);
        
            item=itens[consumed];
            itens[consumed] = -1;
            consumed = (consumed+1)%BUFFER_SIZE;
            printf("[C%ld] Consuming  %d ...\n", num, item);
            fflush(stdout);
        

        pthread_mutex_unlock(&mutex);
        
        sem_post(&spaces);
        
        /* Interleave  producer and consumer execution */
        usleep(1e+5);
        
    }
    pthread_exit(0);
}

int main()
{
    pthread_t thread_P[PRODUCERS], thread_C[CONSUMERS];
    
    sem_init(&items, 0, 0);
    sem_init(&spaces, 0, BUFFER_SIZE);
    pthread_mutex_init(&mutex, NULL);
    
    for (int i=0; i<PRODUCERS; i++) {
        pthread_create(&thread_P[i], NULL, Producer, (void*)i);
    }
    
    for (int i=0; i<CONSUMERS; i++) {
        pthread_create(&thread_C[i], NULL, Consumer, (void*)i);
    }
    
    //(void) pthread_join(thread_P, NULL);
    //(void) pthread_join(thread_C, NULL);
    
    //printf("Ended!");
    
    pthread_exit(NULL);
}
