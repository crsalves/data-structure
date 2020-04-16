#pragma once
#include<stdio.h>
#include<malloc.h>

#define true 1
#define false 0
typedef int bool;

typedef struct tmpNode {
	float value;
	int column;
	struct tmpNode* next;
}Node;

typedef Node* Pointer;

typedef struct {
	Pointer* Matrix;
	int rows;
	int columns;
}Array;

// Initialization 
void initializeArray(Array* nArray, int nRow, int nColumn) {
	nArray->rows = nRow;
	nArray->columns = nColumn;
	nArray->Matrix = (Pointer*)malloc(nColumn * sizeof(Pointer));
	for (int indx = 0; indx < nRow; indx++)
		nArray->Matrix[indx] = NULL;
}

// Inserting
bool insertElemArray(Array* nArray, int nRow, int nColunm, float nValue) {
	if ((nRow < 0))
		return false;

	if (nRow >= nArray->rows)
		return false;

	if (nColunm < 0)
		return false;

	if (nColunm >= nArray->columns)
		return false;

	Pointer prev = NULL;
	Pointer current = nArray->Matrix[nRow];

	while ((current != NULL) && (current->column < nColunm)) {
		prev = current;
		current = current->next;
	}

	// Checking if the position already exists and it is valid
	if ((current != NULL) && (current->column == nColunm)) {
		if (nValue == 0) {
			if (prev == NULL)
				nArray->Matrix[nRow] = current->next;
			prev->next = current->next;
			free(current);
		}
		current->value = nValue;
	}
	else {
		Pointer newElem = (Pointer)malloc(sizeof(Node));
		newElem->column = nColunm;
		newElem->value = nValue;
		newElem->next = current;
		if (prev == NULL)
			nArray->Matrix[nRow] = newElem;
		else
			prev->next = newElem;
	}
	return true;
}

float accessArray(Array* nArray, int nRow, int nColumn) {
	if ((nRow < 0))
		return false;

	if(nRow >= nArray->rows) 
		return false;

	if (nColumn < 0)
		return false;

	if (nColumn >= nArray->columns)
		return false;

	Pointer current = nArray->Matrix[nRow];

	while ((current != NULL) && (current->column < nColumn))
		current = current->next;

	if ((current != NULL) && (current->column = nColumn))
		return current->value;

	return 0;
}

void displayArray(Array* nArray, int nRow, int nColumn) {
	Pointer current = nArray->Matrix[nRow];
	while (current != NULL)
	{
		printf("%i\n", nArray->Matrix[nColumn]->value);
		current = current->next;
	}
}