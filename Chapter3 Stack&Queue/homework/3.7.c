#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5

typedef struct
{
	int* base;
	int front, rear;
	int tag;
}SqQueue;

void InitQueue(SqQueue* Q)
{
	Q->base = (int*)malloc(sizeof(int) * MAXSIZE);
	if (!Q->base)
	{
		printf("Memory allocation failed!\n");
		exit(1);
	}
	Q->front = Q->rear = 0;
	Q->tag = 0;
}

void EnQueue(SqQueue* Q, int e)
{
	if ((Q->tag == 1) && (Q->front == Q->rear))
	{
		printf("Queue is full!\n");
		return;
	}
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	if (Q->front == Q->rear)
		Q->tag = 1;
}

void DeQueue(SqQueue* Q, int* e)
{
	if ((Q->tag == 0) && ((Q->rear) == (Q->front)))
	{
		printf("Queue is empty\n");
		return;
	}
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	if (Q->front == Q->rear)
		Q->tag = 0;
}

int main()
{
	printf("Sintream_ouse\n");
	SqQueue* Q = (SqQueue*)malloc(sizeof(SqQueue));
	int e = 0;
	InitQueue(Q);
	EnQueue(Q, 1);
	EnQueue(Q, 2);
	EnQueue(Q, 3);
	EnQueue(Q, 4);
	EnQueue(Q, 5);
	//EnQueue(Q, 6);
	DeQueue(Q, &e);
	DeQueue(Q, &e);
	DeQueue(Q, &e);
	DeQueue(Q, &e);
	DeQueue(Q, &e);
	//DeQueue(Q, &e);
	return 0;
}
