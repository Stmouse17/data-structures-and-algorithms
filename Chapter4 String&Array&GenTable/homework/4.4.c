#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void Format(char s1[], char s2[], char s3[], int n)
{
	int len = strlen(s1);
	int i, j = 0;
	int wordlen = 0;
	int space_count, extra;
	int pos = 0;
	if (len < n)
	{
		strcpy(s2, s1);
		s3[0] = '\0';
		return;
	}
	for (i = n - 1; i >= 0; i--)
	{
		if (s1[i] == ' ')
		{
			pos = i;
			break;
		}
	}

	if (pos == 0)
		pos = n;
	strncpy(s2, s1, pos);
	s2[pos] = '\0';
	while (s1[0] == ' ')
		memmove(s2, s2 + 1, strlen(s2));
	while (s2[strlen(s2) - 1] == ' ')
		s2[strlen(s2) - 1] = '\0';
	strcpy(s3, s1 + pos + 1);
}

int main() 
{
	char s1[200] = "This is a simple example to demonstrate text formatting.";
	char s2[100], s3[100];
	int n = 25;
	Format(s1, s2, s3, n);
	printf("s2 = \"%s\"\n", s2);
	printf("s3 = \"%s\"\n", s3);
	return 0;
}