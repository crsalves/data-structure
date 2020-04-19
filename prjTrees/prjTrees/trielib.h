#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define N_ALPHABET 26

typedef bool RETURNTYPE;

typedef struct axNode {
	struct axNode* children[N_ALPHABET];
	RETURNTYPE end;
}Node;

typedef Node* Pointer;

// Initialization
Pointer initializeTrie() {
	return (createTrieNode());
}

// Auxiliary Function
Pointer createTrieNode() {
	Pointer parent = NULL;

	parent = (Pointer)malloc(sizeof(Node));

	if (parent) {
		parent->end = false;// It marks each node as it is not the end of the word
		for (int i = 0; i < N_ALPHABET; i++)
			parent->children[i] = NULL;
	}
	return parent;
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

