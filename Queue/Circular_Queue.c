#include<stdio.h>
#include<stdlib.h>

struct CircularQueue{
    int size;
    int f;
    int r;
    int* arr;
};

int isFull(struct CircularQueue *q)
{
    if((q->r+1)%q->size == q->f)
        return 1;
    return 0;
}

int isEmpty(struct CircularQueue* q)
{
    if(q->f == q->r)
        return 1;
    return 0;
}

void enqueue(struct CircularQueue* q, int num)
{
    if(isFull(q))
    {
        printf("Queue is full\n");
        return;
    }

    q->r = (q->r+1)%q->size;
    q->arr[q->r] = num;
    printf("Enqueued Element: %d\n", num);
}

int dequeue(struct CircularQueue * q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    q->f = (q->f+1)%q->size;
    int ret = q->arr[q->f];
    printf("Dequeued Element: %d\n", ret);
    return ret;
}

int main()
{
    struct CircularQueue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 13);
    enqueue(&q, 57);
    enqueue(&q, 63);

    if(isEmpty(&q))
        printf("Queue Empty\n");

    if(isFull(&q))
        printf("Queue Full At End\n");

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    if(isEmpty(&q))
        printf("Queue Empty\n");

    if(isFull(&q))
        printf("Queue Full At End\n");

    return 0;
}