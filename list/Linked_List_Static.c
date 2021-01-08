///*!	\file		Linked_List_Static.c
//	\author		Carla Alves
//	\date		2020-03-27
//
//	Static implamentation of a linked linear list:
//	1) Physically, the elements are spreadly stored in the computer memory;
//	2) All elements have the address of the 'next element position', except the last element;
//	3) It is necessary to know the 'first element position';
//*/
//#include"listLib.h"
//
//int main() {
//
//	staticLinkList myList;
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