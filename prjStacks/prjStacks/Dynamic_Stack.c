#include"stacklib.h"

int main() {
	DynamicStack myStack;
	initializeDynamicStack(&myStack);

	Register myReg;
	myReg.key = 5;
	pushDynamicStack(&myStack, myReg);
	myReg.key = 34;
	pushDynamicStack(&myStack, myReg);
	myReg.key = 2;
	pushDynamicStack(&myStack, myReg);
	displayDynamicStack(&myStack);

	// it always deletes the last element inserted (LIFO)
	popDynamicStack(&myStack, &myReg);
	displayDynamicStack(&myStack);
	
	return 0;
}