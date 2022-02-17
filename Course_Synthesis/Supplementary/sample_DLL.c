/*
 * Doubly linked list implementation from Moni_Lab3 (own implementation).
 * 
 * The purpose of the tutorial was used to understand the functioning of a doubly linked list
 * 
 * No part of this code is used for the actual implementation of the course synthesis.
 * 
 * USED ONLY FOR UNDERSTANDING PURPOSE!
 */


// 1. Creating a doubly linked list with different operations:

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// initialize
struct node { 
	int data;
	struct node* next;
	struct node* prev;
}; 

// creating a global variables that will store addresses for the head  node

struct node* head = NULL;

// Construct a new node and returning a pointer to it
struct node* getNewNode (int x) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

// Operation: append to the head of the list
void enqueueHead (int x) {
	struct node* newNode = getNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}

// Operation: append to the tail of the list
void enqueueTail (int x) {
	struct node* temp = head;
	struct node* newNode = getNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	//we go to the last node
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}

// printing elements from the head
void print(){
	struct node* temp = head;
	while(temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

// Operation: remove elements from the list
void dequeueNode() {
	struct node* temp = head; //since queue is FIFO
	if(head == NULL) {
		printf("Empty queue!\n");
		return;
	} 
	else {
		head = head->next;
	}
	free(temp);
}

// Operation: add an element to a specific position in a list
void insertNode (int data, int pos) {
	struct node *newNode, *temp;
	newNode = (struct node*)malloc(sizeof(struct node));
	
	if(newNode == NULL) {
		return;
	}
	else {
		//linking the data
		newNode->data = data;
		newNode->next = NULL;
		temp = head;

		//going to the n-1 position
		for(int i = 2; i <= pos-1; i++) {
			temp = temp->next;
			if(temp == NULL) {
				return;
			}
		}
		if(temp != NULL) {
			//link the address to the new node
			newNode->next = temp->next;

			//link the address of the n-1 node
			temp->next = newNode;
		}
	}
}

//Operation: return the number of items in the list
int countNodes() {
	int count = 0;
	struct node *temp;
	temp = head;

	while(temp != NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}

// search an element in the doubly linked list
// Operation: return the item at a specific position in a list
bool  search(int pos) {
        int index;  
        struct node *currentNode;
        index = 0;
        currentNode = head;

        // iteration till the last element to find the element
        while(currentNode != NULL && currentNode->data != pos) {
		return index;

        index++;
        currentNode = currentNode->next;
        }
	//element not found
        return false;
}
	 
// Operation: Queue specific: returns an element from the front of the list
int frontElement() { 
	if(head == NULL) {
		printf("Empty queue!\n");
                return 0;
        }
	return head->data;
}

// Operation: return true if the element is in the list
bool contains(struct node* head, int x) {
	
	//initialize current node
	struct node* current = head;
	while(current != NULL) {
		if(current->data == x) {
		return true;
	}
	current = current->next;
	}
	return false;
}

// Operation: to check if the list is empty
bool IsEmpty() {
	if(head == NULL) {
		printf("There is nothing here! Goodbye!\n");
		return true;
	}
	return false;
}

int main() {
        
        enqueueTail(2);
        print();
        enqueueTail(4);
        print();
        enqueueHead(6);
        print();
        enqueueHead(8);
        print();
        dequeueNode();
        print();
        dequeueNode();
        print();
        dequeueNode();
        print();
        dequeueNode();
        print();
        dequeueNode();
        print();
        IsEmpty();
	return 0;

}