//
//  main.cpp
//  readers_writers
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
#include <unistd.h>

#define WRITERS   1
#define READERS   2

int readcount, writecount; //(initial value = 0)
sem_t readerMutex, writerMutex;
sem_t reader_open_door, readTry;
sem_t resourse;

void *reader(void *arg){
    
    while (true) {
        sem_wait(&reader_open_door);
        sem_wait(&readTry);
        sem_wait(&readerMutex);
        readcount++;
        if (readcount == 1) {
            sem_wait(&resourse);
        }
        sem_post(&readerMutex);
        sem_post(&readTry);
        sem_post(&reader_open_door);
        
        printf("Reading...\n");
        
        sem_wait(&readerMutex);
        readcount--;
        if (!readcount) {
            sem_post(&readTry);
        }
        sem_post(&readerMutex);
        
    }
    
    pthread_exit(0);
    
}

void *writer(void *arg){
    
    while(true){
        sem_wait(&writerMutex);
        writecount++;
        if (writecount==1) {
            sem_wait(&readTry);
        }
        sem_post(&writerMutex);
        
        sem_wait(&resourse);
        printf("Writing...");
        sem_post(&resourse);
        
        sem_wait(&writerMutex);
        writecount--;
        if (writecount==0) {
            sem_post(&readTry);
        }
        sem_post(&writerMutex);
        
    }
    
    pthread_exit(0);
}

int main()
{
    pthread_t thread_W[WRITERS], thread_R[READERS];
    
    readcount = 0;
    writecount = 0;
    
    sem_init(&readerMutex, 0, 1);
    sem_init(&writerMutex, 0, 1);
    sem_init(&reader_open_door, 0, 1);
    sem_init(&readTry, 0, 1);
    sem_init(&resourse, 0, 1);
    
    for (int i=0; i<WRITERS; i++) {
        pthread_create(&thread_W[i], NULL, writer, (void*)i);
    }
    
    for (int i=0; i<READERS; i++) {
        pthread_create(&thread_R[i], NULL, reader, (void*)i);
    }
    
    //(void) pthread_join(thread_P, NULL);
    //(void) pthread_join(thread_C, NULL);
    
    //printf("Ended!");
    
    pthread_exit(NULL);
}
