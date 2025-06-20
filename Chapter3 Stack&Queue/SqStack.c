#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
#define AID 10

typedef struct SqStack	//Õ»µÄ¶¨Òå
{
	int* base;
	int* top;
	int size;
}SqStack;

void InitStack(SqStack* s)	//³õÊ¼»¯
{
	s->base = (int*)malloc(SIZE * sizeof(int));
	if (!s->base)	//ÅÐ¶ÏÊÇ·ñÉêÇëÄÚ´æÊ§°Ü£»±ÜÃâ¾¯¸æ
		exit(0);
	s->top = s->base;
	s->size = SIZE;
}

void Push(SqStack* s, int a)
{
	if (s->top - s->base >= s->size)	//¿Õ¼ä²»×ã×·¼Ó´æ´¢
	{
		s->base = (int*)realloc(s->base, (s->size + AID) * sizeof(int));
		if (!s->base)
			exit(0);
		s->top = s->base + s->size;
		s->size = s->size + AID;
	}
	*(s->top) = a;
	s->top++;
}

void Pop(SqStack* s, int* reception)
{
	if (s->base == s->top)
		return;
	*reception = *(--s->top);
}

void ClearStack(SqStack* s)
{
	s->top = s->base;
}

void DestroyStack(SqStack* s)
{
	int i;
	for (i = 0; i < s->size; i++)
	{
		free(s->base);
		s->base++;
	}
	s->base = s->top = NULL;
	s->size = 0;
}