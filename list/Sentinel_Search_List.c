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
//#include"listLib.h"
//
//int main() {
//
//	sentinelList myList;
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