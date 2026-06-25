#include<stdio.h>

int factorial(int value, int a){
	if (value == 1 || value == 0){
		return a;
	}
	else{
		return factorial(value - 1, value*a);
	}
}


int main(){
	int n, fact;
	printf("Enter the number: ");
	scanf("%d", &n);
	fact = factorial(n, 1);
	printf("Factorial is %d ", fact);
	return 0;
}