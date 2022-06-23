#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Traverse(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    //head node
    head->data = 11;
    head->next = first;

    //first node
    first->data = 22;
    first->next = second;

    //second node
    second->data = 33;
    second->next = third;

    //third node
    third->data = 44;
    third->next = fourth;

    //fourth node
    fourth->data = 55;
    fourth->next = NULL;

    Traverse(head);
    return 0;
}