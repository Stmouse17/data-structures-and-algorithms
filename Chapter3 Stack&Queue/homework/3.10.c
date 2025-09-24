#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int data;
	Node* next;
}Node;

Node* InitLinkList()
{
	Node* head = (Node*)malloc(sizeof(Node));
	if (!head)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	head->next = NULL;
	return head;
}

void HeadInsert(Node* head, int value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (!newNode)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	newNode->data = value;
	newNode->next = head->next;
	head->next = newNode;
}

int GetMax(Node* head)
{
	if (!head->next)
		return head->data;
	else
	{
		int max = GetMax(head->next);
		return head->data >= max ? head->data : max;
	}
}

int GetLength(Node* head)
{
	if (!head->next)
		return 0;
	else
		return 1 + GetLength(head->next);
}

int GetAverage(Node* n)
{
	printf("Easy...\n");
}