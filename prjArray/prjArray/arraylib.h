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
	int row;
	int column;
}Array_2D;

// BOOK
typedef struct Struture {
	int row;
	int column;
	// TIPOINFO info;
	struct Struture* next;
}Node2;

typedef struct {
	Node2* start;
}Matrix;



// Initialization 
void initializeArray(Array_2D* nArray, int nRow, int nColumn) {
	nArray->row = nRow;
	nArray->column = nColumn;
	nArray->Matrix = (Pointer*)malloc(nColumn * sizeof(Pointer));
	for (int indx = 0; indx < nRow; indx++)
		nArray->Matrix[indx] = NULL;
}

// Inserting
bool insertElemArray(Array_2D* nArray, int nRow, int nColunm, float nValue) {
	if ((nRow < 0))
		return false;

	if (nRow >= nArray->row)
		return false;

	if (nColunm < 0)
		return false;

	if (nColunm >= nArray->column)
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

float accessArray(Array_2D* nArray, int nRow, int nColumn) {
	if ((nRow < 0))
		return false;

	if(nRow >= nArray->row) 
		return false;

	if (nColumn < 0)
		return false;

	if (nColumn >= nArray->column)
		return false;

	Pointer current = nArray->Matrix[nRow];

	while ((current != NULL) && (current->column < nColumn))
		current = current->next;

	if ((current != NULL) && (current->column = nColumn))
		return current->value;

	return 0;
}

void displayArray(Array_2D* nArray) {
	Pointer current = nArray->Matrix[1];// First element is at position number 1

	while (current != NULL)
	{
		printf("%0.2f\n", current->value);
		current = current->next;
	}
}