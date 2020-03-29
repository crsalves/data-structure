/*!	\file		Linked_List_Circular.c
	\author		Carla Alves
	\date		2020-03-29

	Dinamic implamentation of a linked linear list:
	1) Physically, the elements are spreadly stored in the computer memory;
	2) All elements have the address of the 'next element position', except the last element;
	3) It is necessary to know the 'first element position';
	4) Every new element, it allocates a space in memory dinamically;
*/

#include"stdio.h"
#include"stdbool.h"
#include"malloc.h"

typedef int KEYTYPE;

typedef struct {
	KEYTYPE key;
}Register;

typedef struct tmpReg {
	Register reg;
	struct tmpReg* nextPos;
}Element;

typedef Element* POINTER;

typedef struct {
	POINTER firstPos;
}List;

/*
	1) Initializing the list
*/
void initializeLinkListCircular(List* anyList) {
	anyList->firstPos = (POINTER)malloc(sizeof(Element));
	anyList->firstPos->nextPos = anyList->firstPos;
}

/*
	2) Displaying all elements stored in the list
*/
void displayLinkedListCircular(List* anyList) {
	POINTER end = anyList->firstPos->nextPos;
	int counter = 0;// Just for view purposes (to show the index for the user)
	while (end != NULL) {
		printf("[%i] = %i\n", counter, end->reg.key);
		end = end->nextPos;
		counter++;
	}
}

/*
	3)  Finding the total number of elements stored in the list
*/
int findNbElemLinkListCircular(List* anyList) {
	POINTER end = anyList->firstPos->nextPos;
	int listSize = 0;

	while (end != NULL) {
		listSize++;
		end = end->nextPos;
	}
	return listSize;
}

/*
	4) Getting the first value stored in the list
*/
KEYTYPE getFstElemLinkListCircular(List* anyList) {
	int length = findNbElemLinkListCircular(anyList);
	if (length > 0) {
		return (anyList->firstPos->reg.key);
	}
	else
		return (-1); //empty list
}

/*
	5) Getting the last value stored in the list
*/
int getLstElemLinkListCircular(List* anyList) {
	POINTER end = anyList->firstPos->nextPos->reg.key;
	while (end != anyList->firstPos->reg.key) {
		end = end->nextPos;
		if (end->nextPos->reg.key == anyList->firstPos->reg.key)
			return end->reg.key;
	}
	return (-1); //empty list
}

/*
	6) Searching in the linked list ordered using 'Sentinel'
		**1st APPROACH: Unordered list
*/
POINTER searchSeqLinkListUnordCircular(List* anyList, KEYTYPE anyKey) {
	POINTER pos = anyList->firstPos->nextPos;
	anyList->firstPos->reg.key = anyKey;

	while (pos->reg.key != anyKey) {
		pos = pos->nextPos;
	}

	// Checking if it reached the sentinel
	if (pos != anyList->firstPos)
		return pos;
	return NULL; // Not found!
}

/*   
	6) Searching in the linked list ordered using 'Sentinel'
		**2nd APPROACH: Ordered list
*/
int searchSeqLinkListOrdCircular(List* anyList, KEYTYPE anyKey) {
	POINTER pos = anyList->firstPos->nextPos;
	anyList->firstPos->reg.key = anyKey;

	while (pos->reg.key < anyKey) {
		pos = pos->nextPos;
	}

	// Checking if it reached the sentinel
	if ((pos != anyList->firstPos) && (pos->reg.key == anyKey))
		return pos;
	return NULL; // Not found!
}

/*
	**Auxiliary function for insertation

	Note! Even it doesn't find the searched value, it always keeps the address of the PREDECESSOR element
*/
int getAvailablePosLinkListCircular(List* anyList, KEYTYPE anyKey, POINTER* anyPred) {
	*anyPred = anyList->firstPos;
	POINTER current = anyList->firstPos->nextPos;
	anyList->firstPos->reg.key = anyKey;

	// Checking values to store neatly
	while (current->reg.key < anyKey) {
		*anyPred = current;
		current = current->nextPos;
	}

	if ((current != anyList->firstPos) && (current->reg.key == anyKey))
		return current;
	return NULL;// Not found!
}

/*
	7) Inserting elements in ascending position
	*It must be ordered;
	*No repeated values;

	**Auxiliary func to get the available position
	and update the available position for the next turn;
*/
bool insertElemLinkListOrdCircular(List* anyList, Register anyReg) {
	POINTER nPred, nAddress;

	// Call the auxiliary func
	nAddress = getAvailablePosLinkListCircular(anyList, anyReg.key, &nPred);

	// Checking for repeated values
	if (nAddress != NULL)
		return false;

	// Allocating memory
	nAddress = (POINTER)malloc(sizeof(Element));
	nAddress->reg = anyReg;

	// It is not necessary to test (if-else) because it will always have a predecessor value. 
	// Also, it updates the next value to maintain the next position of the next element.
	nAddress->nextPos = nPred->nextPos;
	nPred->nextPos = nAddress;
	return true;
}


/*
	8) Excluding one specific element

	**Auxiliary func to search the position of the excluded element;
	*** Always free the memory space!!!!
*/
bool deleteElemLinkListCircular(List* anyList, KEYTYPE anyKey) {
	POINTER nPred, nAddress;
	nAddress = getAvailablePosLinkListCircular(anyList, anyKey, &nPred);

	// Checking if the element exist in the list
	if (nAddress == NULL)
		return false;

	nPred->nextPos = nAddress->nextPos;

	free(nAddress);
	return true;
}

/*
	9) Reinitializing the list
	*** Always free the memory space!!!!
*/
void reinitializeSeqLinkListCircular(List* anyList) {
	POINTER end = anyList->firstPos->nextPos;

	while (end != anyList->firstPos) {
		POINTER delete = end;
		end = end->nextPos;
		free(delete);
	}
	anyList->firstPos->nextPos = anyList->firstPos;
}


int main() {

	List myList;
	initializeLinkListCircular(&myList);

	Register crrYear;
	crrYear.key = 40;
	insertElemLinkListOrdCircular(&myList, crrYear);
	crrYear.key = 10;
	insertElemLinkListOrdCircular(&myList, crrYear);
	crrYear.key = 30;
	insertElemLinkListOrdCircular(&myList, crrYear);
	crrYear.key = 20;
	insertElemLinkListOrdCircular(&myList, crrYear);
	displayLinkedListCircular(&myList);

	crrYear.key = 20;
	//printf("%i\n", searchSeqLinkListOrdCircular(&myList, crrYear.key));
	//printf("First element is %i\n", getFstElemLinkListCircular(&myList));
	//printf("Last element is %i\n", getLstElemLinkListCircular(&myList));

	reinitializeSeqLinkListCircular(&myList);
	return 0;
}