#define CRT_NO_SECURE_WARNINGS_
#include <stdio.h>

//���Ա�
typedef struct
{
	char name[20];
	int grade;
}student;

typedef struct
{
	student* elem;
	int length;
}Sqlist;

//һ����ԣ����Ա��������ʾ��