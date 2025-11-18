#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode
{
	int data;
	struct BSTNode* lchild, * rchild;
} BSTNode, *BSTree;

void PrintGE(BSTree T, int x)
{
	if (!T)
		return;
	if (T->data >= x)
	{
		PrintGE(T->lchild, x);
		printf("%d ", T->data);
		PrintGE(T->rchild, x);
	}
	else
		PrintGE(T->rchild, x);
}

int main()
{
	BSTNode* A = (BSTNode*)malloc(sizeof(BSTNode));
	BSTNode* B = (BSTNode*)malloc(sizeof(BSTNode));
	BSTNode* C = (BSTNode*)malloc(sizeof(BSTNode));
	BSTNode* D = (BSTNode*)malloc(sizeof(BSTNode));
	BSTNode* E = (BSTNode*)malloc(sizeof(BSTNode));
	BSTNode* F = (BSTNode*)malloc(sizeof(BSTNode));
	BSTNode* G = (BSTNode*)malloc(sizeof(BSTNode));
	A->data = 7; A->lchild = B; A->rchild = C;
	B->data = 5; B->lchild = D; B->rchild = E;
	C->data = 9; C->lchild = F; C->rchild = G;
	D->data = 1; D->lchild = NULL; D->rchild = NULL;
	E->data = 6; E->lchild = NULL; E->rchild = NULL;
	F->data = 8; F->lchild = NULL; F->rchild = NULL;
	G->data = 10; G->lchild = NULL; G->rchild = NULL;
	PrintGE(A, 7);
	return 0;
}