#include<stdio.h>
#include <ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
int top=-1;
float stack[MAX]; 
void push(float value)
{
    if(top==MAX-1)
    {
        printf("Stack OVERFLOW");
        return; 
    }
    else
    {
    	top++; 
    	stack[top]=value; 
	}

}

float pop()
{
	if(top==-1)
	{
		printf("Stack Underflow"); 
		return '\0'; 
	}
	else
	{
		return stack[top--]; 
	}
}


void display()
{
	
	for (int i=top; i>=0; i-- )
	{
		printf("%c",stack[i]); 
	}
}

float peek()
{
	if(top==-1)
	{
		printf("Stack Underflow"); 
		return '\0'; 
	}
	else
	{
		return stack[top];
		
	}
}
int main()
{
	char str[100]={"35*6-25/+"}; 
	float x1, x2, ans;

	int j=0;  
	int len = strlen(str);
	for (int i=0;i<len;i++){
		if (isdigit(str[i])){
			push(str[i] - '0');
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
			x1 = pop() ;
			x2 = pop() ;
			
			char op = str[i];
			if (op == '+'){
				ans = x2 + x1;
			}
			else if (op == '-'){
				ans = x2 - x1;
			}
			else if (op == '*'){
				ans = x2 * x1;
			}
			else if (op == '/'){
				ans = x2 / x1;
				
			
			}
			push(ans);
			
		}
		
		
	} 
	ans = pop();
	printf("%f", ans);
	return 0;
}