///*!	\file		Linear_Sequential_List.c
//	\author		Carla Alves
//	\date		2020-03-25
//
//	Implementation of a linear list data structure using auxiliary functions:
//	1) Initialization;
//	2) Display all elements;
//	3) Total elements;
//	4) Return the first element;
//	5) Return the last element;
//	6) Sequential search;
//	7) Insert one element;
//	8) Delete one element;
//	9) Reinitialization;
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
//void initializeSequentialList(List * anyList) {
//	anyList->nbElem = 0;
//}
//
///* 
//	2) Displaying all elements stored in the list
//*/
//void displayList(List* anyList) {
//	for(int indx = 0; indx < anyList->nbElem; indx++)
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
//		return (anyList->tabElem[anyList->nbElem-1].key);
//	else
//		return (-1); //empty list
//}
//
///*
//	6) Searching in the sequential list
//*/
//int searchSequentialList(List* anyList, KEYTYPE anyKey) {
//	int indx = 0;
//	while (indx < anyList->nbElem) {
//		if (anyKey == anyList->tabElem[indx].key)
//			return indx;// Element Found!
//		indx++;
//	}
//	return -1;// Element not found!
//}
//
///*
//	7) Inserting one element in a specific position
//		*Defining features:
//		1. If the list is not full and it is a valid position (index)
//			1.1 All previous elements will be placed/copy to the right
//			1.2 Insert/assign the element in the desired position
//			1.3 Increment nbElement
//			1.4 return true
//		1.1 Else 
//			1.1.1 Return false
//*/
//bool insertElemList(List* anyList, Register anyReg, int pos) {
//	int indx;
//
//	if ((anyList->nbElem == MAX) || (pos < 0) || pos > anyList->nbElem)
//		return false;
//
//	//	In order to release position and replace the elements to the 
//	// right index while searching, it searches the "pos" from back to front.
//	for (indx = anyList->nbElem; indx > pos; indx--) {
//		anyList->tabElem[indx] = anyList->tabElem[indx - 1];
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
//	int pos = searchSequentialList(anyList, anyKey);
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
//int mainList() {
//
//	List myList;
//	initializeSequentialList(&myList);
//
//	Register crrYear;
//	crrYear.key = 2020;
//	insertElemList(&myList, crrYear, 0);
//	crrYear.key = 500;
//	insertElemList(&myList, crrYear, 1);
//	displayList(&myList);
//
//	return 0;
//}