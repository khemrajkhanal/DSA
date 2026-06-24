#include <stdio.h>
#define MAXSIZE 5  

int queue[MAXSIZE];
int front = -1;
int rear = -1;


void enqueue(int value) {
    if ((rear + 1) % MAXSIZE == front) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % MAXSIZE;
    queue[rear] = value;

}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow!\n");
        return;
    }
    
    printf("%d is deleted\n", queue[front]);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAXSIZE;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty.\n");
        return;
    }
    printf("Elements in queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % MAXSIZE; 
    }
    printf("\n");
}


void view() {
    if (front == -1) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("Top Element = %d\n", queue[front]);
}

int main() {
    int n, val;
    printf("How many elements you want to insert: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &val);
        enqueue(val);
    }
    dequeue();
    enqueue(10);
    view();
    display();
    return 0;
}
