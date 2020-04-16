#pragma once
#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
typedef int keytype;

typedef struct {
	keytype key;
}Register;

typedef struct auxElem {
	Register reg;
	struct auxElem* prev;
	struct auxElem* next;
}Element;

typedef Element* Pointer;

typedef struct {
	Pointer head;
}Deque;

// Initialization
void initializeDeque(Deque* nDeque) {
	nDeque->head = (Pointer)malloc(sizeof(Element));
	nDeque->head->next = nDeque->head;
	nDeque->head->prev = nDeque->head;
}

// Size (number of elements)
// 1º Approach
int countNbElemDeque1(Deque* nDeque) {
	Pointer end = nDeque->head->next;

	int nbElem = 0;
	while (end != nDeque->head) {
		nbElem++;
		end = end->next;
	}
	return nbElem;
}

// 2º Approach
int countNbElemDeque2(Deque* nDeque) {
	Pointer end = nDeque->head->prev;

	int nbElem = 0;
	while (end != nDeque->head) {
		nbElem++;
		end = end->prev;
	}
	return nbElem;
}

// Display all elements (back-to-front)
void displayDeque(Deque* nDeque) {
	Pointer end = nDeque->head->prev;
	while (end != nDeque->head) {
		printf("%i\n", end->reg.key);
		end = end->prev;
	}
}

// Inserting one element
bool insertDequeEnd(Deque* nDeque, Register nReg) {
	Pointer newElem = (Pointer)malloc(sizeof(Element));

	newElem->reg = nReg;
	newElem->next = nDeque->head;
	newElem->prev = nDeque->head->prev;

	nDeque->head->prev = newElem;
	newElem->prev->next = newElem;

	return true;
}

// Excluding/ Deleting one specific element
// The search starts from the front in this implementation
bool delElemDeque(Deque* nDeque, Register* reg) {
	if (nDeque->head->next == nDeque->head) // test empty deque
		return false;

	Pointer delElem = nDeque->head->next;
	*reg = delElem->reg;
	nDeque->head->next = delElem->next;
	delElem->next->prev = nDeque->head;
	free(delElem);
	return true;
}

// Restarting Deque
void restartDeque(Deque* nDeque) {
	Pointer end = nDeque->head->next;
	while (end != nDeque->head) {
		Pointer delElem = end;
		end = end->next;
		free(delElem);
	}
	nDeque->head->next = nDeque->head;
	nDeque->head->prev = nDeque->head;
}