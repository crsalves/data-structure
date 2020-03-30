/*!	\file		Linked_List_Circular.c
	\author		Carla Alves
	\date		2020-03-29

	Dinamic implamentation of a linked linear list:
	1) Physically, the elements are spreadly stored in the computer memory;
	2) All elements have the address of the 'next element position', except the last element;
	3) It is necessary to know the 'first element position';
	4) Every new element, it allocates a space in memory dinamically;
*/
#include"listLib.h"

int main() {

	List myList;
	initializeLinkListCircular(&myList);

	Register crrYear;
	crrYear.key = 20;
	insertElemLinkListOrdCircular(&myList, crrYear);
	crrYear.key = 10;
	insertElemLinkListOrdCircular(&myList, crrYear);
	crrYear.key = 30;
	insertElemLinkListOrdCircular(&myList, crrYear);
	crrYear.key = 40;
	insertElemLinkListOrdCircular(&myList, crrYear);
	displayLinkedListCircular(&myList);

	crrYear.key = 30;
	printf("%i\n", searchSeqLinkListOrdCircular(&myList, crrYear.key));
	printf("First element is %i\n", getFstElemLinkListCircular(&myList));
	printf("Last element is %i\n", getLstElemLinkListCircular(&myList));

	reinitializeSeqLinkListCircular(&myList);
	return 0;
}