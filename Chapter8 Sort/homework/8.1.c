#include <stdio.h>
#include <stdlib.h>

/*
Implement a simple selection sort (ascending order) on a singly linked list.
*For selection sort on a linked list, a common method is to traverse the linked
 list and find the minimum node in the remaining list at each position.
*Then swap the keys of the current node and the smallest node (swap the data fields),
 because changing pointers is cumbersome and unnecessary.
*/

typedef struct Node
{
	int key;
	struct Node* next;
} Node;

Node* CreateNode(int key)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->key = key;
	newNode->next = NULL;
	return newNode;
}

Node* BuildList(int a[], int n)
{
	Node* head = CreateNode(0);	// Dummy head node
	Node* tail = head;
	for (int i = 0; i < n; ++i)
	{
		tail->next = CreateNode(a[i]);
		tail = tail->next;
	}
	return head;
}

void PrintList(Node* head)
{
	Node* current = head->next; // Skip dummy head
	while (current)
	{
		printf("%d ", current->key);
		current = current->next;
	}
	printf("\n");
}

void SelectionSortLinkedList(Node* head)
{
	if (!head || !head->next)
		return;
	Node* p = head->next; // Start from the first real node
	while (p)
	{
		Node* min = p;
		Node* q = p->next;
		while (q)
		{
			if (q->key < min->key)
				min = q;
			q = q->next;
		}
		if (min != p)
		{
			int tmp = p->key;
			p->key = min->key;
			min->key = tmp;
		}
		p = p->next;
	}
}

int main()
{
	int a[] = { 6, 2, 7, 5, 1 };
	int n = sizeof(a) / sizeof(a[0]);
	Node* head = BuildList(a, n);
	printf("Original list:\n");
	PrintList(head);
	SelectionSortLinkedList(head);
	printf("Sorted list:\n");
	PrintList(head);
	return 0;
}