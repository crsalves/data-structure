///*!	\file		Linked_List_Static.c
//	\author		Carla Alves
//	\date		2020-03-27
//
//	Static implamentation of a linked linear list:
//	1) Physically, the elements are spreadly stored in the computer memory;
//	2) All elements have the address of the 'next element position', except the last element;
//	3) It is necessary to know the 'first element position';
//*/
//
//#include"stdio.h"
//#include"stdbool.h"
//#define MAX 50
//#define INVALID -1
//
//typedef int KEYTYPE;
//
//typedef struct {
//	KEYTYPE key;
//}Register;
//
//typedef struct {
//	Register reg;
//	int nextPos;
//}Element;
//
//typedef struct {
//	Element tabElem[MAX];
//	int stPos;// This identifies the first element position
//	int availPos;// This indicates available positions
//}List;
//
///*
//	1) Initializing the list
//*/
//void initializeLinkListStatic(List* anyList) {
//	for (int indx = 0; indx < (MAX - 1); indx++) {
//		anyList->tabElem[indx].nextPos = indx + 1;
//	}
//
//	anyList->tabElem[MAX - 1].nextPos = INVALID; // The last element doesn't have next position
//	anyList->stPos = INVALID; // The first position starts with no next valid position because the list is empty
//	anyList->availPos = 0; // The index zero is the first available position
//}
//
///*
//	2) Displaying all elements stored in the list
//*/
//void displayLinkedListStatic(List* anyList) {
//	int indx = anyList->stPos;
//
//	while (indx != INVALID) {
//		printf("[%i] = %i\n", indx, anyList->tabElem[indx].reg.key);
//		indx = anyList->tabElem[indx].nextPos;
//	}
//}
//
///*
//	3)  Finding the total number of elements stored in the list
//*/
//int findNbElemLinkListStatic(List* anyList) {
//	int indx = anyList->stPos;
//	int listSize = 0;
//
//	while (indx != INVALID) {
//		listSize++;
//		indx = anyList->tabElem[indx].nextPos;
//	}
//
//	return listSize;
//}
//
///*
//	4) Getting the first value stored in the list
//*/
//KEYTYPE getFstElemLinkListStatic(List* anyList) {
//	int length = findNbElemLinkListStatic(anyList);
//	if (length > 0) {
//		return (anyList->tabElem[anyList->stPos].reg.key);
//	}		
//	else
//		return (-1); //empty list
//}
//
///*
//	5) Getting the last value stored in the list
//*/
//KEYTYPE getLstElemLinkListStatic(List* anyList) {
//	int length = findNbElemLinkListStatic(anyList);
//	if (length > 0)
//		return (anyList->tabElem[anyList->availPos-1].reg.key);
//	else
//		return (-1); //empty list
//}
//
///*
//	6) Searching in the linked list ordered
//	NEGATIVE: Binary search does not work in this case because the element 
//			in the middle may not indicate the ordered middle element
//*/
//int searchSeqLinkListOrdStatic(List* anyList, KEYTYPE anyKey) {
//	int indx = anyList->stPos;
//
//	// This stops when the current element is bigger than the sought element 
//	while ((indx != INVALID) && (anyList->tabElem[indx].reg.key < anyKey))
//		indx = anyList->tabElem[indx].nextPos;
//
//	if ((indx != INVALID) && (anyList->tabElem[indx].reg.key == anyKey))
//		return indx;
//	else
//		return INVALID; // Not found!
//}
//
///*
//	**Auxiliary function for insertation
//*/
//int getAvailablePosLinkListStatic(List* anyList) {
//	int crrAvailable = anyList->availPos;
//
//	// Updating the available position for the next insertation
//	if (anyList->availPos != INVALID) {
//		anyList->availPos = anyList->tabElem[anyList->availPos].nextPos;
//	}
//	return crrAvailable;
//}
//
///*
//	7) Inserting elements in ascending position 
//	*It must be ordered;
//	*No repeated values;
//
//	**Auxiliary func to get the available position 
//	and update the available position for the next turn;
//*/
//bool insertElemLinkListOrdStatic(List* anyList, Register anyReg) {
//	if (anyList->availPos == INVALID)
//		return false;
//
//	int prevPos = INVALID;
//	int crrPos = anyList->stPos;
//	KEYTYPE tmpKey = anyReg.key;
//
//	while ((crrPos != INVALID) && (anyList->tabElem[crrPos].reg.key < tmpKey)) {
//		prevPos = crrPos;
//		crrPos = anyList->tabElem[crrPos].nextPos;
//	}
//
//	// Checking repeated values
//	if ((crrPos != INVALID) && (anyList->tabElem[crrPos].reg.key == tmpKey))
//		return false;
//
//	// **Auxiliary function
//	crrPos = getAvailablePosLinkListStatic(anyList);
//
//	anyList->tabElem[crrPos].reg.key = anyReg.key;
//
//	// If it is the first element that will be inserted
//	if (prevPos == INVALID) {
//		anyList->tabElem[crrPos].nextPos = anyList->stPos;
//		anyList->stPos = crrPos;
//	}
//	else // when there is at least one element in the list
//	{
//		anyList->tabElem[crrPos].nextPos = anyList->tabElem[prevPos].nextPos;
//		anyList->tabElem[prevPos].nextPos = crrPos;
//	}
//	return true;
//}
//
///*
//	**Auxiliary function for deletition
//
//	The released position will be the first available position.
//*/
//void releasePosLinkListStatic(List* anyList, int releasedPos) {
//	anyList->tabElem[releasedPos].nextPos = anyList->availPos;
//	anyList->availPos = releasedPos;
//}
//
//
///*
//	8) Excluding one specific element
//
//	**Auxiliary func to release the position of the excluded element;
//*/
//bool deleteElemLinkListStatic(List* anyList, KEYTYPE anyKey) {
//	int prevPos = INVALID;
//	int crrPos = anyList->stPos;
//
//	while ((crrPos != INVALID) && (anyList->tabElem[crrPos].reg.key < anyKey)) {
//		prevPos = crrPos;
//		crrPos = anyList->tabElem[crrPos].nextPos;
//	}
//
//	// Checking if the element exists
//	if ((crrPos == INVALID) || (anyList->tabElem[crrPos].reg.key != anyKey))
//		return false;
//
//	if (prevPos == INVALID)
//		anyList->stPos = anyList->tabElem[crrPos].nextPos;
//	else
//		anyList->tabElem[prevPos].nextPos = anyList->tabElem[crrPos].nextPos;
//
//	releasePosLinkListStatic(&anyList, crrPos);
//	return true;
//}
//
///*
//	9) Reinitializing the list
//*/
//void reinitializeSeqLinkListStatic(List* anyList) {
//	initializeLinkListStatic(&anyList);
//}
//
//
//int main() {
//
//	List myList;
//	initializeLinkListStatic(&myList);
//
//	Register crrYear;
//	crrYear.key = 10;
//	insertElemLinkListOrdStatic(&myList, crrYear);
//	crrYear.key = 20;
//	insertElemLinkListOrdStatic(&myList, crrYear);
//	crrYear.key = 30;
//	insertElemLinkListOrdStatic(&myList, crrYear);
//	crrYear.key = 40;
//    insertElemLinkListOrdStatic(&myList, crrYear);
//	 displayLinkedListStatic(&myList);
//
//	crrYear.key = 20;
//	printf("%i\n", searchSeqLinkListOrdStatic(&myList, crrYear.key));
//	printf("First element is %i\n", getFstElemLinkListStatic(&myList));
//	printf("Last element is %i\n", getLstElemLinkListStatic(&myList));
//	return 0;
//}