#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

void Traverse(struct Node *ptr) //O(N)
{
    while (ptr != NULL)
    {
        printf("Element is: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int isEmpty(struct Node* head) {
    if(head == NULL)
        return 1;
    return 0;
}

int isFull(struct Node* head) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr == NULL)
        return 1;
    return 0;
}

struct Node* push(struct Node* top, int number)
{
    if(isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct Node* new = (struct Node*)malloc(sizeof(struct Node));
        new->data = number;
        new->next = top;
        top = new;
    }
    return top;
}

int pop(struct Node** top)
{
    if(!isEmpty(top))
    {
        struct Node* temp = *top;
        int value = (*top)->data;
        *top = (*top)->next;
        free(temp);
        return value;
    }
    printf("Stack is empty\n");
    return -1;
}

int main()
{
    struct Node* top = NULL;
    top = push(top, 15);
    top = push(top, 26);
    top = push(top, 11);
    top = push(top, 64);
    Traverse(top);
    int element = pop(&top);
    printf("Popped element is %d\n", element);
    Traverse(top);
    return 0;
}