#include <stdio.h>
#include <stdlib.h>
struct node
{
    int c, p;
    struct node *next;
} * start1, *start2, *start3;
struct node *create(struct node *start)
{
    int n, coeff, po;
    struct node *nn, *temp;
    printf("Enter the no.of terms:");
    scanf("%d", &n);
    while (n != 0)
    {
        printf("Enter the coefficient:");
        scanf("%d", &coeff);
        printf("Enter the power:");
        scanf("%d", &po);
        nn = (struct node *)malloc(sizeof(struct node));
        nn->c = coeff;
        nn->p = po;
        if (start == NULL)
        {
            start = nn;
            temp = start;
        }
        else
        {
            temp->next = nn;
            temp = temp->next;
        }
        n--;
    }
    return start;
}
struct node *add(struct node *s1, struct node *s2, struct node *s3)
{
    struct node *t1, *t2, *t3, *nn;
    t1 = s1;
    t2 = s2;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->p == t2->p)
        {
            nn = (struct node *)malloc(sizeof(struct node));
            nn->c = t1->c + t2->c;
            nn->p = t1->p;
            if (s3 == NULL)
            {
                s3 = nn;
                t3 = s3;
            }
            else
            {
                t3->next = nn;
                t3 = t3->next;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        else if (t1->p > t2->p)
        {
            nn = (struct node *)malloc(sizeof(struct node));
            nn->c = t1->c;
            nn->p = t1->p;
            if (s3 == NULL)
            {
                s3 = nn;
                t3 = s3;
            }
            else
            {
                t3->next = nn;
                t3 = t3->next;
            }
            t1 = t1->next;
        }
        else
        {
            nn = (struct node *)malloc(sizeof(struct node));
            nn->c = t2->c;
            nn->p = t2->p;
            if (s3 == NULL)
            {
                s3 = nn;
                t3 = s3;
            }
            else
            {
                t3->next = nn;
                t3 = t3->next;
            }
            t2 = t2->next;
        }
    }
    if (t1 == NULL)
    {
        while (t2 != NULL)
        {
            nn = (struct node *)malloc(sizeof(struct node));
            nn->c = t2->c;
            t2 = t2->next;
            t3->next = nn;
            t3 = t3->next;
        }
    }
    else if (t2 == NULL)
    {
        while (t1 != NULL)
        {
            nn = (struct node *)malloc(sizeof(struct node));
            nn->c = t1->c;
            t1 = t1->next;
            t3->next = nn;
            t3 = t3->next;
        }
    }
    return s3;
}
void main()
{
    struct node *temp1, *temp2, *temp3;
    // clrscr();
    printf("Enter first equation\n");
    start1 = create(start1);
    printf("First equation is:\n");
    temp1 = start1;
    while (temp1 != NULL)
    {
        printf("%d\t", temp1->c);
        temp1 = temp1->next;
    }
    printf("\n");
    printf("Enter second equation\n");
    start2 = create(start2);
    printf("Second equation is:\n");
    temp2 = start2;
    while (temp2 != NULL)
    {
        printf("%d\t", temp2->c);
        temp2 = temp2->next;
    }
    printf("\n");
    start3 = add(start1, start2, start3);
    printf("Resultant equation is:\n");
    temp3 = start3;
    while (temp3 != NULL)
    {
        printf("%d\t", temp3->c);
        temp3 = temp3->next;
    }
}