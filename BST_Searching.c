#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};

typedef struct node *NODE;

NODE insert(int item, NODE root)
{
    NODE temp, cur, prev;
    temp = (NODE)malloc(sizeof(struct node));
    temp->info = item;
    temp->llink = NULL;
    temp->rlink = NULL;

    if (root == NULL)
        return temp;

    prev = NULL;
    cur = root;

    while (cur != NULL)
    {
        prev = cur;
        cur = (item < cur->info) ? cur->llink : cur->rlink;
    }

    if (item < prev->info)
    {
        prev->llink = temp;
    }
    else
    {
        prev->rlink = temp;
    }

    return root;
}

NODE search(int item, NODE root)
{
    if (root == NULL || item == root->info)
        return root;

    if (item < root->info)
        return (search(item, root->llink));
    return (search(item, root->rlink));
}

int main()
{
    NODE root = NULL, temp=NULL;
    int choice, item, flag;
    for (;;)
    {
        printf("1) Insert rear\n ");
        printf("2) Search\n ");
        printf("3) Exit\n ");
        printf("Enter your choice\n");
        scanf("%d \n", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            root=insert(item,root);
            break;

        case 2:
            temp=NULL;
            if(temp==NULL)
            {
                printf("Tree is empty\n");
            }
            else
            {
                printf("Enter the item to be searched:\n");
                scanf("%d",&item);
                temp=search(item,root);
                if(temp==NULL)
                {
                    printf("Search Unsuccessfull");
                }
                else
                {
                    printf("Search Successfull");
                }
            }
            break;
           
        case 3:
            exit(0);
        
        default: printf("Inavild Input\n");
        }
    }
}