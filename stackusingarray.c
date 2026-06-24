#include<stdio.h>
#define MAXSIZE 5
int stack[MAXSIZE];
int top = -1;

void push(int value){
	if(top == MAXSIZE - 1){
		printf("Stack Overflow.");
	}
	else{
		top++;
		stack[top] = value;
	}
}
void pop(){
	int value;
	
	if (top == -1){
		printf("Stack Underflow\n");
	}
	else{
		value = stack[top];
		top--;
		printf("%d popped\n",value);
	}
}

void peek(){
	if (top == -1){
		printf("Stack Underflow\n");
		return;
	}
	else{
		printf("Top is %d\n", stack[top]);
	}
}

void display(){
	if(top == -1){
		printf("Stack Underflow");
		return;
	}
	else{
		printf("Stack elements are:\n");
		for(int i = 0; i<=top; i++){
			printf("%d ", stack[i]);
		}
		printf("\n");
	}
}

int main(){
	
	int i, num;
	printf("Enter the elements:\n");
	for(i = 0; i<MAXSIZE; i++){
		scanf("%d ", &num);
		push(num);
	}
	pop();
	peek();
	display();
}