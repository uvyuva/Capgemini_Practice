#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

struct queue
{
    int f;
    int r;
    int item[QUEUE_SIZE];
    int count;
};

typedef struct queue QUEUE;

int insert_rear(int item, QUEUE *q)
{
    if (q->count == QUEUE_SIZE)
    {
        printf("Queue Full");
        return 0;
    }
    q->r = (q->r + 1) % QUEUE_SIZE;
    q->item[q->r] = item;
    (q->count)++;
}

int insert_front(int item, QUEUE *q)
{
    if(q->f==0 && q->r==-1)
    {
        q->item[++(q->r)]=item;
    }
    else if(q->f!=0)
    {
        q->item[--(q->f)]=item;
    }
    else
    {
        printf("Insertion at front not possible");
    }
}

int delete_rear(QUEUE *q)
{
    if(q->f >q->r)
    {
        printf("Queue is empty, deletion not possible");
        return 0;
    }
    printf("The deleted element is %d\n",q->item[q->r]);
    (q->r)--;
    if(q->f > q->r)
    {
        q->f=0;
        q->r=-1;
    }
}

int delete_front(QUEUE *q)
{
    if (q->count == 0)
    {
        printf("Queue empty");
        return 0;
    }
    q->f = (q->f + 1) % QUEUE_SIZE;
    (q->count)--;
}

int display(QUEUE *q)
{
    int i, j;
    if (q->count == 0)
    {
        printf("Queue Empty");
        return 0;
    }
    printf("Contents of Queue: \n");
    i = q->f;
    for (j = 1; j <= q->count; j++)
    {
        printf("%d \t", q->item[i]);
        i = (i + 1) % QUEUE_SIZE;
    }
}

int main()
{
    int input, item;
    QUEUE q;
    q.f = 0;
    q.r = -1;
    q.count = 0;
    for (;;)
    {
        printf("1) Insert rear\n ");
        printf("2) Delete front\n ");
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
