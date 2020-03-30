#pragma once
#include"stdio.h"
#include"stdbool.h"
#include"malloc.h"

#define MAX 50
#define INVALID -1

typedef int KEYTYPE;

typedef struct {
	KEYTYPE key;
}Register;

typedef struct {
	Register tabElem[MAX];
	int nbElem;
}List;

typedef struct {
	Register tabElem[MAX + 1]; // Create an extra element here!
	int nbElem;
}sentinelList;

typedef struct {
	Register reg;
	int nextPos;
}staticLinkElement;

typedef struct {
	staticLinkElement tabElem[MAX];
	int firstPos;// This identifies the first element position
	int availPos;// This indicates available positions
}staticLinkList;

typedef struct aux {
	Register reg;
	struct aux* nextPos;// This pointer is called "auxiliary" because it was not created yet!
}dinamicElement;

typedef dinamicElement* POINTER;

typedef struct {
	POINTER firstPos;
}dinamicLinkList;

typedef struct tmpReg {
	Register reg;
	struct tmpReg* nextPos;
}circularLinkElement;

typedef circularLinkElement* headPOINTER;

typedef struct {
	headPOINTER head;
}circularLinkList;

/*
	1) Initializing the list
	We must use a pointer as a parameter, otherwise the list will not be updated.
*/
void initializeSequentialList(List* anyList) {
	anyList->nbElem = 0;
}

/*
	1) Initializing the list
	We must use a pointer as a parameter, otherwise the list will not be updated.
*/
void initializeSentinelList(sentinelList* anyList) {
	anyList->nbElem = 0;
}

/*
	1) Initializing the list
*/
void initializeLinkListStatic(staticLinkList* anyList) {
	for (int indx = 0; indx < (MAX - 1); indx++) {
		anyList->tabElem[indx].nextPos = indx + 1;
	}

	anyList->tabElem[MAX - 1].nextPos = INVALID; // The last element doesn't have next position
	anyList->firstPos = INVALID; // The first position starts with no next valid position because the list is empty
	anyList->availPos = 0; // The index zero is the first available position
}

/*
	1) Initializing the list
*/
void initializeLinkListDinamic(dinamicLinkList* anyList) {
	anyList->firstPos = NULL;
}

/*
	1) Initializing the list
*/
void initializeLinkListCircular(circularLinkList* anyList) {
	anyList->head = (headPOINTER)malloc(sizeof(circularLinkElement));
	anyList->head->nextPos = anyList->head;
}

/*
	2) Displaying all elements stored in the list
*/
void displayList(List* anyList) {
	for (int indx = 0; indx < anyList->nbElem; indx++)
		printf("[%i] = %i\n", indx, anyList->tabElem[indx].key);
}   

/*
	2) Displaying all elements stored in the list
*/
void displayLinkedListStatic(staticLinkList* anyList) {
	int indx = anyList->firstPos;

	while (indx != INVALID) {
		printf("[%i] = %i\n", indx, anyList->tabElem[indx].reg.key);
		indx = anyList->tabElem[indx].nextPos;
	}
}

/*
	2) Displaying all elements stored in the list
*/
void displayLinkedListDinamic(dinamicLinkList* anyList) {
	POINTER end = anyList->firstPos;
	int counter = 0;// Just for view purposes (to show the index for the user)
	while (end != NULL) {
		printf("[%i] = %i\n", counter, end->reg.key);
		end = end->nextPos;
		counter++;
	}
}

/*
	2) Displaying all elements stored in the list
*/
void displayLinkedListCircular(circularLinkList* anyList) {
	headPOINTER end = anyList->head->nextPos;
	int counter = 0;// Just for view purposes (to show the index for the user)
	while (end != anyList->head) {
		printf("[%i] = %i\n", counter, end->reg.key);
		end = end->nextPos;
		counter++;
	}
}

/*
	3)  Finding the total number of elements stored in the list
*/
int findNbElements(List* anyList) {
	return anyList->nbElem;
}

/*
	3)  Finding the total number of elements stored in the list
*/
int findNbElemLinkListStatic(staticLinkList* anyList) {
	int indx = anyList->firstPos;
	int listSize = 0;

	while (indx != INVALID) {
		listSize++;
		indx = anyList->tabElem[indx].nextPos;
	}

	return listSize;
}

