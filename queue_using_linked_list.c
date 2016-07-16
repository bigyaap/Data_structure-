
#include <stdio.h>
#include <stdlib.h>

struct node{
	int info;
	struct node *next;
};
typedef struct node NodeType;
NodeType *rear=0,*front=0;
void insert(int);
void delete();
void display();

int main(){
	int choice, item;
	do
	{
    printf("\n\n\t\t*******MENU*******");
	printf("\n1.Insert \n2.Delete \n3.Display\n4:Exit\n");
	printf("enter your choice\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("\nEnter the data:\n");
			scanf("%d",&item);
			insert(item);
			break;
		case 2:
			delete();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(1);
			break;
		default:
			printf("invalid choice.\n");
			break;
		}
	}while(choice<5);
	return 0;
}
void insert(int item) {
NodeType *nnode;    //declaration of a node
nnode=( NodeType *)malloc(sizeof(NodeType));
if(rear==0) {  //if there are no nodes
	nnode->info=item;
	nnode->next=NULL;
	rear=front=nnode;
}
else {
	nnode->info=item;
	nnode->next=NULL;
	rear->next=nnode;
	rear=nnode;
	}
}

void delete() {  //deletes a node
	NodeType *temp;
	if(front==0){  //if queue is empty
		printf("Queue contain no elements.\n");
		return;
	}
	else if(front->next==NULL) {  //if queue is not empty
		temp=front;
		rear=front=NULL;
		printf("\nDeleted item is %d\n",temp->info);
		free(temp);
	}
	else {
		temp=front;
		front=front->next;
		printf("\nDeleted item is %d\n",temp->info);
		free(temp);
	}
}
void display() {
	NodeType *temp;
	temp=front;
	printf("\nQueue items are:\t");
	while(temp!=NULL){
		printf("%d\t",temp->info);
		temp=temp->next;
	}
}
