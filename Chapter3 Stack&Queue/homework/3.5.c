#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define YES 1
#define NO 0

int Is_Legal(char* seq)
{
	int i = 0;
	int j, k;
	j = k = 0;
	while (seq[i] != '\0')
	{
		if (seq[i] == 'I')
			j++;
		else
			k++;
		if (k > j)
		{
			printf("Illegal Sequence\n");
			return NO;
		}
		i++;
	}
	if (k == j)
	{
		printf("Legal Sequence\n");
		return YES;
	}
	else
	{
		printf("Illegal Sequence\n");
		return NO;
	}
}

int main()
{
	char seq[12] = "IOIIOIOO";
	Is_Legal(seq);
	return 0;
}