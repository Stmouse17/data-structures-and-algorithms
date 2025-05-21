#include <stdio.h>
#include <stdlib.h>
#define FLASE 0
#define TRUE 1

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

Node* InitList()
{
	Node* H = (Node*)malloc(sizeof(Node));
	H->data = 0;
	H->data = H;
	return H;
}

void HeadInsert(Node* H, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = H->next;
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
	Node* n = H;
	Node* node = (Node*)malloc(sizeof(Node*));
	node->data = data;
	while (n->next != H)
	{
		n = n->next;
	}
	node->next = H;
	n->next = node;
}

int DeleteNode(Node* H, int data)
{
	Node* pre = H;
	Node* current = H->next;
	while (current != H)
	{
		if (current->data == data)
		{
			pre->next = current->next;
			free(current);
			return TRUE;
		}
		pre = current;
		current = current->next;
	}
	return FLASE;
}




