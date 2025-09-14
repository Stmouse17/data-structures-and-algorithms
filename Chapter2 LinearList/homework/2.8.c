#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

Node* InitList()
{
	Node* list = (Node*)malloc(sizeof(Node));
	list->data = 0;
	list->next = NULL;
	return list;
}

void TailInsert(Node* list, int data)
{
	Node* head = list;
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	while (list->next)
	{
		list = list->next;
	}
	list->next = node;
	head->data++;
}

void PrintList(Node* list)
{
	list = list->next;
	while (list)
	{
		printf("%d ", list->data);
		list = list->next;
	}
	printf("NULL\n");
}
                          
void DeleteMinMax(Node* H, int Min, int Max)
{
	Node* p = H->next;
	Node* q = H->next;
	Node* pre = NULL;
	int count = 0;
	while (p && p->data <= Min)
	{
		pre = p;
		p = p->next;
	}
	while (q && q->data < Max)
		q = q->next;
	pre->next = q;
	while (p != q)
	{
		Node* tmp = p->next;
		free(p);
		p = tmp;
		count++;
	}
	H->data -= count;
}

int main()
{
	printf("Sintream_ouse\n");
	Node* H = InitList();
	TailInsert(H, 1);
	TailInsert(H, 2);
	TailInsert(H, 3);
	TailInsert(H, 4);
	TailInsert(H, 5);
	TailInsert(H, 6);
	TailInsert(H, 7);
	DeleteMinMax(H, 2, 6);
	PrintList(H);
	printf("%d ", H->data);
	return 0;
}
