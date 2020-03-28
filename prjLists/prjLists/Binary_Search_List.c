///*!	\file		Binary_Search_List.c
//	\author		Carla Alves
//	\date		2020-03-26
//
//	Optimization of the search function for a linear list data structure using the binary technique:
//	1) Insert element neatly;
//	2) No repeated values will be alllowed (in this program);
//	3) Search for the correct position to insert the new element from back to front;
//	4) Create a binary searching which uses three variables to indicate the element on the left, right, and middle;
//	5) Start the search at the middle position, then, it goes to left or right and so on.
//
//	*PROS x CONS:
//	-POSITIVE: More efficient than Sentinel search approach;
//	-NEGATIVE: It works only for ordered lists.
//*/
//
//#include"stdio.h"
//#include"stdbool.h"
//#define MAX 50
//
//typedef int KEYTYPE;
//
//typedef struct {
//	KEYTYPE key;
//}Register;
//
//typedef struct {
//	Register tabElem[MAX];
//	int nbElem;
//}List;
//
///*
//	1) Initializing the list
//	We must use a pointer as a parameter, otherwise the list will not be updated.
//*/
//void initializeSequentialList(List* anyList) {
//	anyList->nbElem = 0;
//}
//
///*
//	2) Displaying all elements stored in the list
//*/
//void displayList(List* anyList) {
//	for (int indx = 0; indx < anyList->nbElem; indx++)
//		printf("[%i] = %i\n", indx, anyList->tabElem[indx].key);
//}
//
///*
//	3)  Finding the total number of elements stored in the list
//*/
//int findNbElements(List* anyList) {
//	return anyList->nbElem;
//}
//
///*
//	4) Getting the first value stored in the list
//*/
//KEYTYPE getFirstElement(List* anyList) {
//	if (anyList->nbElem > 0)
//		return (anyList->tabElem[0].key);
//	else
//		return (-1); //empty list
//}
//
///*
//	5) Getting the last value stored in the list
//*/
//KEYTYPE getLastElement(List* anyList) {
//	if (anyList->nbElem > 0)
//		return (anyList->tabElem[anyList->nbElem - 1].key);
//	else
//		return (-1); //empty list
//}
//
///*
//	6) Using 'Binary technique' for searching in the sequential list
//*/
//int searchBinary(List* anyList, KEYTYPE anyKey) {
//	int middle, left = 0, right = anyList->nbElem-1;
//
//	while (left <= right) {
//		middle = ((left + right) / 2);
//
//		if (anyKey == anyList->tabElem[middle].key)
//			return middle;
//		else {
//			if (anyList->tabElem[middle].key < anyKey)
//				left = middle + 1;
//			else
//				right = middle - 1;
//		}
//	}// end loop
//	return -1; // Not found!
//}
//
///*
//	7) Inserting elements in ascending position (It must be ordered!)
//*/
//bool insertElemListOrd(List* anyList, Register anyReg) {
//
//	if (anyList->nbElem == MAX) // Full list!
//		return false;
//
//	int pos = anyList->nbElem;
//
//	// Started from back to front because it also releases space for the new element
//	while ((pos >= 0) && (anyList->tabElem[pos-1].key > anyReg.key)) {
//		anyList->tabElem[pos] = anyList->tabElem[pos-1];
//		pos--;
//	}
//
//	anyList->tabElem[pos] = anyReg;
//	anyList->nbElem++;
//	return true;
//}
//
///*
//	8) Excluding one specific element
//		*Defining method:
//		1. Search the element
//		2. Move one position back all elements in the right side
//		3. Decrement nbElements
//*/
//bool deleteElemList(List* anyList, KEYTYPE anyKey) {
//	int pos = searchBinary(anyList, anyKey);
//
//	if (pos == -1)  
//		return false;
//
//	// It will overwrite the elements, "deleting them"
//	for (int indx = pos; indx < anyList->nbElem; indx++)
//		anyList->tabElem[indx] = anyList->tabElem[indx + 1];
//
//	// It "disables" access to the remainder last value, "deleting it"
//	anyList->nbElem--;
//
//	return true;
//}
//
///*
//	9) Reinitializing the list
//*/
//void reinitializeSequentialList(List* anyList) {
//	anyList->nbElem = 0;
//}
//
//
//int main() {
//
//	List myList;
//	initializeSequentialList(&myList);
//
//	Register crrYear;
//	crrYear.key = 2020;
//	insertElemListOrd(&myList, crrYear);
//	crrYear.key = 500;
//	insertElemListOrd(&myList, crrYear);
//	displayList(&myList);
//
//	crrYear.key = 2020;
//	printf("%i", searchBinary(&myList, crrYear.key));
//
//	return 0;
//}