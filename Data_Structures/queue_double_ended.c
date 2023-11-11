// implementation using circular array

#include <stdio.h>
#include <stdlib.h>
int max = 10, queue[30], rear = -1, front = -1;

void insertRear(int val)
{
    if (front == -1)
    {
        front = rear = 0;
        queue[rear] = val;
    }
    else if ((rear + 1) % max == front)
    {
        printf("Queue is full\n");
    }
    else
    {
        rear = (rear + 1) % max;
        queue[rear] = val;
    }
}

void swap(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void insertFront(int val)
{
    int temp;
    if ((rear + 1) % max == front)
    {
        printf("Queue is full\n");
    }
    else if (front == -1)
    {
        front = rear = 0;
        queue[front] = val;
    }
    else if(front== rear == 0)
    {   
        // bug in this case
        front = max-1;
        queue[front] = val;
    }
    else{
        // front = (front - 1)  ;
        // queue[front] = val;

        temp = queue[front];
        queue[front] = val;
        for(int i=front+1;i<=rear;i++){
            swap(temp , queue[i]);
        }
        queue[rear+1] = temp;
    }

}

void delFront()
{
    if (front == -1)
    {
        printf("Queue underflow\n");
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

void delRear()
{
    if (front == -1)
    {
        printf("Queue underflow\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        rear = (rear - 1) % max;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue not present\n");
    }
    else
    {
        for (int i = front; i <= rear; i++ )
        {
            printf("%d(%d) ", queue[i], i);
        }
    }
}

void search(int val)
{
    if (front == -1)
    {
        printf("Queue not present\n");
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
        int op,x;
        printf("\nEnter 1 to insert at rear , 2 to display , 3 to search , 4 to delete at front, 5 to insert at front, 6 to delete at rear , 7 to exit :  \n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter the value\n");
            scanf("%d", &x);
            insertRear(x);
            display();
            break;

        case 2:
            display();
            break;

        case 3:
            printf("Enter the value\n");
            int val;
            scanf("%d", &val);
            search(val);
            break;

        case 4:
            delFront();
            display();
            break;

        case 5:
            printf("Enter the value\n");
            scanf("%d", &x);
            insertFront(x);
            display();
            break;
            
        case 6:
            delRear();
            display();
            break;

        case 7:
            k = 0;
            break;

        default:
            printf("Enter a valid input\n");
            break;
        }
    }
}