/*!	\file		Linked_List_Dinamic.c
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

typedef struct aux {
	Register reg;
	struct aux* nextPos;// This pointer is called "auxiliary" because it was not created yeah!
}Element;

typedef Element* POINTER;

typedef struct {
	POINTER firstPos;
}List;

/*
	1) Initializing the list
*/
void initializeLinkListDinamic(List* anyList) {
	anyList->firstPos = NULL;
}

/*
	2) Displaying all elements stored in the list
*/
void displayLinkedListDinamic(List* anyList) {
	POINTER end = anyList->firstPos;
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
int findNbElemLinkListDinamic(List* anyList) {
	POINTER end = anyList->firstPos;
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
KEYTYPE getFstElemLinkListDinamic(List* anyList) {
	int length = findNbElemLinkListDinamic(anyList);
	if (length > 0) {
		return (anyList->firstPos->reg.key);
	}
	else
		return (-1); //empty list
}

/*
	5) Getting the last value stored in the list
*/
int getLstElemLinkListDinamic(List* anyList) {
	POINTER end = anyList->firstPos;
	while (end != NULL) {
		end = end->nextPos;
		if (end->nextPos == NULL)
			return end->reg.key;
	}
	return (-1); //empty list
}

/*
	6) Searching in the linked list ordered
		**1st APPROACH: Unordered list
*/
POINTER searchSeqLinkListUnordDinamic(List* anyList, KEYTYPE anyKey) {
	POINTER pos = anyList->firstPos;

	while (pos != NULL) {
		if (pos->reg.key == anyKey)// Testing inside the loop is more expensive
			return pos;
		pos = pos->nextPos;
	}
	return NULL; // Not found!
}

/*
	6) Searching in the linked list ordered
		**2nd APPROACH: Ordered list
*/
int searchSeqLinkListOrdDinamic(List* anyList, KEYTYPE anyKey) {
	POINTER pos = anyList->firstPos;

	while ((pos != NULL) && (pos->reg.key < anyKey)) {
		pos = pos->nextPos;
	}

	// Testing outside the loop is more efficient
	if ((pos != NULL) && (pos->reg.key == anyKey))
		return pos;
	return NULL;// Not found!
}

/*
	**Auxiliary function for insertation

	Note! Even it doesn't find the searched value, it always keeps the address of the PREDECESSOR element
*/
int getAvailablePosLinkListDinamic(List* anyList, KEYTYPE anyKey, POINTER* anyPred) {
	*anyPred = NULL;
	POINTER current = anyList->firstPos;

	// Checking values to store neatly
	while ((current != NULL) && (current->reg.key < anyKey)) {
		*anyPred = current;
		current = current->nextPos;
	}

	if ((current != NULL) && (current->reg.key == anyKey))
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
bool insertElemLinkListOrdDinamic(List* anyList, Register anyReg) {
	KEYTYPE nKey = anyReg.key;
	POINTER nPred, nAddress;

	// Call the auxiliary func
	nAddress = getAvailablePosLinkListDinamic(anyList, nKey, &nPred);

	// Checking for repeated values
	if (nAddress != NULL)
		return false;

	// Allocating memory
	nAddress = (POINTER)malloc(sizeof(Element));

	nAddress->reg = anyReg;

	// Setting the pointers
	if (nPred == NULL) {
		nAddress->nextPos = anyList->firstPos;
		anyList->firstPos = nAddress;
	}
	else {
		nAddress->nextPos = nPred->nextPos;
		nPred->nextPos = nAddress;
	}
	return true;
}


/*
	8) Excluding one specific element

	**Auxiliary func to search the position of the excluded element;
	*** Always free the memory space!!!!
*/
bool deleteElemLinkListDinamic(List* anyList, KEYTYPE anyKey) {
	POINTER nPred, nAddress;
	nAddress = getAvailablePosLinkListDinamic(anyList, anyKey, &nPred);

	// Checking if the element exist in the list
	if (nAddress == NULL)
		return false;

	// Checking if the it is the first element of the list
	if (nPred == NULL)
		anyList->firstPos = nAddress->nextPos;
	else
		nPred->nextPos = nAddress->nextPos;

	free(nAddress);
	return true;
}

/*
	9) Reinitializing the list
	*** Always free the memory space!!!!
*/
void reinitializeSeqLinkListDinamic(List* anyList) {
	POINTER end = anyList->firstPos;

	while (end != NULL) {
		POINTER delete = end;
		end = end->nextPos;
		free(delete);
	}
	anyList->firstPos = NULL;
}


int main() {

	List myList;
	initializeLinkListDinamic(&myList);

	Register crrYear;
	crrYear.key = 40;
	insertElemLinkListOrdDinamic(&myList, crrYear);
	crrYear.key = 10;
	insertElemLinkListOrdDinamic(&myList, crrYear);
	crrYear.key = 30;
	insertElemLinkListOrdDinamic(&myList, crrYear);
	crrYear.key = 20;
	insertElemLinkListOrdDinamic(&myList, crrYear);
	displayLinkedListDinamic(&myList);

	crrYear.key = 20;
	printf("%i\n", searchSeqLinkListOrdDinamic(&myList, crrYear.key));
	printf("First element is %i\n", getFstElemLinkListDinamic(&myList));
	printf("Last element is %i\n", getLstElemLinkListDinamic(&myList));

	reinitializeSeqLinkListDinamic(&myList);
	return 0;
}