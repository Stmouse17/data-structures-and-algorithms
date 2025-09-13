#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAXSIZE 20

typedef struct
{
	char data[MAXSIZE];
	int length;
}SqString;

//Normal version

void GetNext(SqString t, int next[])
{
	int j = 0;
	int k = -1;
	next[0] = k;
	while (j < t.length - 1)
	{
		if (k == -1 || t.data[j] == t.data[k])
			next[++j] = ++k;
		else
			k = next[k];
	}
}

int KMPIndex1(SqString s, SqString t)
{
	int i = 0, j = 0;
	int next[MAXSIZE];
	GetNext(t, next);
	while (i < s.length && j < t.length)
	{
		if (j == -1 || s.data[i] == t.data[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (j >= t.length)
		return (i - t.length);
	else
		return -1;
}

//Improved version

void GetNextval(SqString t, int nextval[])
{
	int j = 0;
	int k = -1;
	nextval[0] = k;
	while (j < t.length)
	{
		if (k == -1 || t.data[j] == t.data[k])
		{
			j++;
			k++;
			if (t.data[j] == t.data[k])
				nextval[j] = nextval[k];
			else
				nextval[j] = k;
		}
		else
			k = nextval[k];
	}
}

int KMPIndex2(SqString s, SqString t)
{
	int i = 0, j = 0;
	int nextval[MAXSIZE];
	GetNextval(t, nextval);
	while (i < s.length && j < t.length)
	{
		if (j == -1 || s.data[i] == t.data[j])
		{
			i++;
			j++;
		}
		else
			j = nextval[j];
	}
	if (j >= t.length)
		return (i - t.length);
	else
		return -1;
}

int main()
{
	printf("Sintream_ouse\n");
	
	//The set usecases can refer to
	SqString s, t;
	strcpy(s.data, "abbaccaba");
	strcpy(t.data, "cca");
	s.length = 9;
	t.length = 3;	//avoid categorizing '\n'into string
	/*
	SqString s = { { 'a','b','a','c','b','b','a','c','b'}, 9 };
	SqString t = { { 'c','b','b','a' }, 4 };
	*/
	int index1, index2;
	index1 = KMPIndex2(s, t);
	index2 = KMPIndex2(s, t);
	printf("%d\n", index1);
	printf("%d\n", index2);
	return 0;
}