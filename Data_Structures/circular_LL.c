#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
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
    temp->next = head;
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
        do
        {
            printf(" %d ", temp->data);
            temp = temp->next;
        } while (temp != head);
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
        new->next = head;
    }
    else
    {
        while (temp -> next != head)
        {
            temp = temp->next;
        } 
        temp->next = new;
        new->next = head;
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
        new->next = head;
    }
    else
    {
        while (temp -> next!= head)
        {
            temp = temp->next;
        } 
        temp->next = new;
        new->next = head;
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
        head = temp = new;
        new->next = head;
    }
    else
    {
        do
        {
            if (temp->data == val)
            {
                new->next = temp->next;
                temp->next = new;
                break;
            }
            else
            {
                temp = temp->next;
            }
        } while (temp != head);
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
        do
        {
            if (temp->data == val)
            {
                printf("%d found at %d", val, temp->next);
                k = 1;
            }
            temp = temp->next;
        } while (temp->next != head);
        if (!k)
        {
            printf("%d not found", val);
        }
    }
}

void delete_ll()
{
    struct Node *temp, *new, *prev;
    int val;
    printf("Enter the value to delete: ");
    scanf("%d", &val);
    temp = head;
    prev = NULL;
    do
    {
        if (temp->data == val)
        {
            if (prev == NULL)
            {   
                head = temp -> next;
                prev->next = temp->next;
                temp->next = NULL;
                free(temp);
            }
            else
            {
                prev->next = temp->next;
                temp->next = NULL;
                free(temp);
            }
            printf("%d deleted \n",val);
            break;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    } while (temp->next != head);
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
        }
        else if (ins == 2)
        {
            insertend();
        }
        else
        {
            insertafter();
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