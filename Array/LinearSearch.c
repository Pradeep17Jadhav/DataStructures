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

int LinearSearch(int arr[], int size, int elementToFind)
{
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == elementToFind)
            return i;
    }
    return -1;
}

int main()
{
    int arr[50] = {4, 82, 5, 66, 41, 87, 12, 16, 13};
    int capacity = sizeof(arr) / sizeof(int);
    int size = 9;
    int elementToFind = 13;
    int index = 1;
    Display(arr, size);

    int ret = LinearSearch(arr, size, elementToFind);
    if(ret != -1)
    {
        printf("Found %d at index: %d", elementToFind, ret);
    }
    else
    {
        printf("Couldnt find the element %d", elementToFind);
    }
    return 0;
}