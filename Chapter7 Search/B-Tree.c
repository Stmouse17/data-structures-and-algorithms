#define _CRT_SECURE_NO_SECURE
#include <stdio.h>
#include <stdlib.h>
#define T 3   //Minimum degree (each node has at least T-1 keys and at most 2T-1 keys)

typedef struct BTreeNode
{
    int keys[2 * T - 1];                 // keywords
    struct BTreeNode* children[2 * T];   // child node
    int n;                               // number of keywords
    int isLeaf;                          
} BTreeNode;

BTreeNode* CreateNode(int isLeaf)   //*
{
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->isLeaf = isLeaf;
    node->n = 0;
    for (int i = 0; i < 2 * T; i++) 
        node->children[i] = NULL;
    return node;
}

BTreeNode* Search(BTreeNode* x, int key)    //*
{
    int i = 0;
    while (i < x->n && key > x->keys[i])
        i++;
    if (i < x->n && key == x->keys[i])
        return x;
    if (x->isLeaf)
        return NULL;
    return Search(x->children[i], key);
}

void SplitChild(BTreeNode* x, int i)    //*
{
    BTreeNode* y = x->children[i];          //Node to be split
    BTreeNode* z = CreateNode(y->isLeaf);   //New node
    z->n = T - 1;
    //Copy the latter half of y to z
    for (int j = 0; j < T - 1; j++)
        z->keys[j] = y->keys[j + T];
    if (!y->isLeaf)
    {
        for (int j = 0; j < T; j++)
            z->children[j] = y->children[j + T];
    }
    y->n = T - 1;
    //Insert the new child into x
    for (int j = x->n; j >= i + 1; j--)
        x->children[j + 1] = x->children[j];
    x->children[i + 1] = z;
    //Move the middle key up to the parent node
    for (int j = x->n - 1; j >= i; j--)
        x->keys[j + 1] = x->keys[j];
    x->keys[i] = y->keys[T - 1];
    x->n++;
}

void InsertNonFull(BTreeNode* x, int key)   //Inserting a non-full node
{
    int i = x->n - 1;
    if (x->isLeaf)
    {
        //Insert directly into the leaves
        while (i >= 0 && key < x->keys[i]) 
        {
            x->keys[i + 1] = x->keys[i];
            i--;
        }
        x->keys[i + 1] = key;
        x->n++;
    }
    else 
    {
        while (i >= 0 && key < x->keys[i])
            i--;
        i++;
        if (x->children[i]->n == 2 * T - 1)
        {
            SplitChild(x, i);
            if (key > x->keys[i]) i++;
        }
        InsertNonFull(x->children[i], key);
    }
}

void Insert(BTreeNode** root, int key)  //Insert main function
{
    if (*root == NULL)
        *root = CreateNode(1);
    if ((*root)->n == 2 * T - 1)
    {
        BTreeNode* s = CreateNode(0);
        s->children[0] = *root;
        SplitChild(s, 0);
        *root = s;
    }
    InsertNonFull(*root, key);
}

//Delete related utility functions

void RemoveFromNode(BTreeNode* node, int idx)   //Remove keys[idx] from the node
{
    for (int i = idx + 1; i < node->n; i++)
        node->keys[i - 1] = node->keys[i];
    node->n--;
}


int GetPredecessor(BTreeNode* node, int idx)    //Get the maximum key from the predecessor node
{
    BTreeNode* cur = node->children[idx];
    while (!cur->isLeaf) cur = cur->children[cur->n];
    return cur->keys[cur->n - 1];
}

int GetSuccessor(BTreeNode* node, int idx)  //Get the minimum key from the successor node
{
    BTreeNode* cur = node->children[idx + 1];
    while (!cur->isLeaf) cur = cur->children[0];
    return cur->keys[0];
}

void BorrowFromPrev(BTreeNode* node, int idx)   //Complete: Borrow from the left brother
{
    BTreeNode* child = node->children[idx];
    BTreeNode* sibling = node->children[idx - 1];
    //child node right shift
    for (int i = child->n - 1; i >= 0; i--)
        child->keys[i + 1] = child->keys[i];
    if (!child->isLeaf)
    {
        for (int i = child->n; i >= 0; i--)
            child->children[i + 1] = child->children[i];
    }
    child->keys[0] = node->keys[idx - 1];
    if (!child->isLeaf) 
        child->children[0] = sibling->children[sibling->n];
    node->keys[idx - 1] = sibling->keys[sibling->n - 1];
    child->n++;
    sibling->n--;
}


void BorrowFromNext(BTreeNode* node, int idx)   //Complete: Borrow from the brother on the right 
{
    BTreeNode* child = node->children[idx];
    BTreeNode* sibling = node->children[idx + 1];
    child->keys[child->n] = node->keys[idx];
    if (!child->isLeaf) 
        child->children[child->n + 1] = sibling->children[0];
    node->keys[idx] = sibling->keys[0];
    for (int i = 1; i < sibling->n; i++)
        sibling->keys[i - 1] = sibling->keys[i];
    if (!sibling->isLeaf)
    {
        for (int i = 1; i <= sibling->n; i++)
            sibling->children[i - 1] = sibling->children[i];
    }
    child->n++;
    sibling->n--;
}


