#include"dequelib.h"

int main() {
	Deque myDeque;
	initializeDeque(&myDeque);

	Register myReg;
	myReg.key = 5;
	insertDequeEnd(&myDeque, myReg);
	myReg.key = 34;
	insertDequeEnd(&myDeque, myReg);
	myReg.key = 2;
	insertDequeEnd(&myDeque, myReg);
	displayDeque(&myDeque);

	delElemDeque(&myDeque, &myReg);
	displayDeque(&myDeque);

	return 0;
}