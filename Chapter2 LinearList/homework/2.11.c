#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1

//ÎªÁË·½±ã£¬nextÖ¸ÌâÄ¿µÄlink¡£

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

int Search_k1(Node* H, size_t k)
{
	Node* p = H;
	if (k <= H->data)
	{
		for (int i = 0; i < H->data - k + 1; i++)
			p = p->next;
		printf("%d ", p->data);
		return TRUE;
	}
	else
		return FALSE;
}

int Search_k2(Node* H, size_t k)
{
	int count = 0;
	Node* p = H->next;
	Node* q = H->next;
	while (p)
	{
		if (count < k)
			count++;
		else q = q->next;
		p = p->next;
	}
	if (count == k)
	{
		printf("%d ", q->data);
		return TRUE;
	}
	else
		return FALSE;
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
	Search_k1(H, 2);
	Search_k2(H, 6);
	return 0;
}
