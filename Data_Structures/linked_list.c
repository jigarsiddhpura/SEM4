#include <stdio.h>
// #include<conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    // since the pointer next is pointing to the node , its data type is also node
};
struct Node *head; // declaring head global

struct Node *createnode()
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->next = NULL;
    return temp;
}

void createlist(int n)
{
    struct Node *temp, *new;
    head = temp = NULL;
    while (n > 0)
    {
        new = createnode();
        printf("Enter data: ");
        scanf("%d", &new->data);
        if (head == NULL)
        {
            head = new;
            temp = new;
        }
        else
        {
            temp->next = new;
            temp = new;
        }
        n--;
    }
}

void display()
{
    struct Node *temp;
    temp = head;
    if (temp == NULL)
    {
        printf("Linked list not present");
    }
    else
    {
        while (temp != NULL)
        {
            printf(" %d ", temp->data);
            temp = temp->next;
        }
    }
}

void insertbeg()
{
    struct Node *temp, *new;
    new = createnode();
    printf("Enter the value u wanna add at beginning: ");
    scanf("%d", &new->data);
    temp = head;
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        new->next = temp;
        head = new;
    }
}

void insertend()
{
    struct Node *temp, *new;
    new = createnode();
    printf("Enter the value u wanna add at end: ");
    scanf("%d", &new->data);
    temp = head;
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = NULL;
    }
}

void insertafter()
{
    struct Node *temp, *new;
    int val;
    new = createnode();
    printf("Enter the data u wanna add in the node: ");
    scanf("%d", &new->data);
    printf("Enter the value of data after which u wanna insert: ");
    scanf("%d", &val);
    temp = head;
    if (head == NULL)
    {
        head = new;
        temp = new;
    }
    else
    {
        while (temp->next != NULL)
        {

            if (temp->data == val)
            {
                new->next = temp->next;
                temp->next = new;
                // break;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
}

void search()
{
    struct Node *temp, *new;
    int val, k = 0;
    printf("Enter the value u wanna search: ");
    scanf("%d", &val);
    temp = head;
    if (head == NULL)
    {
        printf("Linked List not present");
    }
    else
    {
        while (temp->next != NULL)
        {
            if (temp->data == val)
            {
                printf("%d found at %d", val, temp->next);
                k = 1;
            }
            temp = temp->next;
        }
        if (!k)
        {
            printf("%d not found", val);
        }
    }
}

void delete_ll()
{
    struct Node *temp, *prev;
    int val;
    printf("Enter the value to delete: ");
    scanf("%d", &val);
    temp = head;
    prev = NULL;
    while (temp->next != NULL)
    {
        if (temp->data == val)
        {
            // printf("inside if");
            if (prev == NULL)
            {
                head = temp->next;
                temp->next = NULL;
                free(temp);
            }
            else
            {
                prev->next = temp->next;
                temp->next = NULL;
                free(temp);
            }
            break;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    printf("%d deleted \n",val);
}

void main()
{
    int n, ins, op;
    printf("Enter no. of nodes - ");
    scanf("%d", &n);
    createlist(n);
    printf("Linked list:\n");
    display();
    printf("\nEnter 1 to add a node , 2 to search & 3 to delete: ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        printf("\nEnter 1 to add a node at beginning , 2 for end , else 0: ");
        scanf("%d", &ins);
        if (ins == 1)
        {
            insertbeg();
            // display();
            // break;
        }
        else if (ins == 2)
        {
            insertend();
            // display();
            // break;
        }
        else
        {
            insertafter();
            // display();
            // break;
        }
        display();
        break;

    case 2:
        search();
        break;

    case 3:
        delete_ll();
        display();
        break;
    }
}