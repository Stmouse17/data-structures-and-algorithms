#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 100
#define AID 10

typedef struct SqStack	
{
	char* base;
	char* top;
	int size;
}SqStack;

void InitStack(SqStack* s)	
{
	s->base = (char*)malloc(SIZE * sizeof(char));
	if (!s->base)	
		exit(0);
	s->top = s->base;
	s->size = SIZE;
}

void Push(SqStack* s, char a)
{
	if (s->top - s->base >= s->size)	
	{
		s->base = (char*)realloc(s->base, (s->size + AID) * sizeof(char));
		if (!s->base)
			exit(0);
		s->top = s->base + s->size;
		s->size = s->size + AID;
	}
	*(s->top) = a;
	s->top++;
}

void Pop(SqStack* s, char* reception)
{
	if (s->base == s->top)
		return;
	*reception = *(--s->top);
}

int main()
{
	SqStack s;
	InitStack(&s);
	char a;
	int i = 0;
	int sum = 0;
	scanf("%c", &a);
	while (a != '#')
	{
		Push(&s, a);
		scanf("%c", &a);
	}
	getchar();
	int len = s.top - s.base;
	for (int i = 0; i < len; i++)
	{
		Pop(&s, &a);
		sum += (a - 48) * pow(2, i);
	}
	printf("%d", sum);
	return 0;
}