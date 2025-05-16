#define CRT_NO_SECURE_WARNINGS_
#include <stdio.h>
#include <stdlib.h>

//单链表
//创建节点Node
typedef struct Node
{
	int data;
	struct Node* next;
}Node;
//初始化
Node* InitList()
{
	Node* list = (Node*)malloc(sizeof(Node));
	list->data = 0;
	list->next = NULL;
	return list;
}

void HeadInsert(Node* list, int data)		//头插法插入操作
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = list->next;
	list->next = node;
	list->data++;
}

void TailInsert(Node* list, int data)		//尾插法插入操作
{
	Node* head = list;						//参数list变化，需要保存头指针
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

void DeleteNode(Node* list, int data)
{
	Node* pre = list;
	Node* current = list->next;
	while (current)
	{
		if (current->data == data)
		{
			pre->next = current->next;
			free(current);
			list->data--;
			break;
		}
		pre = current;
		current = current->next;
	}
}

void PrintList(Node* list)
{
	list = list->next;
	while (list)
	{
		printf("%d ", list->data);
		list = list->next;
	}
	printf("\n");
}

int main()
{
	printf("Sintream_ouse\n");
	Node* list = InitList();
	HeadInsert(list, 1);
	HeadInsert(list, 2);
	HeadInsert(list, 3);
	HeadInsert(list, 4);
	HeadInsert(list, 5);
	TailInsert(list, 6);
	TailInsert(list, 7);
	TailInsert(list, 8);
	TailInsert(list, 9);
	TailInsert(list, 10);
	PrintList(list);
	printf("\n");
	DeleteNode(list, 5);
	DeleteNode(list, 10);
	DeleteNode(list, 6);
	PrintList(list);
	return 0;
}



