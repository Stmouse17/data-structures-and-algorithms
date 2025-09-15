#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1

typedef struct
{
	int top[2], bot[2];
	//Avoid using fixed length array, otherwise it's not conducive to allocating space during initialization
	int* V;	
	int m;
}DblStack;

void InitDblStack(DblStack* S)
{
	S->V = (int*)malloc(S->m * sizeof(int));
	S->bot[0] = -1;
	S->bot[1] = S->m;
	S->top[0] = -1;
	S->top[1] = S->m;
}

int DblPush(DblStack* S, int i, int x)
{
	if (S->top[1] - S->top[0] == 1)
		return ERROR;
	if (i)
		S->V[--S->top[1]] = x;
	else
		S->V[++S->top[0]] = x;
	return OK;
}

int DblPop(DblStack* S, int i, int x)
{
	if (S->bot[i] == S->top[i])
		return ERROR;
	if (i)
		x = S->V[S->top[1]++];
	else
		x = S->V[S->top[0]--];
	return OK;
}

int IsEmpty(DblStack* S, int i)
{
	return S->top[i] == S->bot[i];
}

int IsFull(DblStack* S)
{
	return S->top[0] + 1 == S->top[1];
}