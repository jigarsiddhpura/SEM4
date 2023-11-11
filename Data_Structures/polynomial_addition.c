#include <stdio.h>
#include <stdlib.h>

struct node
{
    int c, p;
    struct node *next;
}*head1,*head2,*head3 ;

struct node *createnode(int coeff, int exp)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->c = coeff;
    temp->p = exp;
    return temp;
}

// createPoly creates a polynomial & returns its head
struct node *createPoly(struct node *head)
{
    int n, coeff, exp;
    struct node *new_node, *temp;
    printf("Enter the no.of terms:");
    scanf("%d", &n);
    while (n != 0)
    {
        printf("Enter the coefficient:");
        scanf("%d", &coeff);
        printf("Enter the power:");
        scanf("%d", &exp);
        new_node = createnode(coeff, exp);
        if (head == NULL)
        {
            head = new_node;
            temp = head;
        }
        else
        {
            temp->next = new_node;
            temp = temp->next;
        }
        n--;
    }
    printf("\n");
    return head;
}

struct node *addPoly(struct node *p1, struct node *p2, struct node *p)
{
    struct node *ptr1, *ptr2, *ptr, *nn;
    int co ,po;
    ptr1 = p1;
    ptr2 = p2;
    // ptr = createnode(0, 0);
    while (ptr1 != NULL && ptr2 != NULL)
    {
        // polynomial 1 or 2 with higher power is added to ptr
        if (ptr1->p > ptr2->p)
        {
            co = ptr1->c;
            po = ptr1->p;
            nn = createnode(co, po);
            if(p == NULL){
                p = nn;
                ptr = p;
            }
            else{
                ptr->next =nn;
                ptr = ptr->next;
            }
            ptr1 = ptr1->next;
        }
        else if (ptr1->p < ptr2->p)
        {
            co = ptr2->c;
            po = ptr2->p;
            nn = createnode(co, po);
            if(p == NULL){
                p = nn;
                ptr = p;
            }
            else{
                ptr->next =nn;
                ptr = ptr->next;
            }
            
            ptr2 = ptr2->next;
        }

        // if power sme add poly 1&2
        else
        {
            co = ptr1->c + ptr2->c;
            po = ptr1->p;
            nn = createnode(co, po);
            if(p == NULL){
                p = nn;
                ptr = p;
            }
            else{
                ptr->next =nn;
                ptr = ptr->next;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        // ptr = ptr->next;
    }

    // if one of the polynomial reaches last node , 2nd one is simply added in poly
    struct node *ptr_new;
    if (ptr1->next != NULL)
    {
        ptr_new = ptr1;
    }
    if (ptr2->next != NULL)
    {
        ptr_new = ptr2;
    }

    while (ptr_new->next != NULL)
    {
        co = ptr_new->c;
        po = ptr_new->p;
        nn = createnode(co, po);
        ptr->next = nn;
        ptr = ptr->next;
        ptr_new = ptr_new->next;
    }
    ptr->next = NULL;
    return p;
}

struct node *display(struct node *poly)
{
    // temp = head;
    if (poly == NULL)
    {
        printf("Poly not present");
    }
    else
    {
        while (poly != NULL)
        {
            printf(" %d^%d ", poly->c, poly->p);
            poly = poly->next;
        }
    }
}

void main()
{
    struct node *poly1, *poly2, *poly, *poly3;

    // creating 2 polnomial
    printf("For Equation 1:\n");
    head1 = createPoly(head1);
    display(head1);
    printf("For Equation 2:\n");
    head2 = createPoly(head2);
    display(head2);

    poly3 = addPoly(head1, head2, head3);
    // printf("success");
    display(poly3);
}