#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
#define AID 10

typedef struct 
{
	double* base;
	double* top;
	int size;
}SqStack;

void InitStack(SqStack* s)
{
	s->base = (double*)malloc(SIZE * sizeof(double));
	if (!s->base)
		exit(0);
	s->top = s->base;
	s->size = SIZE;
}

void Push(SqStack* s, double a)
{
	if (s->top - s->base >= s->size)
	{
		s->base = (double*)realloc(s->base, (s->size + AID) * sizeof(double));
		if (!s->base)
			exit(0);
		s->top = s->base + s->size;
		s->size = s->size + AID;
	}
	*(s->top) = a;
	s->top++;
}

void Pop(SqStack* s, double* reception)
{
	if (s->base == s->top)
		return;
	*reception = *(--s->top);
}

double Calculator()
{
	//Set up a stack to store operands 
	SqStack* s = (SqStack*)malloc(sizeof(SqStack));
	InitStack(s);
	double result = 0.0;
	double a, b;
	char ch = getchar();
	while (ch != '$')
	{
		if ((ch >= '0' && ch <= '9') || ch == '.')
		{
			int i = 0;
			char num[10];
			while ((ch >= '0' && ch <= '9') || ch == '.')
			{
				num[i++] = ch;
				ch = getchar();
			}
			result = atof(num);
			Push(s, result);
		}
		/*
		if (ch == ' ')
			ch = getchar();
		else
		{
			Pop(s, &b);
			Pop(s, &a);
			switch (ch)
			{
			case'+': Push(s, a + b); break;
			case'-': Push(s, a - b); break;
			case'*': Push(s, a * b); break;
			case'/': Push(s, a / b); break;
			}
			ch = getchar();
		}
	}
	return *(s->top - 1);
	*/
		switch (ch)
		{
		case' ': break;
		case'+': Pop(s, &b); Pop(s, &a); Push(s, a + b); break;
		case'-': Pop(s, &b); Pop(s, &a); Push(s, a - b); break;
		case'*': Pop(s, &b); Pop(s, &a); Push(s, a * b); break;
		case'/': Pop(s, &b); Pop(s, &a); Push(s, a / b); break;
		}
		ch = getchar();
	}
	return *(s->top - 1);
}



int main()
{
	printf("Please enter a postfix expression (end with $): ");
	double result = Calculator();
	printf("The result is: %.2f\n", result);
	return 0;
}