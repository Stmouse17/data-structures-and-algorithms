#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode
{
	int data;
	struct BTNode* lchild, * rchild;
}BTNode;

void ChangeLR(BTNode* T)
{
	BTNode* temp;
	if (T->lchild == NULL || T->rchild == NULL)
		return;
	else
	{
		temp = T->lchild;
		T->lchild = T->rchild;
		T->rchild = temp;
		ChangeLR(T->lchild);
		ChangeLR(T->rchild);
	}
}

int main()
{
	BTNode* A, * B, * C, * D, * E, * F, * G;
	A = (BTNode*)malloc(sizeof(BTNode));
	B = (BTNode*)malloc(sizeof(BTNode));
	C = (BTNode*)malloc(sizeof(BTNode));
	D = (BTNode*)malloc(sizeof(BTNode));
	E = (BTNode*)malloc(sizeof(BTNode));
	F = (BTNode*)malloc(sizeof(BTNode));
	G = (BTNode*)malloc(sizeof(BTNode));
	A->data = 1; B->data = 2; C->data = 3; D->data = 4; E->data = 5; F->data = 6; G->data = 7;
	A->lchild = B; A->rchild = C;
	B->lchild = D; B->rchild = E;
	C->lchild = F; C->rchild = G;
	D->lchild = NULL; D->rchild = NULL;
	E->lchild = NULL; E->rchild = NULL;
	F->lchild = NULL; F->rchild = NULL;
	G->lchild = NULL; G->rchild = NULL;
	ChangeLR(A);
	printf("%d %d %d %d %d %d %d\n", A->data, A->lchild->data, A->rchild->data, A->lchild->lchild->data, A->lchild->rchild->data, A->rchild->lchild->data, A->rchild->rchild->data);
	return 0;
}