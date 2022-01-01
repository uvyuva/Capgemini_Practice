#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node *NODE;

NODE insert_front(int item, NODE first)
{
    NODE newnode;
    newnode = (NODE)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Out of memory");
        exit(1);
    }
    newnode->info = item;
    newnode->link = first;
    return newnode;
}
int display(NODE first)
{
    NODE temp;
    if (first == NULL)
    {
        printf("List empty");
        return 0;
    }
    printf("Contents are: \n");
    temp = first;
    while (temp != NULL)
    {
        printf("%d \t", temp->info);
        temp = temp->link;
    }
}

int main()
{
    NODE first = NULL;
    int item, input;
    for (;;)
    {
        printf("1) Insertion\n ");
        printf("2) Display\n ");
        printf("3) Exit\n ");
        printf("Enter your choice\n ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            insert_front(item,first);
            break;

        case 2:
            display(first);
            break;
        
        case 3:
            exit(0);

        default:

            break;
        }
    }
}