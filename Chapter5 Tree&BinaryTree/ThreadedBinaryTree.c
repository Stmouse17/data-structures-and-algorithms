#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//Accelerate the search for node predecessors and successors

typedef struct
{
	int data;
	struct TBTNode* lchild, * rchild;
	int ltag, rtag;
}TBTNode;



void InThread(TBTNode* p, TBTNode** pre)
{
	if (p)
	{
		InThread(p->lchild, pre);
		if (p->lchild == NULL)
		{
			p->lchild = *pre;
			p->ltag = 1;
		}
		if (*pre && (*pre)->rchild == NULL)
		{
			(*pre)->rchild = p;
			(*pre)->rtag = 1;
		}
		*pre = p;
		InThread(p->rchild, pre);
	}
}

void CreateInThread(TBTNode* root)
{
	TBTNode* pre = NULL;
	if (root)
	{
		InThread(root, &pre);
		pre->rchild = NULL;
		pre->rtag = 1;
	}
}

int main()
{
	TBTNode* A = (TBTNode*)malloc(sizeof(TBTNode));
	TBTNode* B = (TBTNode*)malloc(sizeof(TBTNode));
	TBTNode* C = (TBTNode*)malloc(sizeof(TBTNode));
	TBTNode* D = (TBTNode*)malloc(sizeof(TBTNode));
	TBTNode* E = (TBTNode*)malloc(sizeof(TBTNode));
	A->data = 1; A->lchild = B; A->rchild = C; A->ltag = 0; A->rtag = 0;
	B->data = 2; B->lchild = D; B->rchild = E; B->ltag = 0; B->rtag = 0;
	C->data = 3; C->lchild = NULL; C->rchild = NULL; C->ltag = 0; C->rtag = 0;
	D->data = 4; D->lchild = NULL; D->rchild = NULL; D->ltag = 0; D->rtag = 0;
	E->data = 5; E->lchild = NULL; E->rchild = NULL; E->ltag = 0; E->rtag = 0;
	CreateInThread(A);
	return 0;
}
