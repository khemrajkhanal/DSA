#include<stdio.h>
#include<string.h>
#define MAXSIZE 100

char stack[100];
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
	int i = 0;
	printf("Enter the string:");
	scanf("%s", str);
	for(i = 0; i<strlen(str); i++){
		push(str[i]);
	}
	char reverse[100];
	for(i = 0; i<strlen(str); i++){
		reverse[i] = pop();
	}
	reverse[i] = '\0'; /* Null-terminate the reversed string */
	
	printf("%s", reverse);
	return 0;
}