#include <stdio.h>
#define SIZE 30
int stack[SIZE], top = -1;

void push()
{
    int n, val;
    if (top == SIZE - 1)
    {
        printf("STACK OVERFLOW");
    }
    else
    {
        printf("Enter the value: ");
        scanf("%d", &val);
        top++;
        stack[top] = val;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("STACK UNDERFLOW");
    }
    else
    {
        int topmost = stack[top];
        top--;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("STACK IS EMPTY");
    }
    else
    {
        int i;
        for (i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
}

void main()
{
    int op, choice;

    while (choice != 4)
    {
        printf("\nEnter 1 to push , 2 to pop , 3 to show & 4 to exit : ");
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
            peek();
            break;
        }
        case 4:
        {
            printf("Exiting ...");
            exit();
        }
        default:
            printf("Enter valid number");
            break;
        };
    }
}