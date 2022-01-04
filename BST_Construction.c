#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};

typedef struct node *NODE;

NODE innsert(int item, NODE root)
{
    NODE temp, cur, prev;
    temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Out of memory");
        exit(1);
    }
    temp->info = item;
    temp->llink = NULL;
    temp->rlink = NULL;
    if (root == NULL)
    {
        return temp;
    }
    prev = NULL;
    cur = root;
    while (cur != NULL)
    {
        prev = cur;
        cur = (item < cur->info) ? cur->llink : cur->rlink;
    }
    if (item < prev->info)
        prev->llink = temp;
    else
        prev->rlink = temp;
    return root;
}

void inorder(NODE root)
{
    if (root != NULL)
    {
        inorder(root->llink);
        printf("%d\t", root->info);
        inorder(root->rlink);
    }
}

void postorder(NODE root)
{
    if (root != NULL)
    {
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d\t", root->info);
    }
}

void preorder(NODE root)
{

    if (root != NULL)
    {
        printf("%d\t", root->info);
        preorder(root->llink);
        preorder(root->rlink);
    }
}

int main()
{
    NODE root = NULL;
    int choice, item, flag;
    for (;;)
    {
        printf("1) Insert\n ");
        printf("2) Preorder\n ");
        printf("3) Inorder\n ");
        printf("4) Postorder\n");
        printf("5) Exit\n");
        printf("Enter your choice\n");
        scanf("%d \n", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            root = insert(item, root);
            break;

        case 2:
            if (root == NULL)
            {
                printf("Tree is Empty");
            }
            else
            {
                printf("Preorder traversel: \n");
                preorder(root);
                printf("\n");
            }
            break;

        case 3:
            if (root == NULL)
            {
                printf("Tree is Empty");
            }
            else
            {
                printf("Inorder traversel: \n");
                inorder(root);
                printf("\n");
            }
            break;

        case 4:
            if (root == NULL)
            {
                printf("Tree is Empty");
            }
            else
            {
                printf("Postorder traversel: \n");
                postorder(root);
                printf("\n");
            }
            break;
        case 5:
            exit(0);
        
        default: 
            printf("Invalid Input");
        }
    }
}