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
//#include"listLib.h"
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