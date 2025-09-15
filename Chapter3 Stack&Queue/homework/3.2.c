#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20
#define AID 10
#define YES 1
#define NO 0

//

typedef struct
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

int IsPalindrome(char* t, SqStack* s)
{
	int length = strlen(t);
	int i = 0;
	for (i = 0; i < length / 2; i++)
		Push(s, t[i]);
	if (length % 2 != 0)
		i++;	//Skip the middle element when the string length is odd
	while (s->base != s->top)
	{
		char temp;
		Pop(s, &temp);
		if (temp != t[i])
			return NO;
		else
			i++;
	}
	return YES;
}

int main()
{
	printf("Sintream_ouse\n");
	char t[20] = "aababaa";
	SqStack* s = (SqStack*)malloc(sizeof(SqStack));
	if (!s) {
		fprintf(stderr, "Memory allocation failed for SqStack\n");
		exit(0);
	}
	InitStack(s);
	int signal = IsPalindrome(t, s);
	printf("%d\n", signal);
	return 0;
}