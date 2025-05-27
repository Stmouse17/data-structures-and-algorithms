#include <stdio.h>
#define FALSE 0
#define TRUE 1

void Quicksort(int* arr, int start, int end)
{
    if (start >= end)
        return;
    int left = start;
    int right = end;
    int pivot = arr[left];
    while (left < right)
    {
        while (arr[right] > pivot && left < right)
        {
            right--;
        }
        if (left < right)
        {
            arr[left] = arr[right];
            left++;
        }
        while (arr[left] < pivot && left < right)
        {
            left++;
        }
        if (left < right)
        {
            arr[right] = arr[left];
            right--;
        }
        arr[left] = pivot;
        Quicksort(arr, start, left - 1);
        Quicksort(arr, right + 1, end);
    }
}

int MainElem(int arr[], int n)
{
    int count = 1;
    int key = arr[0];
    int i = 0;
    int j = 0;
    for (i = 1; i < n; i++)
    {
        if (arr[i] == key)
            count++;
        else
        {
            if (count)
                count--;
            else
            {
                key = arr[i];
                count = 1;
            }
        }
    }
    if (count)
        for (i = 0; i < n; i++)
        {
            if (arr[i] == key)
                j++;
        }
    if (count > n / 2)
    {
        printf("%d\n", key);
        return TRUE;
    }
    else
        return FALSE;
}

int main() 
{
    printf("Sintream_ouse\n");
    int arr1[] = { 0,5,5,3,5,1,5,7 };
    int arr2[] = { 0,5,5,3,5,1,5,5 };
    int len = sizeof(arr1) / sizeof(arr1[0]);
    Quicksort(arr1, 0, len - 1);
    for (int j = 0; j < len; j++) {
        printf("%d ", arr1[j]);
    }
    int flag = arr1[len / 2];
    int count = 1;
    for (int i = (len / 2) - 1; i > 0; i--) {
        if (arr1[i] == arr1[len / 2])
        {
            count++;
        }
    }
    for (int i = (len / 2) + 1; i < len; i++) {
        if (arr1[i] == arr1[len / 2])
        {
            count++;
        }
    }
    if (count > (len / 2))
    {
        printf("\n");
        printf("%d\n", arr1[len / 2]);
    }
    else
    {
        printf("\n");
        printf("%d\n", -1);
    }
     return 0;
}

