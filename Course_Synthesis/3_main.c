#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "3_concurrentLinkedHashMap.c"

int main1() {
    clock_t start1, end1;
    clock_t start2, end2;
    clock_t start3, end3;
    double cpuTimeUsed1;
    double cpuTimeUsed2;
    double cpuTimeUsed3;

    // first make IDS:
    pthread_t threadIDs[3];

    linkedHashMap_t* linkedHashMap = createLinkedHashMap( 8, 0.5);

    // create a thread
    pthread_create(&threadIDs[0],NULL,put,NULL);
    pthread_create(&threadIDs[1],NULL,removes,NULL); 
    pthread_create(&threadIDs[2],NULL,get,NULL); 

    // 3. Join a thread. 
    pthread_join(threadIDs[0], NULL);
    pthread_join(threadIDs[1], NULL);
    pthread_join(threadIDs[2], NULL);

    start1 = clock();
    put(linkedHashMap, 5, 100);
    end1 = clock();
    cpuTimeUsed1 = ((double) (end1 - start1) / CLOCKS_PER_SEC);

    put(linkedHashMap, 10, 200);
    put(linkedHashMap, 15, 209);
    put(linkedHashMap, 30, 300);
    put(linkedHashMap, 20, 324);

    start2 = clock();
    removes(linkedHashMap, 5);
    end2 = clock();
    cpuTimeUsed2 = ((double) (end2 - start2) / CLOCKS_PER_SEC);

    start3 = clock();
    get(linkedHashMap, 15);
    end3 = clock();
    cpuTimeUsed3 = ((double) (end3 - start3) / CLOCKS_PER_SEC);

    printf("put() took %f seconds to execute \n", cpuTimeUsed1); 
    printf("removes() took %f seconds to execute \n", cpuTimeUsed2);
    printf("get() took %f seconds to execute \n", cpuTimeUsed3);
    return 0;
}
