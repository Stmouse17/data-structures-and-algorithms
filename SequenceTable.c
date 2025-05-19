#define CRT_NO_SECURE_WARNINGS_
#include <stdio.h>

//线性表
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

//一般而言，线性表用数组表示。