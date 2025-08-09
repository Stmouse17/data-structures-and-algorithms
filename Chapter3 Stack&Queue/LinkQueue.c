#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	Node* next;
}Node;

typedef struct
{
	Node* head;
	Node* rear;
}LinkQueue;

void InitQueue(LinkQueue* q)
{
	q->head = q->rear = (Node*)malloc(sizeof(Node));
	if (!q->head)
		exit(0);
	q->head->next = NULL;
}

void InsertQueue(LinkQueue* q, int data)
{
	Node* p;
	p = (Node*)malloc(sizeof(Node));
	if (!p)
		exit(0);
	p->data = data;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
}

void DeleteQueue(LinkQueue* q, int* reception)
{
	Node* p;
	if (q->head = q->rear)
		return;
	p = q->head->next;
	*reception = p->data;
	q->head->next = p->next;
	if (q->rear = p)
		q->rear = q->head;
	free(p);
}

void DestroyQueue(LinkQueue* q)
{
	while (q->head)
	{
		q->rear = q->head->next;
		free(q->head);
		q->head = q->rear;
	}
}
