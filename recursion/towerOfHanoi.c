#include<stdio.h>
int count = 0;
void hanoi(int n, char source, char aux, char dest){
	if (n == 1){
		printf("Disk %d transferred from %c to %c.\n",n, source, dest);
		count += 1;
	}
	else{
		hanoi(n-1, source, dest, aux);
		printf("Disk %d transferred from %c to %c.\n",n, source, dest);
		count += 1;
		hanoi(n-1, aux, source, dest);
	}
	
}

int main(){
	int n ;
	printf("Enter the number of disks: ");
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
	printf("Movement required is %d", count);
}