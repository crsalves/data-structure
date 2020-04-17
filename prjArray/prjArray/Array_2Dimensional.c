#include"arraylib.h"

int main() {
	Array myArray;
	initializeArray(&myArray, 3, 4);

	
	insertElemArray(&myArray, 1, 1, 2.5);

	displayArray(&myArray, 1, 1);
	
	return 0;
}