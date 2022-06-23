#include <stdio.h>
#include <stdlib.h>

void Display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int InsertAtIndex(int arr[], int size, int index, int capacity, int value)
{
    if(index > capacity - 1 || index > size)
        return -1;

    for (int i = size; i >= index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = value;
    return 1;
}

int main()
{
    int arr[50] = {4, 82, 5, 66, 41, 87, 12, 16, 13};
    int capacity = sizeof(arr) / sizeof(int);
    int size = 9;
    int element = 14;
    int index = 1;
    Display(arr, size);

    int ret = InsertAtIndex(arr, size, index, capacity, element);
    if(ret == 1)
    {
        size++;
        Display(arr, size);
    }
    return 0;
}