/*
	3)  Finding the total number of elements stored in the list
*/
int findNbElemLinkListCircular(circularLinkList* anyList) {
	headPOINTER end = anyList->head->nextPos;
	int listSize = 0;

	while (end != anyList->head) {
		listSize++;
		end = end->nextPos;
	}
	return listSize;
}

/*
	3)  Finding the total number of elements stored in the list
*/
int findNbElemLinkListDinamic(dinamicLinkList* anyList) {
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
KEYTYPE getFirstElement(List* anyList) {
	if (anyList->nbElem > 0)
		return (anyList->tabElem[0].key);
	else
		return (-1); //empty list
}

/*
	4) Getting the first value stored in the list
*/
KEYTYPE getFstElemLinkListStatic(staticLinkList* anyList) {
	int length = findNbElemLinkListStatic(anyList);
	if (length > 0) {
		return (anyList->tabElem[anyList->firstPos].reg.key);
	}
	else
		return (-1); //empty list
}

/*
	4) Getting the first value stored in the list
*/
KEYTYPE getFstElemLinkListDinamic(dinamicLinkList* anyList) {
	int length = findNbElemLinkListDinamic(anyList);
	if (length > 0) {
		return (anyList->firstPos->reg.key);
	}
	else
		return (-1); //empty list
}

/*
	4) Getting the first value stored in the list
*/
KEYTYPE getFstElemLinkListCircular(circularLinkList* anyList) {
	int length = findNbElemLinkListCircular(anyList);
	if (length > 0) {
		return (anyList->head->nextPos->reg.key);
	}
	else
		return (-1); //empty list
}

/*
	5) Getting the last value stored in the list
*/
KEYTYPE getLastElement(List* anyList) {
	if (anyList->nbElem > 0)
		return (anyList->tabElem[anyList->nbElem - 1].key);
	else
		return (-1); //empty list
}

/*
	5) Getting the last value stored in the list
*/
KEYTYPE getLstElemLinkListStatic(staticLinkList* anyList) {
	int length = findNbElemLinkListStatic(anyList);
	if (length > 0)
		return (anyList->tabElem[anyList->availPos - 1].reg.key);
	else
		return (-1); //empty list
}

/*
	5) Getting the last value stored in the list
*/
int getLstElemLinkListDinamic(dinamicLinkList* anyList) {
	POINTER end = anyList->firstPos;
	while (end != NULL) {
		end = end->nextPos;
		if (end->nextPos == NULL)
			return end->reg.key;
	}
	return (-1); //empty list
}

/*
	5) Getting the last value stored in the list
*/
int getLstElemLinkListCircular(circularLinkList* anyList) {
	headPOINTER end = anyList->head->nextPos;
	while (end != anyList->head) {
		if (end->nextPos == anyList->head)
			return end->reg.key;
		end = end->nextPos;
	}
	return -1; //empty list
}

/*
	6) Searching in the sequential list
*/
int searchSequentialList(List* anyList, KEYTYPE anyKey) {
	int indx = 0;
	while (indx < anyList->nbElem) {
		if (anyKey == anyList->tabElem[indx].key)
			return indx;// Element Found!
		indx++;
	}
	return -1;// Element not found!
}

/*
	6) Using 'Sentinel' for searching in the sequential list
		*Using the 'if' statement to test inside a 'while loop' is not as
		efficient as checking the sentinel outside the loop
*/
int searchSentinelList(List* anyList, KEYTYPE anyKey) {
	int indx = 0;

	// 1) Placing the Sentinel after last valid position of the list
	anyList->tabElem[anyList->nbElem].key = anyKey;

	// 2) Using "while" instead of "for" because we don't know exactly how many iterations it will take
	while (anyKey != anyList->tabElem[indx].key)
		indx++;

	// 3) Checking if it reached the sentinel
	if (indx == anyList->nbElem)
		return -1;// Element not found!
	else
		return indx;// Element found!
}

/*
	6) Using 'Binary technique' for searching in the sequential list
*/
int searchBinary(List* anyList, KEYTYPE anyKey) {
	int middle, left = 0, right = anyList->nbElem - 1;

	while (left <= right) {
		middle = ((left + right) / 2);

		if (anyKey == anyList->tabElem[middle].key)
			return middle;
		else {
			if (anyList->tabElem[middle].key < anyKey)
				left = middle + 1;
			else
				right = middle - 1;
		}
	}// end loop
	return -1; // Not found!
}

/*
	6) Searching in the linked list ordered
	NEGATIVE: Binary search does not work in this case because the element
			in the middle may not indicate the ordered middle element
*/
int searchSeqLinkListOrdStatic(staticLinkList* anyList, KEYTYPE anyKey) {
	int indx = anyList->firstPos;

	// This stops when the current element is bigger than the sought element 
	while ((indx != INVALID) && (anyList->tabElem[indx].reg.key < anyKey))
		indx = anyList->tabElem[indx].nextPos;

	if ((indx != INVALID) && (anyList->tabElem[indx].reg.key == anyKey))
		return indx;
	else
		return INVALID; // Not found!
}

/*
	6) Searching in the linked list
		**1st APPROACH: Unordered list
*/
POINTER searchSeqLinkListUnordDinamic(dinamicLinkList* anyList, KEYTYPE anyKey) {
	POINTER pos = anyList->firstPos;

	while (pos != NULL) {
		if (pos->reg.key == anyKey)// Testing inside the loop is more expensive
			return pos;
		pos = pos->nextPos;
	}
	return NULL; // Not found!
}

/*
	6) Searching in the linked list
		**2nd APPROACH: Ordered list
*/
int searchSeqLinkListOrdDinamic(dinamicLinkList* anyList, KEYTYPE anyKey) {
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
	6) Searching in the linked list ordered using 'Sentinel'
		**1st APPROACH: Unordered list
*/
headPOINTER searchSeqLinkListUnordCircular(circularLinkList* anyList, KEYTYPE anyKey) {
	headPOINTER pos = anyList->head->nextPos;
	anyList->head->reg.key = anyKey;

	while (pos->reg.key != anyKey) {
		pos = pos->nextPos;
	}

	// Checking if it reached the sentinel
	if (pos != anyList->head)
		return pos;
	return NULL; // Not found!
}

/*
	6) Searching in the linked list ordered using 'Sentinel'
		**2nd APPROACH: Ordered list
*/
headPOINTER searchSeqLinkListOrdCircular(circularLinkList* anyList, KEYTYPE anyKey) {
	headPOINTER pos = anyList->head->nextPos;
	anyList->head->reg.key = anyKey;

	while (pos->reg.key < anyKey) {
		pos = pos->nextPos;
	}

	// Checking if it reached the sentinel
	if ((pos != anyList->head) && (pos->reg.key == anyKey))
		return pos;
	return NULL; // Not found!
}

/*
	7) Inserting one element in a specific position
		*Defining features:
		1. If the list is not full and it is a valid position (index)
			1.1 All previous elements will be placed/copy to the right
			1.2 Insert/assign the element in the desired position
			1.3 Increment nbElement
			1.4 return true
		1.1 Else
			1.1.1 Return false
*/
bool insertElemList(List* anyList, Register anyReg, int pos) {
	int indx;

	if ((anyList->nbElem == MAX) || (pos < 0) || pos > anyList->nbElem)
		return false;

	//	In order to release position and replace the elements to the 
	// right index while searching, it searches the "pos" from back to front.
	for (indx = anyList->nbElem; indx > pos; indx--) {
		anyList->tabElem[indx] = anyList->tabElem[indx - 1];
	}

	anyList->tabElem[pos] = anyReg;
	anyList->nbElem++;
	return true;
}

/*
	7) Inserting elements in ascending position (It must be ordered!)
*/
bool insertElemListOrd(List* anyList, Register anyReg) {

	if (anyList->nbElem == MAX) // Full list!
		return false;

	int pos = anyList->nbElem;

	// Started from back to front because it also releases space for the new element
	while ((pos >= 0) && (anyList->tabElem[pos - 1].key > anyReg.key)) {
		anyList->tabElem[pos] = anyList->tabElem[pos - 1];
		pos--;
	}

	anyList->tabElem[pos] = anyReg;
	anyList->nbElem++;
	return true;
}

/*
	**Auxiliary function for insertation
*/
int getAvailablePosLinkListStatic(staticLinkList* anyList) {
	int crrAvailable = anyList->availPos;

	// Updating the available position for the next insertation
	if (anyList->availPos != INVALID) {
		anyList->availPos = anyList->tabElem[anyList->availPos].nextPos;
	}
	return crrAvailable;
}

/*
	7) Inserting elements in ascending position
	*It must be ordered;
	*No repeated values;

	**Auxiliary func to get the available position
	and update the available position for the next turn;
*/
bool insertElemLinkListOrdStatic(staticLinkList* anyList, Register anyReg) {
	if (anyList->availPos == INVALID)
		return false;

	int prevPos = INVALID;
	int crrPos = anyList->firstPos;
	KEYTYPE tmpKey = anyReg.key;

	while ((crrPos != INVALID) && (anyList->tabElem[crrPos].reg.key < tmpKey)) {
		prevPos = crrPos;
		crrPos = anyList->tabElem[crrPos].nextPos;
	}

	// Checking repeated values
	if ((crrPos != INVALID) && (anyList->tabElem[crrPos].reg.key == tmpKey))
		return false;

	// **Auxiliary function
	crrPos = getAvailablePosLinkListStatic(anyList);

	anyList->tabElem[crrPos].reg.key = anyReg.key;

	// If it is the first element that will be inserted
	if (prevPos == INVALID) {
		anyList->tabElem[crrPos].nextPos = anyList->firstPos;
		anyList->firstPos = crrPos;
	}
	else // when there is at least one element in the list
	{
		anyList->tabElem[crrPos].nextPos = anyList->tabElem[prevPos].nextPos;
		anyList->tabElem[prevPos].nextPos = crrPos;
	}
	return true;
}

/*
	**Auxiliary function for insertation

	Note! Even it doesn't find the searched value, it always keeps the address of the PREDECESSOR element
*/
int getAvailablePosLinkListDinamic(dinamicLinkList* anyList, KEYTYPE anyKey, POINTER* anyPred) {
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
bool insertElemLinkListOrdDinamic(dinamicLinkList* anyList, Register anyReg) {
	KEYTYPE nKey = anyReg.key;
	POINTER nPred, nAddress;

	// Call the auxiliary func
	nAddress = getAvailablePosLinkListDinamic(anyList, nKey, &nPred);

	// Checking for repeated values
	if (nAddress != NULL)
		return false;

	// Allocating memory
	nAddress = (POINTER)malloc(sizeof(dinamicElement));

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
	**Auxiliary function for insertation

	Note! Even it doesn't find the searched value, it always keeps the address of the PREDECESSOR element
*/
int getAvailablePosLinkListCircular(circularLinkList* anyList, KEYTYPE anyKey, POINTER* anyPred) {
	*anyPred = anyList->head;
	POINTER current = anyList->head->nextPos;
	anyList->head->reg.key = anyKey;

	// Checking values to store neatly
	while (current->reg.key < anyKey) {
		*anyPred = current;
		current = current->nextPos;
	}

	if ((current != anyList->head) && (current->reg.key == anyKey))
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
bool insertElemLinkListOrdCircular(circularLinkList* anyList, Register anyReg) {
	headPOINTER nPred, nAddress;

	// Call the auxiliary func
	nAddress = getAvailablePosLinkListCircular(anyList, anyReg.key, &nPred);

	// Checking for repeated values
	if (nAddress != NULL)
		return false;

	// Allocating memory
	nAddress = (POINTER)malloc(sizeof(circularLinkElement));
	nAddress->reg = anyReg;

	// It is not necessary to test (if-else) because it will always have a predecessor value. 
	// Also, it updates the next value to maintain the next position of the next element.
	nAddress->nextPos = nPred->nextPos;
	nPred->nextPos = nAddress;
	return true;
}


/*
	8) Excluding one specific element
		*Defining method:
		1. Search the element
		2. Move one position back all elements in the right side
		3. Decrement nbElements
*/
bool deleteElemList(List* anyList, KEYTYPE anyKey) {
	int pos = searchSequentialList(anyList, anyKey);

	if (pos == -1)
		return false;

	// It will overwrite the elements, "deleting them"
	for (int indx = pos; indx < anyList->nbElem; indx++)
		anyList->tabElem[indx] = anyList->tabElem[indx + 1];

	// It "disables" access to the remainder last value, "deleting it"
	anyList->nbElem--;

	return true;
}

/*
	8) Excluding one specific element
		*Defining method:
		1. Search the element
		2. Move one position back all elements in the right side
		3. Decrement nbElements
*/
bool deleteElemSentinelList(List* anyList, KEYTYPE anyKey) {
	int pos = searchSentinelList(anyList, anyKey);

	if (pos == -1)
		return false;

	// It will overwrite the elements, "deleting them"
	for (int indx = pos; indx < anyList->nbElem; indx++)
		anyList->tabElem[indx] = anyList->tabElem[indx + 1];

	// It "disables" access to the remainder last value, "deleting it"
	anyList->nbElem--;

	return true;
}

/*
	8) Excluding one specific element
		*Defining method:
		1. Search the element
		2. Move one position back all elements in the right side
		3. Decrement nbElements
*/
bool deleteElemBinaryList(List* anyList, KEYTYPE anyKey) {
	int pos = searchBinary(anyList, anyKey);

	if (pos == -1)
		return false;

	// It will overwrite the elements, "deleting them"
	for (int indx = pos; indx < anyList->nbElem; indx++)
		anyList->tabElem[indx] = anyList->tabElem[indx + 1];

	// It "disables" access to the remainder last value, "deleting it"
	anyList->nbElem--;

	return true;
}

/*
	**Auxiliary function for deletition

	The released position will be the first available position.
*/
void releasePosLinkListStatic(staticLinkList* anyList, int releasedPos) {
	anyList->tabElem[releasedPos].nextPos = anyList->availPos;
	anyList->availPos = releasedPos;
}


/*
	8) Excluding one specific element

	**Auxiliary func to release the position of the excluded element;
*/
bool deleteElemLinkListStatic(staticLinkList* anyList, KEYTYPE anyKey) {
	int prevPos = INVALID;
	int crrPos = anyList->firstPos;

	while ((crrPos != INVALID) && (anyList->tabElem[crrPos].reg.key < anyKey)) {
		prevPos = crrPos;
		crrPos = anyList->tabElem[crrPos].nextPos;
	}

	// Checking if the element exists
	if ((crrPos == INVALID) || (anyList->tabElem[crrPos].reg.key != anyKey))
		return false;

	if (prevPos == INVALID)
		anyList->firstPos = anyList->tabElem[crrPos].nextPos;
	else
		anyList->tabElem[prevPos].nextPos = anyList->tabElem[crrPos].nextPos;

	releasePosLinkListStatic(&anyList, crrPos);
	return true;
}

/*
	8) Excluding one specific element

	**Auxiliary func to search the position of the excluded element;
	*** Always free the memory space!!!!
*/
bool deleteElemLinkListDinamic(dinamicLinkList* anyList, KEYTYPE anyKey) {
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
	8) Excluding one specific element

	**Auxiliary func to search the position of the excluded element;
	*** Always free the memory space!!!!
*/
bool deleteElemLinkListCircular(List* anyList, KEYTYPE anyKey) {
	headPOINTER nPred, nAddress;
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
*/
void reinitializeSequentialList(List* anyList) {
	anyList->nbElem = 0;
}

/*
	9) Reinitializing the list
*/
void reinitializeSeqLinkListStatic(List* anyList) {
	initializeLinkListStatic(&anyList);
}

/*
	9) Reinitializing the list
	*** Always free the memory space!!!!
*/
void reinitializeSeqLinkListDinamic(dinamicLinkList* anyList) {
	POINTER end = anyList->firstPos;

	while (end != NULL) {
		POINTER delete = end;
		end = end->nextPos;
		free(delete);
	}
	anyList->firstPos = NULL;
}

/*
	9) Reinitializing the list
	*** Always free the memory space!!!!
*/
void reinitializeSeqLinkListCircular(circularLinkList* anyList) {
	headPOINTER end = anyList->head->nextPos;

	while (end != anyList->head) {
		POINTER delete = end;
		end = end->nextPos;
		free(delete);
	}
	anyList->head->nextPos = anyList->head;
}