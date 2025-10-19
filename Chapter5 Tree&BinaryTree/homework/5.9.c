#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXV 20

typedef struct
{
	char data;
	int weight;
	struct BiTNode* lchild, * rchild;
}BiTNode, *BiTree;



int WPL(BiTree T, int depth)
{
	if (T == NULL)
		return 0;
	if (T->lchild == NULL && T->rchild == NULL)
		return depth * T->weight;
	else
		return WPL(T->lchild, depth + 1) + WPL(T->rchild, depth + 1);
}

int main()
{
	BiTNode* A = (BiTNode*)malloc(sizeof(BiTNode));
	BiTNode* B = (BiTNode*)malloc(sizeof(BiTNode));
	BiTNode* C = (BiTNode*)malloc(sizeof(BiTNode));
	BiTNode* D = (BiTNode*)malloc(sizeof(BiTNode));
	BiTNode* E = (BiTNode*)malloc(sizeof(BiTNode));
	BiTNode* F = (BiTNode*)malloc(sizeof(BiTNode));
	BiTNode* G = (BiTNode*)malloc(sizeof(BiTNode));
	A->data = 1; A->lchild = B; A->rchild = C; A->weight = 1;
	B->data = 2; B->lchild = D; B->rchild = E; B->weight = 1;
	C->data = 3; C->lchild = F; C->rchild = G; C->weight = 1;
	D->data = 4; D->lchild = NULL; D->rchild = NULL; D->weight = 2;
	E->data = 5; E->lchild = NULL; E->rchild = NULL; E->weight = 3;
	F->data = 6; F->lchild = NULL; F->rchild = NULL; F->weight = 4;
	G->data = 7; G->lchild = NULL; G->rchild = NULL; G->weight = 5;
	printf("WPL=%d\n", WPL(A, 0));
	return 0;
}


