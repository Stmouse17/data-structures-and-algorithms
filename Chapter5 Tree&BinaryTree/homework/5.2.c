#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int data;
	struct BTNode* lchild, * rchild;
}BTNode;

int CmpBTree(BTNode* T1, BTNode* T2)
{
	if (T1 == NULL && T2 == NULL)
		return 1;
	else if (T1 == NULL || T2 == NULL)
		return 0;
	else
	{
		if (T1->data != T2->data)
			return 0;
		else
			return CmpBTree(T1->lchild, T2->lchild) && CmpBTree(T1->rchild, T2->rchild);
	}
}

int main()
{
	BTNode* A1 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* B1 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* C1 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* D1 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* A2 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* B2 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* C2 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* D2 = (BTNode*)malloc(sizeof(BTNode));
	A1->data = 1; A2->data = 1;
	B1->data = 2; B2->data = 2;
	C1->data = 3; C2->data = 3;
	D1->data = 4; D2->data = 4;
	A1->lchild = B1; A2->lchild = B2;
	A1->rchild = C1; A2->rchild = C2;
	B1->lchild = D1; B2->lchild = D2;
	B1->rchild = NULL; B2->rchild = NULL;
	C1->lchild = NULL; C2->lchild = NULL;
	C1->rchild = NULL; C2->rchild = NULL;
	D1->lchild = NULL; D2->lchild = NULL;
	D1->rchild = NULL; D2->rchild = NULL;
	printf("%d\n", CmpBTree(A1, A2));
	return 0;
}