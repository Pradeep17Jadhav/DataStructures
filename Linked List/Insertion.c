#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Traverse(struct Node *ptr) //O(N)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

//Case 1 - insert at beginning
struct Node *InsertAtBeginning(struct Node *head, int data) //O(1)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

//Case 2 - insert in between
struct Node *InsertAtIndex(struct Node *head, int index, int data) //O(N)
{
    struct Node *p = head;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    int i = 0;
    while (i < index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->next = p->next;
    p->next = ptr;

    return head;
}

//Case 3 - insert at end
struct Node *InsertAtEnd(struct Node *head, int data) //O(N)
{
    struct Node *p = head;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;
    return head;
}

//Case 4 - insert after node
struct Node * InsertAfterNode(struct Node *head, struct Node *prevNode, int data) //O(1), not O(N)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
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
    
    // head = InsertAtBeginning(head, 97);
    // head = InsertAtIndex(head, 5, 47);
    // head = InsertAtEnd(head, 13);
    head = InsertAfterNode(head, second, 17);

    Traverse(head);
    return 0;
}