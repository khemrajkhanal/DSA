#include<stdio.h>
#include<string.h>
#define MAXSIZE 100

char stack[MAXSIZE];
int top = -1;
void push(char value){
	if(top == MAXSIZE - 1){
		printf("Stack Overflow.");
	}
	else{
		top++;
		stack[top] = value;
	}
}
char pop(){
	char value;
	
	if (top == -1){
		printf("Stack Underflow\n");
	}
	else{
		value = stack[top];
		top--;
	}
	return value;
}
int main(){
	char str[100];
	printf("Enter the parenthesis:");
	scanf("%s", str);
	int balance = 1;
	for (int i =0; str[i]!='\0';i++){
		if(str[i] == '('){
			push(str[i]);
		}
		else if(str[i]== ')'){
			if(top == -1){
				balance = 0;
				break;
			}
			pop();
			
			
		}
	}
	if(top != -1){
		balance = 0;
	}
	if(balance){
		printf("Equal");
		
	}
	else{
		printf("Not Equal");
	}
}