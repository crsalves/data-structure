//#include"queuelib.h"
//
//int main() {
//	StaticQueue myQueue;
//	initializeStaticQueue(&myQueue);
//
//	Register myReg;
//	myReg.key = 1;
//	insertStaticQueue(&myQueue, myReg);
//	myReg.key = 2;
//	insertStaticQueue(&myQueue, myReg);
//	myReg.key = 3;
//	insertStaticQueue(&myQueue, myReg);
//
//	displayStaticQueue(&myQueue);
//	delOneElemStaticQueue(&myQueue, &myReg);
//	myReg.key = 4;
//	insertStaticQueue(&myQueue, myReg);
//	displayStaticQueue(&myQueue);
//
//	restartStaticQueue(&myQueue);
//	printf("\nRestarting...");
//	displayStaticQueue(&myQueue);
//	printf(" done!");
//
//	return 0;
//}