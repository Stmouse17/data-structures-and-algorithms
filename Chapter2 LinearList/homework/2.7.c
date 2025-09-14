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

void Reverse(Node* H)
{
	Node* p = H->next;
	H->next = NULL;
	while (p)
	{
		Node* tmp = p->next;
		p->next = H->next;
		H->next = p;
		p = tmp;
	}
}

int main()
{
	printf("Sinream_ouse\n");
	Node* H = InitList();
	TailInsert(H, 1);
	TailInsert(H, 2);
	TailInsert(H, 3);
	TailInsert(H, 4);
	TailInsert(H, 5);
	Reverse(H);
	PrintList(H);
	printf("%d ", H->data);
	return 0;
}
