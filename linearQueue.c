#include<stdio.h>
#define MAXSIZE 5
int rear = -1;
int top = 0;
int queue[MAXSIZE];

void dequeue(){
	if (top > rear){
		printf("Queue Underflow!\n");
		return;
	}
	printf("%d is deleted\n", queue[top]);
	top++;
}

void enqueue(int value){
	if (rear == MAXSIZE - 1){
		printf("Queue Overflow!\n");
		return;
	}
	rear++;
	queue[rear] = value;
}

void display(){
	int start = top;
	int end = rear;
	printf("Elements in queue.\n");
	for(int i = start; i<=end; i++){
		printf("%d ",queue[i]);
	}
}

void view(){
	if(top > rear){
		printf("Queue Underflow!\n");
		return;
	}
	printf("\nTop = %d", queue[top]);
}

int main(){
	int n, val;
	printf("How mamy element you want to insert: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		printf("Enter element:");
		scanf("%d", &val);
		enqueue(val);
	}
	dequeue();
	display();
	return 0;
}