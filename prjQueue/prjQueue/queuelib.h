#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#define MAX 3 // Only 3 positions to make the test easier

typedef int Keytype;

typedef struct {
	Keytype key;
}Register;

typedef struct {
	Register tabElem[MAX];
	int start;
	int nbElem;
}StaticQueue;

typedef struct aux {
	Register reg;
	struct aux* next;
}Element, * Pointer;

typedef struct {
	Pointer start;
	Pointer end;
}DynamicQueue;

// Initialization
void initializeStaticQueue(StaticQueue* nQueue) {
	nQueue->start = 0;
	nQueue->nbElem = 0;
}

// Initialization
void initializeDynamicQueue(DynamicQueue* nQueue) {
	nQueue->start = NULL;
	nQueue->end = NULL;
}

// Size
int countNbElemStaticQueue(StaticQueue* nQueue) {
	return nQueue->nbElem;
}

// Size
int countNbElemDynamicQueue(DynamicQueue* nQueue) {
	Pointer end = nQueue->start;
	int nbElem = 0;
	while (end != NULL) {
		nbElem++;
		end = end->next;
	}
	return nbElem;
}

// Exhibition
void displayStaticQueue(StaticQueue* nQueue) {
	int indx = nQueue->start;
	for (int tmp = 0; tmp < nQueue->nbElem; tmp++) {
		printf("%i\n", nQueue->tabElem[indx].key);
		indx = (indx + 1) % MAX; // Because FIFO, this line ensures all elements will be display in the correct order.
	}
}

// Exhibition
void displayDynamicQueue(DynamicQueue* nQueue) {
	Pointer end = nQueue->start;
	while (end != NULL) {
		printf("%i\n", end->reg.key);
		end = end->next;
	}
}

// Inserting one element
bool insertStaticQueue(StaticQueue* nQueue, Register nReg) {
	if (nQueue->nbElem >= MAX)
		return false;

	int position = (nQueue->start + nQueue->nbElem) % MAX;
	nQueue->tabElem[position] = nReg;
	nQueue->nbElem++;
	return true;
}

// Inserting one element
bool insertDynamicQueue(DynamicQueue* nQueue, Register nReg) {
	Pointer newElem = (Pointer)malloc(sizeof(Element));
	newElem->reg = nReg;
	newElem->next = NULL;

	if (nQueue->start == NULL)
		nQueue->start = newElem;
	else
		nQueue->end->next = newElem;

	nQueue->end = newElem;
	return true;
}

// Exclusion of one element (FIFO)
bool delOneElemStaticQueue(StaticQueue* nQueue, Register* nReg)
{
	if (nQueue->nbElem == 0)
		return false;

	// It isn't necessary delete, so just make the position available
	*nReg = nQueue->tabElem[nQueue->start];
	nQueue->start = (nQueue->start + 1) % MAX;
	nQueue->nbElem--;
	return true;
}

// Exclusion of one element (FIFO)
bool delOneElemDynamicQueue(DynamicQueue* nQueue, Register* nReg)
{
	if (nQueue->start == NULL)
		return false;

	*nReg = nQueue->start->reg;
	Pointer delElem = nQueue->start;
	nQueue->start = nQueue->start->next;
	free(delElem);

	// If we are deleting the unique element, we must adjust the pointers 
	if (nQueue->start == NULL)
		nQueue->end = NULL;
	return true;
}

// Restarting a Queue
void restartStaticQueue(StaticQueue* nQueue) {
	initializeStaticQueue(nQueue);
}

// Restarting a Queue
void restartDynamicQueue(DynamicQueue* nQueue) {
	Pointer end = nQueue->start;
	while(end != NULL) {
		Pointer delElem = end;
		end = end->next;
		free(delElem);
	}
	nQueue->start = NULL;
	nQueue->end = NULL;
}