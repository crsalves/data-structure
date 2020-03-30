/*!	\file		Linear_Sequential_List.c
	\author		Carla Alves
	\date		2020-03-25

	Implementation of a linear list data structure using auxiliary functions:
	1) Initialization;
	2) Display all elements;
	3) Total elements;
	4) Return the first element;
	5) Return the last element;
	6) Sequential search;
	7) Insert one element;
	8) Delete one element;
	9) Reinitialization;
*/
#include"listLib.h"

int main() {

	List myList;
	initializeSequentialList(&myList);

	Register crrYear;
	crrYear.key = 2020;
	insertElemList(&myList, crrYear, 0);
	crrYear.key = 500;
	insertElemList(&myList, crrYear, 1);
	displayList(&myList);

	return 0;
}