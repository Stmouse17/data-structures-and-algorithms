#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define H 13

//Hash table (chaining) insertion/deletion of key K

typedef struct Node
{
	int key;
	struct Node* next;
} Node;

typedef struct HashTable
{
	int size;	//size of each bucket
	Node** table;
} HashTable;

HashTable* create_table(int size)
{
	HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
	ht->size = size;
	ht->table = (Node**)malloc(sizeof(Node*) * size);
	for (int i = 0; i < size; i++)
		ht->table[i] = NULL;
	return ht;
}

int Hash(int key, int size)
{
	return key % size;
}

void Insert(HashTable* ht, int key)
{
	int index = Hash(key, ht->size);
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = key;
	newNode->next = ht->table[index];
	ht->table[index] = newNode;	//Head insertion
}

void Delete(HashTable* ht, int key)
{
	int index = Hash(key, ht->size);
	Node* curr = ht->table[index];
	Node* prev = NULL;
	while (curr != NULL && curr->key != key)
	{
		prev = curr;
		curr = curr->next;
	}
	if (curr == NULL) return; //Key not found
	if (prev == NULL)
		ht->table[index] = curr->next; //Delete head
	else
		prev->next = curr->next; //Bypass the node to delete
	free(curr);
}

void PrintTable(HashTable* ht)
{
	for (int i = 0; i < ht->size; i++)
	{
		printf("Bucket %d: ", i);
		Node* curr = ht->table[i];
		while (curr != NULL)
		{
			printf("%d -> ", curr->key);
			curr = curr->next;
		}
		printf("NULL\n");
	}
}

int main()
{
	HashTable* ht = create_table(H);
	Insert(ht, 10);
	Insert(ht, 23);
	Insert(ht, 36);
	Insert(ht, 49);
	PrintTable(ht);
	printf("\nDeleting key 23...\n\n");
	Delete(ht, 23);
	PrintTable(ht);
	return 0;
}