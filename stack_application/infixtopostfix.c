#include<stdio.h>
#include <ctype.h>
#include<string.h>

#define MAX 100
int top=-1;
char stack[MAX]; 
void push(char value)
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

char pop()
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

char peek()
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

int precedence(char op)
{
    if(op == '+' || op == '-')
        return 1;

    if(op == '*' || op == '/')
        return 2;

    return 0;
}




int main()
{
	char str[100]={"(3*5)-6+(2/5)"}; 
	char exp[100]; 

	int j=0;  
	
	int len=strlen(str) ;
	for(int i=0; i<len; i++)
	{
		if(str[i]=='(')
		{
			push(str[i]); 
		}
		
		else if(isdigit(str[i]))
		{
			exp[j++]=str[i]; 
		}
		
		else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/')
		{
			while(top!=-1 &&  precedence(peek()) >= precedence(str[i]))
		    {
		        exp[j++] = pop();
		    }
		    push(str[i]); 
			
		}
		else if(str[i] == ')')
		{
		    while(top != -1 && peek() != '(')
		    {
		        exp[j++] = pop();
		    }
		
		    pop(); 
		}
				
		
	}
	
	while(top != -1)
{
    exp[j++] = pop();
}

exp[j] = '\0';
	
	printf("%s",exp); 

    return 0; 
}