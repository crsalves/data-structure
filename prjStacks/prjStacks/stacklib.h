#pragma once
#include<stdio.h>

#define MAX 50

#define true 1
#define false 0
typedef int bool;
typedef int KEYTYPE;

typedef struct {
	KEYTYPE key;
}Register;

typedef struct {
	Register tabElem[MAX];
	int top;
}Stack;

// Initialization 
void initialize(Stack* nStack) {
	nStack->top = -1;
}

// Exibition
void displayStack(Stack* nStack) {
	for (int indx = nStack->top; indx >= 0; indx--)
		printf("%i \n", nStack->tabElem[indx].key);
}

// Inserting elements (PUSH)
bool pushStaticStack(Stack* nStack, Register nReg) {
	if (nStack->top >= MAX - 1)// Test for available position
		return false; // It is full!

	nStack->top = nStack->top++;
	nStack->tabElem[nStack->top] = nReg;
	return true;
}

// Excluding/Deleting (POP)
bool popStaticStack(Stack* nStack, Register* nReg) {
	if (nStack->top == -1)
		return false;

	*nReg = nStack->tabElem[nStack->top];
	nStack->top = nStack->top--;
	return true;
}

// Reinicialization
void restartStaticStack(Stack* nStack) {
	nStack->top = -1;
}