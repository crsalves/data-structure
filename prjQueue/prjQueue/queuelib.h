#pragma once
#include<stdio.h>
#include<stdbool.h>
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

// Initialization
void initializeStaticQueue(StaticQueue* nQueue) {
	nQueue->start = 0;
	nQueue->nbElem = 0;
}

// Size
int countNbElemStaticQueue(StaticQueue* nQueue) {
	return nQueue->nbElem;
}

// Exhibition
void displayStaticQueue(StaticQueue* nQueue) {
	int indx = nQueue->start;
	for (int tmp = 0; tmp < nQueue->nbElem; tmp++) {
		printf("%i\n", nQueue->tabElem[indx].key);
		indx = (indx + 1) % MAX; // Because FIFO, this line ensures all elements will be display in the correct order.
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

// Restarting a Queue
void restartStaticQueue(StaticQueue* nQueue) {
	initializeStaticQueue(nQueue);
}