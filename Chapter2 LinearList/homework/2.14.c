#include <stdio.h>
#include <stdlib.h>

//特别说明，题目中模型原则上是二叉树，下面代码构造两个链表
//在比较时使用data不使用Node*指针。
//申教授说尽量不要取巧

typedef struct Node
{
	char data;
	struct Node* next;
}Node;

Node* InitList()
{
	Node* list = (Node*)malloc(sizeof(Node));
	list->data = 0;
	list->next = NULL;
	return list;
}

void TailInsert(Node* list, char data)
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

Node* FindSuffix(Node* Ha, Node* Hb)
{
	int k = 0;
	Node* L = NULL;
	Node* S = NULL;
	if (Ha->data > Hb->data)
	{
		k = Ha->data - Hb->data;
		L = Ha->next;
		S = Hb->next;
	}
	else
	{
		k = Hb->data - Ha->data;
		L = Hb->next;
		S = Ha->next;
	}
	for (k; k > 0; k--)
	{
		L = L->next;
	}
	while (L && S)
	{
		if (L->data == S->data)
			return L;
		else
		{
			L = L->next;
			S = S->next;
		}
	}
	return NULL;
}

int main()
{
	printf("Sintream_ouse\n");
	Node* Ha = InitList();
	Node* Hb = InitList();
	TailInsert(Ha, 'l');
	TailInsert(Ha, 'o');
	TailInsert(Ha, 'a');
	TailInsert(Ha, 'd');
	TailInsert(Ha, 'i');
	TailInsert(Ha, 'n');
	TailInsert(Ha, 'g');
	TailInsert(Hb, 'b');
	TailInsert(Hb, 'e');
	TailInsert(Hb, 'i');
	TailInsert(Hb, 'n');
	TailInsert(Hb, 'g');
	Node* p = FindSuffix(Ha, Hb);
	printf("%c ", p->data);
	return 0;
}
