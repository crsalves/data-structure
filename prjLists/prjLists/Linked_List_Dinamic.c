///*!	\file		Linked_List_Dinamic.c
//	\author		Carla Alves
//	\date		2020-03-29
//
//	Dinamic implamentation of a linked linear list:
//	1) Physically, the elements are spreadly stored in the computer memory;
//	2) All elements have the address of the 'next element position', except the last element;
//	3) It is necessary to know the 'first element position';
//	4) Every new element, it allocates a space in memory dinamically; 
//*/
//#include"listLib.h"
//
//int main() {
//
//	List myList;
//	initializeLinkListDinamic(&myList);
//
//	Register crrYear;
//	crrYear.key = 40;
//	insertElemLinkListOrdDinamic(&myList, crrYear);
//	crrYear.key = 10;
//	insertElemLinkListOrdDinamic(&myList, crrYear);
//	crrYear.key = 30;
//	insertElemLinkListOrdDinamic(&myList, crrYear);
//	crrYear.key = 20;
//	insertElemLinkListOrdDinamic(&myList, crrYear);
//	displayLinkedListDinamic(&myList);
//
//	crrYear.key = 20;
//	printf("%i\n", searchSeqLinkListOrdDinamic(&myList, crrYear.key));
//	printf("First element is %i\n", getFstElemLinkListDinamic(&myList));
//	printf("Last element is %i\n", getLstElemLinkListDinamic(&myList));
//
//	reinitializeSeqLinkListDinamic(&myList);
//	return 0;
//}