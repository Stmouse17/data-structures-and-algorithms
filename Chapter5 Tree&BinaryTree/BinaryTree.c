#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//Binary Linklist
typedef struct
{
	int data;
	struct BTNode* lchild, * rchild;
}BTNode;

//Traversing a binary tree using recursion

void PreOrder1(BTNode* T)
{
	if (T)
	{
		printf("%d\n", T->data);
		PreOrder1(T->lchild);
		PreOrder1(T->rchild);
	}
}

void InOrder1(BTNode* T)
{
	if (T)
	{
		InOrder1(T->lchild);
		printf("%d\n", T->data);
		InOrder1(T->rchild);
	}
}

void PostOrder1(BTNode* T)
{
	if (T)
	{
		PostOrder1(T->lchild);
		PostOrder1(T->rchild);
		printf("%d\n", T->data);
	}
}

//Traversing a binary tree using dynamic programming

void PreOrder2(BTNode* T)
{
	BTNode* St[100];
	int top = -1;
	BTNode* p = T;
	while (p || top != -1)
	{
		if (p)
		{
			printf("%d\n", p->data);
			St[++top] = p;
			p = p->lchild;
		}
		else
		{
			p = St[top--];
			p = p->rchild;
		}
	}
}

void InOrder2(BTNode* T)
{
	BTNode* St[100];
	int top = -1;
	BTNode* p = T;
	while (p || top != -1)
	{
		if (p)
		{
			St[++top] = p;
			p = p->lchild;
		}
		else
		{
			p = St[top--];
			printf("%d\n", p->data);
			p = p->rchild;
		}
	}
}

//Copilot has provided an almost optimal solution here, which is very impressive.
//Without realizing it, will AI replace human programmers in the future? 

void PostOrder2(BTNode* T)
{
	BTNode* St[100];
	BTNode* p = T;
	BTNode* r = NULL;
	int top = -1;
	while (p || top != -1)
	{
		if (p)
		{
			St[++top] = p;
			p = p->lchild;
		}
		else
		{
			p = St[top];
			if (p->rchild && p->rchild != r)
				p = p->rchild;
			else
			{
				top--;
				printf("%d\n", p->data);
				r = p;
				p = NULL;
			}
		}
	}
}

//Hierarchical traversal of binary trees

void LevelOrder(BTNode* T)
{
	BTNode* Q[100];
	int front = 0, rear = 0;
	BTNode* p = T;
	if (p)
	{
		rear = (rear + 1) % 100;
		Q[rear] = p;
	}
	while (front != rear)
	{
		front = (front + 1) % 100;
		p = Q[front];
		printf("%d\n", p->data);
		if (p->lchild)
		{
			rear = (rear + 1) % 100;
			Q[rear] = p->lchild;
		}
		if (p->rchild)
		{
			rear = (rear + 1) % 100;
			Q[rear] = p->rchild;
		}
	}
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
	printf("PreOrder1:\n");
	PreOrder1(A);
	printf("InOrder1:\n");
	InOrder1(A);
	printf("PostOrder1:\n");
	PostOrder1(A);
	printf("PreOrder2:\n");
	PreOrder2(A);
	printf("InOrder2:\n");
	InOrder2(A);
	printf("PostOrder2:\n");
	PostOrder2(A);
	printf("LevelOrder:\n");
	LevelOrder(A);
	free(A);
	free(B);
	free(C);
	free(D);
	free(E);
	free(F);
	free(G);
	return 0;
}




