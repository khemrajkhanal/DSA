#include<stdio.h>
#include<stdlib.h>
struct node {
	int info;
	struct node *next;
};
struct node *head = NULL;

void insertion_at_begining(int data){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode -> info = data;
	if (head == NULL){
		newnode -> next = NULL;
		head = newnode;
		return;
	}
	newnode -> next = head;
	head = newnode;
}


void insertion_at_end(int data){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode -> info = data;
	newnode -> next = NULL;
	if (head == NULL){
		head = newnode;
		return;
	}
	struct node *ptr = head;
	while(ptr->next != NULL){
		ptr = ptr -> next;
	}
	ptr -> next = newnode;
}

void insertion_at_middle(int data, int pos){
	if (pos < 1) return;
    if (pos == 1) {
        insertion_at_begining(data);
        return;
    }
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode -> info = data;
	struct node *ptr = head;
	for (int i=0; i<pos-1; i++){
		ptr = ptr -> next;
		if (ptr == NULL){
			printf("Position not found\n");
			free(newnode);
		return;
	    }
	}
	newnode->next = ptr->next;
	ptr->next = newnode;
}

void deletion_at_begining(){
	if (head == NULL){
		printf("List is Empty!\n");
		return;
	}
	struct node *ptr = head;
	head = head -> next;
	printf("Deleted element is %d\n", ptr->info);
	free(ptr);
}
void deletion_at_end(){
	if (head->next == NULL){
		struct node *ptr;
		ptr = head;
		head = NULL;
		printf("Deleted element is %d\n", ptr->info);
		free(ptr);
		return;
	}

	struct node *ptr = head;
	struct node *temp;
	while(ptr->next != NULL){
		temp = ptr;
		ptr = ptr->next;
	}
	temp->next = NULL;
	printf("Deleted element is %d\n", ptr->info);
	free(ptr);
	
}
void deletion_at_middle(int pos){
	if (head == NULL){
		printf("List is Empty!\n");
		return;
	}
	if (pos < 1) return;

    if (pos == 1) {
        deletion_at_begining();
        return;
    }
	struct node *ptr = head;
	struct node *temp;
	for (int i=1; i<pos; i++){
		temp = ptr;
		ptr = ptr->next;
		if (ptr == NULL){
			printf("Position not Found!\n");
			return;
		}
		temp->next = ptr->next;
		printf("Deleted element is %d\n", ptr->info);
		free(ptr);
		
	}
}

void display(){
	struct node *temp = head;
	while(temp != NULL){
		printf("%d -> ", temp->info);
		temp = temp -> next;
	}
	printf("NULL\n");
}

int main(){
	insertion_at_begining(10);
	insertion_at_begining(30);
	insertion_at_begining(20);
	insertion_at_begining(40);
	insertion_at_end(70);
  printf("Initial List: ");
	display();
	deletion_at_begining();
  printf("After deleting from beginning: ");
	display();
	deletion_at_end();
  printf("After deleting from end: ");
  display();
	deletion_at_middle(2);
  printf("After deleting at position 2: ");
	display();
}
