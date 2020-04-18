#include"treelib.h"

int main() {

	Pointer myTree = initializeBinaryTree();
	Pointer myNode = createNewNode(10);

	myTree = insertBinaryTree(myTree, myNode);

	myNode = createNewNode(5);
	myTree = insertBinaryTree(myTree, myNode);

	displayBinaryTree(myTree);
	return 0;
}