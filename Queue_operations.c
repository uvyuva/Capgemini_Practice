#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 5
struct queue
{
    int items[QUEUE_SIZE];
    int front, rear;
};

typedef struct queue QUEUE;

int insert_rear(int item, QUEUE *q)
{
    if (q->rear == QUEUE_SIZE - 1)
    {
        printf("Queue Full");
        return 0;
    }
    (q->rear)++;
    q->items[q->rear] = item;
}

int delete_front(QUEUE *q)
{
    if (q->front > q->rear)
    {
        printf("Queue is empty");
        return 0;
    }
    printf("The element deleted is %d\n", q->items[q->front]);
    (q->front)++;
    if (q->front > q->rear)
    {
        q->front = 0;
        q->rear = -1;
    }
}

int display(QUEUE *q)
{
    int i;
    if (q->front > q->rear)
    {
        printf("Queue is empty");
        return 0;
    }
    printf("The queue contents are: \n");
    for (i = q->front; i <= q->rear; i++)
    {
        printf("%d \t", q->items[i]);
    }
}

int main()
{
    QUEUE q;
    q.front = 0;
    q.rear = -1;
    int input, item;
    while (1)
    {
        printf("1) Insertion\n ");
        printf("2) Deletion\n ");
        printf("3) Display\n ");
        printf("4) Exit\n ");
        printf("Enter your choice\n ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            insert_rear(item, &q);
            display(&q);
            break;
            
        case 2:
            delete_front(&q);
            display(&q);
            break;

        case 3:
            display(&q);
            break;
        
        case 4:
            exit(0);

        default:

            break;
        }
    }
}