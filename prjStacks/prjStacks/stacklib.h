#pragma once
#include<stdio.h>
#include<malloc.h>

#define MAX 50

#define true 1
#define false 0
typedef int bool;
typedef int KEYTYPE;

typedef struct {
	KEYTYPE key;
}Register;

typedef struct aux {
	Register reg;
	struct aux* next;
}Element;

typedef Element* POINTER;

typedef struct {
	POINTER top;
}DynamicStack;

typedef struct {
	Register tabElem[MAX];
	int top;
}StaticStack;

// Initialization 
void initializeStaticStack(StaticStack* nStack) {
	nStack->top = -1;
}

// Initialization 
void initializeDynamicStack(DynamicStack* nStack) {
	nStack->top = NULL;
}

// Numbers of elements (Size)
int findNbElemDynamicStack(DynamicStack* nStack) {
	POINTER end = nStack->top;
	int nbElem = 0;
	while (end != NULL) {
		nbElem++;
		end = end->next;
	}
	return nbElem;
}

// Exibition
void displayStaticStack(StaticStack* nStack) {
	for (int indx = nStack->top; indx >= 0; indx--)
		printf("%i \n", nStack->tabElem[indx].key);
}

void displayDynamicStack(DynamicStack* nStack) {
	POINTER end = nStack->top;
	while (end != NULL) {
		printf("%i \n", end->reg.key);
		end = end->next;
	}
}

// Inserting elements (PUSH)
bool pushStaticStack(StaticStack* nStack, Register nReg) {
	if (nStack->top >= MAX - 1)// Test for available position
		return false; // It is full!

	nStack->top = nStack->top++;
	nStack->tabElem[nStack->top] = nReg;
	return true;
}

// Inserting elements (PUSH)
bool pushDynamicStack(DynamicStack* nStack, Register nReg) {
	POINTER newElem = (POINTER)malloc(sizeof(Element));
	newElem->reg = nReg;
	newElem->next = nStack->top;
	nStack->top = newElem;
	return true;
}

// Excluding/Deleting (POP)
bool popStaticStack(StaticStack* nStack, Register* nReg) {
	if (nStack->top == -1)
		return false;

	*nReg = nStack->tabElem[nStack->top];
	nStack->top = nStack->top--;
	return true;
}

// Excluding/Deleting (POP)
bool popDynamicStack(DynamicStack* nStack, Register* nReg) {
	if (nStack->top == NULL)
		return false;

	*nReg = nStack->top->reg;
	POINTER delElem = nStack->top;
	nStack->top = nStack->top->next;
	free(delElem);
	return true;
}

// Reinicialization
void restartStaticStack(StaticStack* nStack) {
	nStack->top = -1;
}

// Reinicialization
void restartDynamicStack(DynamicStack* nStack) {
	POINTER delElem;
	POINTER position = nStack->top;

	while (position != NULL) {
		delElem = position;
		position = position->next;
		free(delElem);
	}
	nStack->top = NULL;
}