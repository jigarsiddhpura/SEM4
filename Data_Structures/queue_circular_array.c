#include <stdio.h>
#include <stdlib.h>
int max = 10, queue[30], rear = -1, front = -1;

void enque(int val)
{
    if (front == -1)
    {
        front = rear = 0;
        queue[rear] = val;
    }
    else if ((rear + 1) % max == front)
    {
        printf("Queue is full");
    }
    else
    {
        rear = (rear + 1) % max;
        queue[rear] = val;
    }
}

void deque()
{
    if (front == -1)
    {
        printf("Queue underflow");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % max;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue not present");
    }
    else
    {
        for (int i = front; i <= rear; i++ )
        {
            printf("%d ", queue[i]);
        }
    }
}

void search(int val)
{
    if (front == -1)
    {
        printf("Queue not present");
    }
    else
    {
        int ctr = 0;
        for (int i = front; i <= rear; i++)
        {
            if (val == queue[i])
            {
                printf("Value at index %d ", ctr);
            }
            ctr++;
        }
    }
}

void main()
{
    int k = -1;
    while (k == -1)
    {
        int op;
        printf("\nEnter 1 to insert value , 2 to display , 3 to search , 4 to delete , 5 to exit :  ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:;
            printf("Enter the value");
            int x;
            scanf("%d", &x);
            enque(x);
            display();
            break;

        case 2:;
            display();
            break;

        case 3:;
            printf("Enter the value");
            int val;
            scanf("%d", &val);
            search(val);
            break;

        case 4:;
            deque();
            display();
            break;

        case 5:;
            k = 0;
            break;

        default:;
            printf("Enter a valid input");
            break;
        }
    }
}