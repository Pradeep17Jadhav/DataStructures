#include<stdio.h>
#include<stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

void Traverse(struct Node *ptr) //O(N)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}

//Case 1 - Delete first node
struct Node* DeleteFirstNode(struct Node* head)
{
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

//Case 2 - Delete in between
struct Node* DeleteAtIndex(struct Node* head, int index)
{
    struct Node* ptr = head;
    struct Node* temp;
    int indexCounter = 0;
    while(indexCounter < index - 1)
    {
        ptr = ptr->next;
        indexCounter++;
    }

    temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    return head;
}

//Case 3 - Delete last node
struct Node* DeleteLastNode(struct Node* head)
{
    struct Node* prev = head;
    struct Node* curr = head->next;
    while(curr->next != NULL)
    {
        prev = prev->next;
        curr = curr->next;
    }
    prev->next = NULL;
    free(curr);
    return head;
}

//Case 4 = Delete Node With Value
struct Node* DeleteNodeWithValue(struct Node* head, int value)
{
    struct Node* prev = head;
    struct Node* curr = head->next;
    while(curr->value != value && curr->next != NULL)
    {
        prev = prev->next;
        curr = curr->next;
    }

    if(curr->value == value)
    {
        prev->next = curr->next;
        free(curr);
    }
    return head;
}

int main()
{
    struct Node* head = (struct Node *)malloc(sizeof(struct Node));
    struct Node* first = (struct Node *)malloc(sizeof(struct Node));
    struct Node* second = (struct Node *)malloc(sizeof(struct Node));
    struct Node* third = (struct Node *)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node *)malloc(sizeof(struct Node));

    //head node
    head->value = 11;
    head->next = first;

    //first node
    first->value = 22;
    first->next = second;

    //second node
    second->value = 33;
    second->next = third;

    //third node
    third->value = 44;
    third->next = fourth;

    //fourth node
    fourth->value = 55;
    fourth->next = NULL;

    Traverse(head);
    // head = DeleteFirstNode(head);
    // head = DeleteLastNode(head);
    // head = DeleteAtIndex(head, 3);
    head = DeleteNodeWithValue(head, 44);

    Traverse(head);

    return 0;
}