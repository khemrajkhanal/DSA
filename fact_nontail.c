#include<stdio.h>


int factorial(value){
	if (value == 1 || value == 0){
		return 1;
	}
	else{
		return value *factorial(value - 1);
	}
}


int main(){
	int n, fact;
	printf("Enter the number: ");
	scanf("%d", &n);
	fact = factorial(n);
	printf("Factorial is %d ", fact);
	return 0;
}