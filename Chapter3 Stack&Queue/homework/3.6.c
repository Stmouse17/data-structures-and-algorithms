#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int data;
	Node* next;
}Node;

void InitSequence(Node* R)
{
	R = (Node*)malloc(sizeof(Node));
	if (!R)
	{
		printf("Failed");
		exit(1);
	}
	R->next = R;
	R->next->data = 0;
}

void ClearSequence(Node* R)
{
	Node* p = R->next->next;
	while (p != R->next)
	{
		Node* q = p;
		p = p->next;
		free(q);
	}
	R->next = R;
	R->next->data = 0;
}

int IsEmpty(Node* R)
{
	return R->next == R;
}

void Enter(Node* R, int e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (!p)
	{
		printf("Failed");
		exit(1);
	}
	R->next->data++;
	p->data = e;
	p->next = R->next;
	R->next = p;
	R = p;
}

void Exit(Node* R, int* e)
{
	if (IsEmpty(R))
	{
		printf("Empty");
		exit(1);
	}
	
	Node* p = R->next->next;
	int* e = p->data;
	R->next->next = p->next;
	R->next->data--;
	if (p = R)
	{
		R = R->next;
		R->next->data = 0;
	}
	free(p);
}

