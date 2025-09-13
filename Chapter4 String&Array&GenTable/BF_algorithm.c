#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//Tips: Use debugging to solve problems encountered.
typedef struct
{
	char data[1000];
	int length;
}SqString;

int BF_index(SqString s, SqString t)
{
	int i = 0, j = 0;
	while (i < s.length && j < t.length)
	{
		if (s.data[i] == t.data[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;	
			j = 0;
		}
	}
	if (j >= t.length)
		return (i - t.length);
	else
		return (-1);
}

int main(void)
{
	SqString s, t;
	strcpy(s.data, "Sintream_ouse");
	//t.data[1000] = "ouse";
	strcpy(t.data, "eam_");
	s.length = 13;	//in fact,the length of the input string needs to be inctreased by 1(\n)
	t.length = 4;
	/*Do not use the sizeof function
	s once the SqString structure is established with a fixed length
	it defaults to 0 if not assigned a value*/
	printf("location:%d\n", BF_index(s, t));
	return 1;
}