#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>
#include <stdlib.h>

void Count()
{
	int num[36] = { 0 };
	char ch;
	int i = 0;
	while ((ch = getchar()) != '\n')
	{
		if (ch >= '0' && ch <= '9')
			num[ch - '0']++;
		else if (ch >= 'a' && ch <= 'z')
			num[ch - 'a' + 10]++;
		else if (ch >= 'A' && ch <= 'Z')
			num[ch - 'A' + 10]++;
	}
	for (i = 0; i < 36; i++)
	{
		if (i < 10)
			printf("%c:%d\n", '0' + i, num[i]);
		else
			printf("%c:%d\n", 'a' + i - 10, num[i]);
	}
}

int main()
{
	Count();
	return 0;
}