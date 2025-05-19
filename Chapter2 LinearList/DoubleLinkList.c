#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1

typedef struct
{
	Node* pre;
	int data;
	Node* next;
}Node;

Node* InitList()
{
	Node* H = (Node*)malloc(sizeof(Node));
	H->data = 0;
	H->pre = NULL;
	H->next = NULL;
	return H;
}

void HeadInsert(Node* H, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	if (H->next == NULL)
	{
		node->next = NULL;
		node->pre = H;
		H->next = node;
		H->data++;
	}
	else
	{
		node->next = H->next;
		node->pre = H;
		H->next->pre = node;
		H->next = node;
		H->data++;
	}
}

void PrintList(Node* H)
{
	Node* node = H->next;
	while (node)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("NULL\n");
}

void TailInsert(Node* H, int data)
{
	Node* node = H;
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = data;
	while (node->next)
	{
		node = node->next;
	}
	n->next = NULL;
	n->pre = node;
	node->next = n;
	H->data++;
}

void DeleteList(Node* H, int data)
{
	Node* node = H->next;
	while (node)
	{
		if (node->next == data)
		{
			node->pre->next = node->next;
			node->next->pre = node->pre;
			free(node);
			H->data--;
			return TRUE;
		}
		node = node->next;
	}
	return FALSE;
}

