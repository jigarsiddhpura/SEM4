// #include <stdio.h>
// #include <stdlib.h>
// int max = 10;

// struct Node
// {
//     int data, pr;
//     struct Node *next;
// };

// struct Node *front = NULL, *prev = NULL;

// struct Node *createNode(int data, int pr)
// {
//     struct Node *temp;
//     temp = (struct Node *)malloc(sizeof(struct Node));
//     temp->next = NULL;
//     temp->data = data;
//     temp->pr = pr;
//     return temp;
// }

// void display()
// {
//     struct Node *temp;
//     temp = front;
//     if (temp == NULL)
//     {
//         printf("Linked list not present");
//     }
//     else
//     {
//         while (temp != NULL)
//         {
//             printf(" %d(%d) ", temp->data, temp->pr);
//             temp = temp->next;
//         }
//     }
// }

// void insert()
// {
//     struct Node *temp, *new;
//     int data, pr;
//     printf("Enter the value u wanna add- ");
//     scanf("%d", &data);
//     printf("Enter the priority of value - ");
//     scanf("%d", &pr);
//     new = createNode(data, pr);
//     temp = front;
//     if (front == NULL)
//     {
//         temp = new;
//         front = new;
//     }
//     else if (temp == front && temp!=NULL)
//     {
//         if (temp->pr > new->pr)
//         {
//             new->next = temp;
//             front = new;
//         }
//         else
//         {
//             temp->next = new;
//             temp = new;
//             front = temp;
//         }
//         prev = front;
//     }
//     else
//     {
//         while (temp != NULL)
//         {
//             if (prev->pr < new->pr && temp->pr > new->pr)
//             {
//                 new->next = temp;
//                 prev->next = new;
//             }
//             prev = temp;
//             temp = temp->next;
//         }
//     }
// }

// void main()
// {
//     int k = 1;
//     while (k)
//     {
//         int op;
//         printf("\nEnter 1 to add a node , 2 to display , 3 to exit : ");
//         scanf("%d", &op);
//         switch (op)
//         {
//         case 1:
//             insert();
//             display();
//             break;

//         case 2:
//             display();
//             break;

//         case 3:
//             k = 0;
//         }
//     }
// }

// C code to implement Priority Queue
// using Linked List
#include <stdio.h>
#include <stdlib.h>

// Node
typedef struct node {
	int data;

	// Lower values indicate higher priority
	int priority;

	struct node* next;

} Node;

// Function to Create A New Node
Node* newNode(int d, int p)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = d;
	temp->priority = p;
	temp->next = NULL;

	return temp;
}

// Return the value at head
int peek(Node** head)
{
	return (*head)->data;
}

// Removes the element with the
// highest priority from the list
void pop(Node** head)
{
	Node* temp = *head;
	(*head) = (*head)->next;
	free(temp);
}

// Function to push according to priority
void push(Node** head, int d, int p)
{
	Node* start = (*head);

	// Create new Node
	Node* temp = newNode(d, p);

	// Special Case: The head of list has lesser
	// priority than new node. So insert new
	// node before head node and change head node.
	if ((*head)->priority > p) {

		// Insert New Node before head
		temp->next = *head;
		(*head) = temp;
	}
	else {

		// Traverse the list and find a
		// position to insert new node
		while (start->next != NULL &&
			start->next->priority < p) {
			start = start->next;
		}

		// Either at the ends of the list
		// or at required position
		temp->next = start->next;
		start->next = temp;
	}
}

// Function to check is list is empty
int isEmpty(Node** head)
{
	return (*head) == NULL;
}

// Driver code
int main()
{
	// Create a Priority Queue
	// 7->4->5->6
	Node* pq = newNode(4, 1);
	push(&pq, 5, 2);
	push(&pq, 6, 3);
	push(&pq, 7, 0);

	while (!isEmpty(&pq)) {
		printf("%d ", peek(&pq));
		pop(&pq);
	}

	return 0;
}