void Merge(BTreeNode* node, int idx)    //Merge children[idx] and children[idx+1] 
{
    BTreeNode* child = node->children[idx];
    BTreeNode* sibling = node->children[idx + 1];
    child->keys[T - 1] = node->keys[idx];
    for (int i = 0; i < sibling->n; i++)
        child->keys[i + T] = sibling->keys[i];
    if (!child->isLeaf) 
    {
        for (int i = 0; i <= sibling->n; i++)
            child->children[i + T] = sibling->children[i];
    }
    child->n += sibling->n + 1;
    for (int i = idx + 1; i < node->n; i++)
    {
        node->keys[i - 1] = node->keys[i];
        node->children[i] = node->children[i + 1];
    }
    node->n--;
    free(sibling);
}

void DeleteKey(BTreeNode* node, int key);   //Main delete function


void Fill(BTreeNode* node, int idx) //Ensure that child[idx] has at least one T key.
{
    if (idx > 0 && node->children[idx - 1]->n >= T)
        BorrowFromPrev(node, idx);
    else if (idx < node->n && node->children[idx + 1]->n >= T)
        BorrowFromNext(node, idx);
    else 
    {
        if (idx < node->n)
            Merge(node, idx);
        else
            Merge(node, idx - 1);
    }
}


void DeleteFromChild(BTreeNode* node, int idx, int key) //Delete key in child node 
{
    BTreeNode* child = node->children[idx];
    if (child->n < T) {
        Fill(node, idx);
        if (idx > node->n) idx--;
        child = node->children[idx];
    }
    DeleteKey(child, key);
}



void DeleteKey(BTreeNode* node, int key)    //Deleting main logic
{
    int idx = 0;
    while (idx < node->n && key > node->keys[idx])
        idx++;
    //Case 1: The key is in this node
    if (idx < node->n && key == node->keys[idx])
    {
        //Case 1.1: In the leaves
        if (node->isLeaf)
        {
            RemoveFromNode(node, idx);
            return;
        }
        //Case 1.2: In internal nodes
        int k = node->keys[idx];
        if (node->children[idx]->n >= T)
        {
            int pred = GetPredecessor(node, idx);
            node->keys[idx] = pred;
            DeleteKey(node->children[idx], pred);
        }
        else if (node->children[idx + 1]->n >= T) 
        {
            int succ = GetSuccessor(node, idx);
            node->keys[idx] = succ;
            DeleteKey(node->children[idx + 1], succ);
        }
        else
        {
            Merge(node, idx);
            DeleteKey(node->children[idx], k);
        }
    }
    //Case 2: The key is not in this node
    else
    {
        if (node->isLeaf) return;
        DeleteFromChild(node, idx, key);
    }
}


void Delete(BTreeNode** root, int key)  //Delete the interface (allows the root node to be shrunk)
{
    if (*root == NULL) 
        return;
    DeleteKey(*root, key);
    if ((*root)->n == 0 && !(*root)->isLeaf)
    {
        BTreeNode* old = *root;
        *root = (*root)->children[0];
        free(old);
    }
}


void PrintTree(BTreeNode* node, int level)  //Print the tree structure (for debugging purposes)
{
    if (node == NULL)
        return;
    printf("Level %d  Keys: ", level);
    for (int i = 0; i < node->n; i++)
        printf("%d ", node->keys[i]);
    printf("\n");
    if (!node->isLeaf) 
    {
        for (int i = 0; i <= node->n; i++)
            PrintTree(node->children[i], level + 1);
    }
}

int main()  //Test code
{
    BTreeNode* root = NULL;
    int arr[] = { 10, 20, 5, 6, 12, 30, 7, 17 };
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) 
        Insert(&root, arr[i]);
    printf("Initial B-tree structure£º\n");
    PrintTree(root, 0);
    Delete(&root, 6);
    printf("\nAfter deleting 6£º\n");
    PrintTree(root, 0);
    Delete(&root, 7);
    printf("\nAfter deleting 7£º\n");
    PrintTree(root, 0);
    Delete(&root, 12);
    printf("\nAfter deleting 12£º\n");
    PrintTree(root, 0);
    return 0;
}

//If I'm not mistaken, you will see
/*
    Initial B-tree structure£º
    Level 0  Keys: 10
    Level 1  Keys: 5 6 7
    Level 1  Keys: 12 17 20 30

    After deleting 6£º
    Level 0  Keys: 10
    Level 1  Keys: 5 7
    Level 1  Keys: 12 17 20 30

    After deleting 7£º
    Level 0  Keys: 12
    Level 1  Keys: 5 10
    Level 1  Keys: 17 20 30

    After deleting 12£º
    Level 0  Keys: 17
    Level 1  Keys: 5 10
    Level 1  Keys: 20 30
*/
                                                