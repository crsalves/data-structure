#include"stacklib.h"

/* 
	I have a stack of paper exams, but I want to divide them
	in to distinct stacks. The fail and the approved tests.
*/
int main() {
	DoubleStack myStack;
	initializeDoubleStack(&myStack);

	Register myReg;
	myReg.key = 5;
	pushDoubleStack(&myStack, myReg, 1);
	myReg.key = 34;
	pushDoubleStack(&myStack, myReg, 1);
	myReg.key = 2;
	pushDoubleStack(&myStack, myReg, 1);
	displayDoubleStack(&myStack, 1);

	// it always deletes the last element inserted (LIFO)
	popDoubleStack(&myStack, &myReg, 1);
	displayDoubleStack(&myStack, 1);

	restartDoubleStack(&myStack);
	displayDoubleStack(&myStack, 1);
	return 0;
}