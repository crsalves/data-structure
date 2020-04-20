#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define true 1
#define false 0
#define ALPHABET 26

typedef int bool;
typedef int Keytype;

typedef struct aux {
	Keytype key;
	/* Data goes here */
	struct aux* left, * right;
}Node1;
typedef Node1* Pointer1;


// Non_Binary_Tree
typedef struct auxNode {
	Keytype key;
	/* Data goes here */
	struct auxNode* firstChild, * nextChild;
}Node2;
typedef Node2* Pointer2;

typedef bool RETURNTYPE;

typedef struct axNode {
	struct axNode* children[ALPHABET];
	RETURNTYPE end;
}Node;

typedef Node* Pointer;

// Auxiliary Function
Pointer createTrieNode() {
	Pointer parent = NULL;

	parent = (Pointer)malloc(sizeof(Node));

	if (parent) {
		parent->end = false;// It marks each node as it is not the end of the word
		for (int i = 0; i < ALPHABET; i++)
			parent->children[i] = NULL;
	}
	return parent;
}

// Initialization
Pointer initializeTrie() {
	return (createTrieNode());
}

// Mapping the Trie
int mapIndexTrie(char letter) {
	return ((int)letter - (int)'a');
}

// Inserting 
void insertTrie(Pointer nRoot, char* nKey) {
	int level;
	int length = strlen(nKey);
	int indx;

	Pointer parent = nRoot;
	for (level = 0; level < length; level++) {
		indx = mapIndexTrie(nKey[level]);

		if (!parent->children[indx])
			parent->children[indx] = createTrieNode();

		parent = parent->children[indx];
	}

	parent->end = true;
}

// Searching
bool findWord(Pointer nRoot, char* nKey) {
	int level;
	int length = strlen(nKey);
	int indx;

	Pointer parent = nRoot;
	for (level = 0; level < length; level++) {
		indx = mapIndexTrie(nKey[level]);

		if (!parent->children[indx])
			return false;

		parent = parent->children[indx];
	}

	return (parent->end);
}

// Initialization
Pointer1 initializeBinaryTree() {
	return (NULL);
}



// Auxiliary Function
Pointer2 createNewNode2(Keytype nKey) {
	Pointer2 newNode = (Pointer2)malloc(sizeof(Node2));
	newNode->firstChild = NULL;
	newNode->nextChild = NULL;
	newNode->key = nKey;
	return (newNode);
}

// Initialization
Pointer2 initializeNonBinaryTree(Keytype nKey) {
	return (createNewNode2(nKey));
}

// Inserting one element
Pointer1 insertBinaryTree(Pointer1 nRoot, Pointer1 nNode) {
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
Pointer1 createNewNode1(Keytype nKey) {
	Pointer1 newNode = (Pointer1)malloc(sizeof(Node1));
	newNode->left = NULL;
	newNode->right = NULL;

	newNode->key = nKey;
	return (newNode);
}

// Searching elements
Pointer2 containElemNonBinaryTree(Keytype nKey, Pointer2 nRoot) {
	if (nRoot == NULL)
		return NULL;

	if (nRoot->key == nKey)
		return (nRoot);

	Pointer2 parent = nRoot->firstChild;
	while (parent) {// Searching the child in the sub-tree where it is root
		Pointer2 tmp = containElemNonBinaryTree(nKey, parent);
		if (tmp)
			return tmp;

		parent = parent->nextChild;
	}
	return NULL;
}

// Inserting one element
bool insertNonBinaryTree(Pointer2 nRoot, Keytype nNewKey, Keytype nKeyParent) {
	Pointer2 parent = containElemNonBinaryTree(nKeyParent, nRoot);


	if (!parent)
		return (false);

	Pointer2 child = createNewNode2(nNewKey);
	Pointer2 firstborn = parent->firstChild;
	if (!parent)
		parent->firstChild = child;
	else {// when it already has children

		while (parent->nextChild)
			parent = parent->nextChild;

		parent->nextChild = child;
	}
	return (true);
}

// Searching elements
Pointer1 containElemBinaryTree(Keytype nKey, Pointer1 nRoot) {
	if (nRoot == NULL)
		return (NULL);

	if (nRoot->key == nKey)
		return (nRoot);

	if (nRoot->key > nKey)
		return (containElemBinaryTree(nKey, nRoot->left));
	return (containElemBinaryTree(nKey, nRoot->right));
}

// Counting numbers of elements
int countNode(Pointer1 nRoot) {
	if (!nRoot)
		return 0;
	return (countNode(nRoot->left) + 1 + (countNode(nRoot->right)));
}

// Exhibition
void displayBinaryTree(Pointer1 nRoot) {
	if (nRoot != NULL) {
		printf("%i\n", nRoot->key);
		displayBinaryTree(nRoot->left);
		displayBinaryTree(nRoot->right);
	}
}

// Exhibition
void displayNonBinaryTree(Pointer2 nRoot) {
	if (nRoot == NULL)
		return; // it is not a good practice for void function!

	printf("%i\n", nRoot->key);
	Pointer2 parent = nRoot->firstChild;
	while (parent) {
		displayNonBinaryTree(parent);
		parent = parent->nextChild;
	}	
}

// Searching Nodes
Pointer1 findNodeBinaryTree(Pointer1 nRoot, Keytype nKey, Pointer1* nParent) {
	Pointer1 currentNode = nRoot;
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
Pointer1 deleteOneNodeBinaryTree(Pointer1 nRoot, Keytype nKey) {
	Pointer1 nodeParent, node4Deleting, tmpParent, tmpChild;
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
