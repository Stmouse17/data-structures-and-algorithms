#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node
{
	int data;
	struct Node* link;
}Node;

Node* InitList()
{
	Node* list = (Node*)malloc(sizeof(Node));
	if (list)
	list->data = 0;
	list->link = NULL;
	return list;
}

void TailInsert(Node* list, int data)
{
	Node* head = list;
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->link = NULL;
	while (list->link)
	{
		list = list->link;
	}
	list->link = node;
	head->data++;
}

void PrintList(Node* list)
{
	Node* H = list;
	list = list->link;
	while (list)
	{
		printf("%d ", list->data);
		list = list->link;
	}
	printf("NULL\n");
	printf("%d ", H->data);
}

void DeleteEqualNode(Node* H, int n)
{
	int* arr = (int*)malloc(sizeof(int));
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = 0;
	}
	Node* p = H->link;
	Node* q = H;
	while (p)
	{

		if (arr[abs(p->data)] == 1)
		{
			q->link = p->link;
			free(p);
			p = q->link;
			H->data--;
		}
		else
		{
			arr[abs(p->data)] = 1;
			q = p;
			p = p->link;
		}
	}
}

int main()
{
	printf("Sintream_ouse\n");
	Node* H = InitList();
	TailInsert(H, 1);
	TailInsert(H, 7);
	TailInsert(H, 17);
	TailInsert(H, 27);
	TailInsert(H, 17);
	TailInsert(H, -7);
	TailInsert(H, -17);
	DeleteEqualNode(H, H->data);
	PrintList(H);
	return 0;
}
