#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode
{
	int data;
	struct BTNode* lchild, * rchild;
}BTNode;

void DoubleTraverse(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%d ", root->data);
	DoubleTraverse(root->lchild);
	printf("%d ", root->data);
	DoubleTraverse(root->rchild);
}

int main()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	BTNode* F = (BTNode*)malloc(sizeof(BTNode));
	BTNode* G = (BTNode*)malloc(sizeof(BTNode));
	A->data = 1; A->lchild = B; A->rchild = C;
	B->data = 2; B->lchild = D; B->rchild = E;
	C->data = 3; C->lchild = F; C->rchild = G;
	D->data = 4; D->lchild = NULL; D->rchild = NULL;
	E->data = 5; E->lchild = NULL; E->rchild = NULL;
	F->data = 6; F->lchild = NULL; F->rchild = NULL;
	G->data = 7; G->lchild = NULL; G->rchild = NULL;
	DoubleTraverse(A);
	printf("\n");
	return 0;
}
	