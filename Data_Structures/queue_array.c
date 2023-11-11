#include<stdio.h>
#include<stdlib.h>
int max=10 , queue[30], rear = -1 , front = -1  ;


void enque(){
    if(rear == max-1){
        printf("Queue is full");
        exit;
    }
    else if(front==-1){
        front = 0;
    }
    int val;
    printf("Enter the value");
    scanf("%d",&val);
    rear ++;
    queue[rear] = val;
    
}

void deque(){
    int val = queue[front];
    if(front == -1){
        printf("Queue underflow");
        exit;
    }
    else if(front == rear ) {
        front = rear = -1;
    }
    else{
        front++ ;
    }

}

void display(){
    if(front == -1){
        printf("Queue not present");
        exit;
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d ", queue[i]);
        }
    }
}

void search(int val){
    if(front == -1){
        printf("Queue not present");
    }
    else{
        for(int i=front;i<rear;i++){
            if(val == queue[i]){
            printf("Value at index %d ", i);
            }
        }
    }

}

void main(){
    int k= -1;
    while(k == -1){
        int op;
        printf("\nEnter 1 to insert value , 2 to display , 3 to search , 4 to delete , 5 to exit :  ");
        scanf("%d", &op);
        switch (op)
        {
        case 1: ;
            enque();
            display();
            break;

        case 2: ;
            display();
            break;

        case 3: ;
        int val;
            printf("Enter the value");
            scanf("%d",&val);
            search(val);
            break;

        case 4: ;
            deque();
            display();
            break;

        case 5: ;
            k = 0;
            break;
        }
    }
}