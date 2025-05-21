#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1

typedef struct Node
{
	int data;
	struct Node* pre;
	struct Node* next;
}Node;

Node* InitList()
{
	Node* H = (Node*)malloc(sizeof(Node));
	H->data = 0;
	H->next = H;
	H->pre = H;
	return H;
}

void HeadInsert(Node* H, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->pre = H;
	node->next = H->next;
	H->next->pre = node;
	H->next = node;
	H->data++;
}

void PrintList(Node* H)
{
	Node* node = H->next;
	while (node != H)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("NULL\n");

}

void TailInsert(Node* H, int data)
{
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = data;
	Node* node = H;
	while (node->next != H)
	{
		node = node->next;
	}
	n->next = H;
	n->pre = node;
	node->next = n;
	H->pre = n;
	H->data++;
}

void DeleteList(Node* H, int data)
{
	Node* node = H->next;
	while (node != H)
	{
		if (node->data == data)
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
