#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Insert(char* s, char* t, int pos)
{
	if (pos < 0)
		pos = 0;
	int i, j;
	int length_s = 0, length_t = 0;
	while (s[length_s] != '\0')
		length_s++;
	while (t[length_t] != '\0')
		length_t++;
	for (i = length_s; i >= pos; i--)
		s[i + length_t] = s[i];
	for (j = 0; j < length_t; j++)
		s[pos + j] = t[j];
}

int main()
{
	char s[100] = "mouse die";
	char t[] = "never ";
	int pos = 6;
	Insert(s, t, pos);
	printf("%s\n", s); 
	return 0;
}