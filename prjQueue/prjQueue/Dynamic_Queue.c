#include"queuelib.h"

int main() {
	StaticQueue myQueue;
	initializeDynamicQueue(&myQueue);

	Register myReg;
	myReg.key = 1;
	insertDynamicQueue(&myQueue, myReg);
	myReg.key = 2;
	insertDynamicQueue(&myQueue, myReg);
	myReg.key = 3;
	insertDynamicQueue(&myQueue, myReg);

	displayDynamicQueue(&myQueue);
	delOneElemDynamicQueue(&myQueue, &myReg);
	myReg.key = 4;
	insertDynamicQueue(&myQueue, myReg);
	displayDynamicQueue(&myQueue);

	restartDynamicQueue(&myQueue);
	printf("\nRestarting...");
	displayDynamicQueue(&myQueue);
	printf(" done!");

	return 0;
}