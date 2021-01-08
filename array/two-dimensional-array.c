#include"arraylib.h"

int main() {
	Array_2D myArray;
	initializeArray(&myArray, 3, 4);
	insertElemArray(&myArray, 1, 1, 22.5);
	displayArray(&myArray);

	insertElemArray(&myArray, 1, 2, 34.5);
	displayArray(&myArray);
	
	return 0;
}