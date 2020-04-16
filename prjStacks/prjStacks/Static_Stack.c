#include"stacklib.h"

int main() {
	Stack myStack;
	initialize(&myStack);

	Register myReg;
	myReg.key = 5;
	pushStaticStack(&myStack, myReg);
	myReg.key = 34;
	pushStaticStack(&myStack, myReg);
	myReg.key = 2;
	pushStaticStack(&myStack, myReg);
	displayStack(&myStack);

	// it always deletes the last element inserted (LIFO)
	popStaticStack(&myStack, &myReg);
	displayStack(&myStack);
}

