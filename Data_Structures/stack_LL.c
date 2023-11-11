#include <stdio.h>
#include<stdlib.h>
#define SIZE 30

struct Node{
    int data;
    struct Node *next;
};

struct Node *createNode(){
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> next = NULL;
    return temp;
}

struct Node *top = NULL;

void push()
{
    int n, val;
    struct Node *new;
    new = createNode();
    printf("Enter the value: ");
    scanf("%d", &val);
    new -> data = val;

    if (top == NULL)
    {
        new->next=NULL;
        top=new;
    }
    else
    {
        new->next=top;
        top=new;
    }
}

void pop()
{
    if (top == NULL)
    {
        printf("STACK UNDERFLOW");
    }
    else
    {
        struct Node *ptr;
        ptr=top;
        top=top->next;
        free(ptr);
        printf("%d deleted", ptr->data);
    }
}


void main()
{
    int op, choice;

    while (choice != 4)
    {
        printf("\nEnter 1 to push , 2 to pop , 3 to exit : ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            printf("Exit done");
            exit(0);
        }
        default:
            printf("Enter valid number");
            break;
        };
    }
}