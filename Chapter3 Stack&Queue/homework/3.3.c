#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXSIZE 20
/*
Review: Copilot looks too much like a wheelchair, suggest using your own thinking to handle problems.
*/
void InOutS(int s[])	//Pass in an array as a stack
{
	int top = 0;	//Stack top pointer
	int bottom = 0;	//Stack bottom pointer
	int i = 0;
	int n = 7;
	int x = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if (x != -1)
		{
			if (top == MAXSIZE - 1)
			{
				printf("Stack Full\n");
				exit(0);
			}
			else
				s[++top] = x;
		}
		else
		{
			if (top == 0)
			{
				printf("Stack Empty\n");
				exit(0);
			}
			else
				printf("%d\n", s[top--]);
		}
	}
}

int main()
{
	int s[MAXSIZE];
	InOutS(s);
	return 0;
}

