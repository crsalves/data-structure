#pragma once
#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int Keytype;

typedef struct aux {
	Keytype key;
	/* Data goes here */
	struct aux* left, * right;
}Node;

typedef Node* Pointer;

// Initialization
Pointer initializeBinaryTree() {
	return (NULL);
}

// Inserting one element
Pointer insertBinaryTree(Pointer nRoot, Pointer nNode) {
	if (nRoot == NULL)
		return (nNode);

	if (nNode->key < nRoot->key)
		nRoot->left = insertBinaryTree(nRoot->left, nNode);
	else
		nRoot->right = insertBinaryTree(nRoot->right, nNode);

	// Discarting repeated values
	return (nRoot);
}

// Auxiliary Function: use this function before calling insert()
Pointer createNewNode(Keytype nKey) {
	Pointer newNode = (Pointer)malloc(sizeof(Node));
	newNode->left = NULL;
	newNode->right = NULL;

	newNode->key = nKey;
	return (newNode);
}

// Searching elements
Pointer containElemBinaryTree(Keytype nKey, Pointer nRoot) {
	if (nRoot == NULL)
		return (NULL);

	if (nRoot->key == nKey)
		return (nRoot);

	if (nRoot->key > nKey)
		return (containElemBinaryTree(nKey, nRoot->left));
	return (containElemBinaryTree(nKey, nRoot->right));
}

// Counting numbers of elements
int countNode(Pointer nRoot) {
	if (!nRoot)
		return 0;
	return (countNode(nRoot->left) + 1 + (countNode(nRoot->right)));
}

// Exhibition
void displayBinaryTree(Pointer nRoot) {
	if (nRoot != NULL) {
		printf("%i\n", nRoot->key);
		displayBinaryTree(nRoot->left);
		displayBinaryTree(nRoot->right);
	}
}

// Searching Nodes
Pointer findNodeBinaryTree(Pointer nRoot, Keytype nKey, Pointer* nParent) {
	Pointer currentNode = nRoot;
	*nParent = NULL;
	while (currentNode) {
		if (currentNode->key == nKey)
			return currentNode;

		*nParent = currentNode;
		if (nKey < currentNode->key)
			currentNode = currentNode->left;
		currentNode = currentNode->right;
	}
	return NULL;
}

// Deleting
Pointer deleteOneNodeBinaryTree(Pointer nRoot, Keytype nKey) {
	Pointer nodeParent, node4Deleting, tmpParent, tmpChild;
	node4Deleting = findNodeBinaryTree(nRoot, nKey, &nodeParent);

	if (node4Deleting == NULL)
		return nRoot;

	// Before delete the node, test if it has only one child
	if ((!node4Deleting->left) || (!node4Deleting->right)) {
		if (!node4Deleting->left)
			tmpChild = node4Deleting->right;
		else
			tmpChild = node4Deleting->left;
	}
	else { // when the node (which will be deleted) has more than one child
		tmpParent = node4Deleting; // Mark the node as a parent too
		tmpChild = node4Deleting->left; // And store its left child to check if it has a child as well

		while (tmpChild->right) { // while it has children
			tmpParent = tmpChild; // Mark the child as a parent
			tmpChild = tmpChild->right; // And store its right child to check if it has a child as well
		}

		if (tmpParent != node4Deleting) {
			tmpParent->right = tmpChild->left;
			tmpChild->left = node4Deleting->left;
		}

		tmpChild->right = node4Deleting->right;
	}

	if (!nodeParent) {
		free(node4Deleting);
		return tmpChild;
	}

	if (nKey < nodeParent->key)
		nodeParent->left = tmpChild;
	else
		nodeParent->right = tmpChild;

	free(node4Deleting);
	return nRoot;
}
