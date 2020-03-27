///*!	\file		Sentinel_Search_List.c
//	\author		Carla Alves
//	\date		2020-03-26
//
//	Optimization of the search function for a linear list data structure using sentinel:
//	1) Optimize one of the two EXPENSIVE steps in the "search function";
//
//	*Thinking process:
//	-The "comparison" step cannot be removed because it checks the key of the searched element;
//	-Then, the "insert mode" step must be the one which will be improved;
//
//	2) Change the order of inserting elements;
//	3) Create a list with an extra space (just in case of a full list) for the 'Sentinel' 
//		which will be placed after the last element;
//
//	*PROS x CONS:
//	-POSITIVE: The 'Sentinel' garantees a more efficient search because the 
//					key will always be found without testing for "out of bounds error";
//	-POSITIVE: It works for unordered lists. So, it allows inserting elements in any position;
//	-NEGATIVE: This extra position will be wasted all over the remainder functions;
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
//	Register tabElem[MAX+1]; // Create an extra element here!
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
//	6) Using 'Sentinel' for searching in the sequential list
//		*Using the 'if' statement to test inside a 'while loop' is not as 
//		efficient as checking the sentinel outside the loop
//*/
//int searchSentinelList(List* anyList, KEYTYPE anyKey) {
//	int indx = 0;
//
//	// 1) Placing the Sentinel after last valid position of the list
//	anyList->tabElem[anyList->nbElem].key = anyKey;
//
//	// 2) Using "while" instead of "for" because we don't know exactly how many iterations it will take
//	while (anyKey != anyList->tabElem[indx].key)
//		indx++;
//
//	// 3) Checking if it reached the sentinel
//	if (indx == anyList->nbElem)
//		return -1;// Element not found!
//	else
//		return indx;// Element found!
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
//	int pos = searchSentinelList(anyList, anyKey);
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
//int mainSentinel() {
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
//	crrYear.key = 2020;
//	printf("%i", searchSentinelList(&myList, crrYear.key));
//
//	return 0;
//}