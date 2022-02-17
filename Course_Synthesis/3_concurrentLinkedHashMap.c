/*
 * LRU (least recently used)- cache implementation using a linked HashMap
 * 
 * After the implementation, modifying the code to make it a concurrent version that should help in improving performance
 * rather than the usual queue of one task finishing after the other one
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "3_concurrentLinkedHashMap.h"

// two mutex variables
pthread_mutex_t mutex1 = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_COND_INITIALIZER;

linkedHashMap_t* createLinkedHashMap(int capacity, double loadFactor) {
    
    // allocating the values
    linkedHashMap_t* linkedHashMap = (linkedHashMap_t*) malloc(sizeof(linkedHashMap_t));
    linkedHashMap->size = capacity / loadFactor;
    linkedHashMap->capacity = capacity;
    linkedHashMap->loadFactor = loadFactor;

    linkedHashMap->doublly = (doubllyLL_t*) malloc(sizeof(doubllyLL_t)*linkedHashMap->size);
    
    // LRU - cache intializing the oldest and newest values
    linkedHashMap->oldest = NULL;
    linkedHashMap->newest = NULL;
    linkedHashMap->currentCapacity = 0;
    
    for (int i = 0; i < linkedHashMap->size; i++) {
        linkedHashMap->doublly[i].head = NULL;
        linkedHashMap->doublly[i].tail = NULL;
    }

    return linkedHashMap;
}

// Making a node in a segment that contains the key - value pairs
node_t* createNode(int key, int value) {
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->before = NULL;
    node->after = NULL;
    node->afterForSegment = NULL;
    node->beforeForSegment = NULL;

    node->pairs = (pair_t*)malloc(sizeof(pair_t));
    node->pairs->key = key;
    node->pairs->value = value;

    return node;
}

/*
 * Note: all the 4 structures have been intialized
 */ 

// finding the node on the segment
node_t* findNode(doubllyLL_t* segment, int key) {
    // null checks are the best!
    if (segment->head == NULL) {
        return NULL;
    }
    else {
        node_t* current = segment->head;
        while (current->pairs->key != key) {
            current = current->afterForSegment;
            if (current == NULL) {
                return NULL;
            }
        }
        return current;
    }
}
// deletes an entire node in the segment
void deleteNode(doubllyLL_t* segment, node_t* current) {
    // Null checks are my favorite, this is the condition when segment only has 1 key - value pair
    if ( current == segment->head && current == segment->tail) {
        segment->head = NULL;
        segment->tail = NULL;
    }
    else if (current == segment->head) {
        // switching begins, switched the link from the head segment
        segment->head = current->afterForSegment;
        segment->head->beforeForSegment = NULL;
    }
    else if (current == segment->tail) {
        // switching begins, switched the link from the tail segment
        segment->tail = current->beforeForSegment;
        segment->tail->afterForSegment = NULL;
    }
    else {
        current->beforeForSegment->afterForSegment = current->afterForSegment;
        current->afterForSegment->beforeForSegment = current->beforeForSegment;
    }
}

// deleting from the HashMap: from the main structure, for the LRU - cache
void deleteLinkedList(linkedHashMap_t* linkedHashMap, node_t* current) {
    // LRU deletion of memory when only 1 segment is present
    if ( current == linkedHashMap->oldest && current == linkedHashMap->newest) {
        linkedHashMap->oldest = NULL;
        linkedHashMap->newest = NULL;
    }
    else if (current == linkedHashMap->oldest) {
        // switching begins, switched the link from the oldest
        linkedHashMap->oldest = linkedHashMap->oldest->after;
        linkedHashMap->oldest->before = NULL;
    }
    else if (current == linkedHashMap->newest) {
        // switching begins, switched the link from the newest
        linkedHashMap->newest = linkedHashMap->newest->before;
        linkedHashMap->newest->after = NULL;
    }
    else {
        current->before->after = current->after;
        current->after->before = current->before;
    }
}

// hashCode function to get the index for the placement on the HashTable
int hashCode(int key, int size) {
    return key % size;
}

// MAIN FUNCTION OF THE LINKED HASHMAP
void removes(linkedHashMap_t* linkedHashMap, int key) {
    int index = hashCode(key, linkedHashMap->size);

    pthread_mutex_lock(&mutex1);
    doubllyLL_t* segment = &linkedHashMap->doublly[index];
    pthread_mutex_unlock(&mutex1);

    node_t* current = findNode(segment, key);

    if (current == NULL) {
        return;
    }
    else {
        deleteNode(segment, current);
        deleteLinkedList(linkedHashMap, current);
        free(current);
        current = NULL;
    }
}

// MAIN FUNCTION OF THE LINKED HASHMAP
void put(linkedHashMap_t* linkedHashMap, int key, int value) {
    int indexValue = hashCode(key, linkedHashMap->size);

    pthread_mutex_unlock(&mutex1);
    doubllyLL_t* segment = &linkedHashMap->doublly[indexValue];
    pthread_mutex_unlock(&mutex1);

    node_t* current = createNode(key, value);

    if (linkedHashMap->currentCapacity > linkedHashMap->capacity) {
        removes(linkedHashMap,key);
    }
}

// MAIN FUNCTION OF THE LINKED HASHMAP
pair_t* get(linkedHashMap_t* linkedHashMap, int key) {
    int index = hashCode(key, linkedHashMap->size);

    pthread_mutex_unlock(&mutex1);
    doubllyLL_t* segment = &linkedHashMap->doublly[index];
    pthread_mutex_unlock(&mutex1);

    node_t* current = findNode(segment, key);

    if (current == NULL) {
        return NULL;
    }

    return current->pairs;
}


void print(linkedHashMap_t* linkedHashMap) {	
   for(int i = 0; i < linkedHashMap->size; i++) {
	
    if(linkedHashMap != NULL)
        printf(" (%d,%d)",linkedHashMap->oldest->pairs->key,
                            linkedHashMap->oldest->pairs->value);
    }	
   printf("\n");
}


int main() {
    return 0;
}
