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
	Node* origin = list;
	list = list->next;
	while (list)
	{
		printf("%d ", list->data);
		list = list->next;
	}
	printf("NULL ");
	printf("%d\n", origin->data);
}

int Max(Node* H)
{
	if (H->next == NULL)
		return NULL;
	Node* before = H->next;
	Node* after = H->next->next;
	while (after)
	{
		if (after->data > before->data)
		
			before = after;
		after = after->next;
	}
	return before->data;
}

int main()
{
	printf("Sintream_ouse\n");
	Node* H = InitList();
	TailInsert(H, -1);
	TailInsert(H, -7);
	TailInsert(H, 3);
	TailInsert(H, 2);
	TailInsert(H, 17);
	TailInsert(H, 7);
	int a = Max(H); 
	printf("%d ", a);
	return 0;
}
