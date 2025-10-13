#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int data;
	struct BTNode* lchild, * rchild;
}BTNode;

int LeafNodeNumber(BTNode* T)
{
	if (T == NULL)
		return 0;
	else if (T->lchild == NULL && T->rchild == NULL)
		return 1;
	else
		return LeafNodeNumber(T->lchild) + LeafNodeNumber(T->rchild);
}

int main()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	A->data = 1;
	B->data = 2;
	C->data = 3;
	D->data = 4;
	A->lchild = B;
	A->rchild = C;
	B->lchild = D;
	B->rchild = NULL;
	C->lchild = NULL;
	C->rchild = NULL;
	D->lchild = NULL;
	D->rchild = NULL;
	printf("Leaf Node Number: %d\n", LeafNodeNumber(A));
	return 0;
}