#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5

/*
	A circular queue is implemented using a array base[0...M-1] of length MAXSIZE.
	The queue head and tail pointers are denoted by front and rear,respeactively.
	When front == rear, the queue is empty.
	When (rear + 1) % MAXSIZE == front, the queue is full.
*/

typedef struct
{
	int* base;
	int front, rear;
}SqQueue;

void InitQueue(SqQueue* Q)
{
	Q->base = (int*)malloc(MAXSIZE * sizeof(int));
	if (!Q->base)
		exit(-1);
	Q->front = Q->rear = 0;
}

void EnQueue(SqQueue* Q, int e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
	{
		printf("Queue is full!\n");
		return;
	}
	Q->base[Q->front] = e;
	Q->front = (Q->front - 1 + MAXSIZE) % MAXSIZE;
}

void DeQueue(SqQueue* Q, int* e)
{
	if (Q->front == Q->rear)
	{
		printf("Queue is empty!\n");
		return;
	}
	*e = Q->base[Q->rear];
	Q->rear = (Q->rear - 1 + MAXSIZE) % MAXSIZE;
}

