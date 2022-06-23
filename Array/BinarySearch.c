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

int BinarySearch(int arr[], int size, int elementToFind)
{
    int low = 0;
    int high = size - 1;
    int mid;
    while (low <= high)
    {
        mid = (high + low) / 2;

        if (arr[mid] == elementToFind)
            return mid;
        
        if(elementToFind < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main()
{
    int arr[50] = {4, 5, 12, 13, 16, 41, 66, 82, 87, 104};
    int capacity = sizeof(arr) / sizeof(int);
    int size = 10;
    int elementToFind = 41;
    int index = 1;
    Display(arr, size);

    int ret = BinarySearch(arr, size, elementToFind);
    if (ret != -1)
    {
        printf("Found %d at index: %d", elementToFind, ret);
    }
    else
    {
        printf("Couldnt find the element %d", elementToFind);
    }
    return 0;
}