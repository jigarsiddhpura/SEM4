#include <stdio.h>
#include <stdlib.h>
int max = 10;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(){
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));       
    temp -> next = NULL;
    return temp;
}

struct Node *front = NULL , *rear = NULL ;

void enque(int val)
{
    struct Node *new;
    new = createNode();
    new -> data = val;
    if (front == NULL)
    {
        front = rear = new;
        front->next = rear->next = NULL;

    }
    else
    {
        rear->next = new;
        rear = new;
        new -> next = NULL;
    }
}

void deque()
{
    
    struct Node *temp;
    if (front == NULL)
    {
        printf("Queue underflow\n");
    }
    else
    {
        temp = front;
        front = front -> next;
        free(temp);
    }
}

void display()
{
    struct Node *temp;
    temp = front;
    if (front == NULL)
    {
        printf("Queue not present\n");
    }
    else
    {
    printf("Queue:\n");
    while(temp !=NULL){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    }
}


void main()
{
    int op;
    while (op != 4)
    {
        printf("\nEnter 1 to insert value , 2 to display , 3 to search  , 4 to exit :  ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter the value");
            int x;
            scanf("%d", &x);
            enque(x);
            display();
            break;

        case 2:
            display();
            break;

        case 3:
            printf("Enter the value");
            int val;
            scanf("%d", &val);
            // search(val);
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Enter a valid input");
            break;
        }
    }
}