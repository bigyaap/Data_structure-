#include<stdio.h>
#include<stdlib.h>

struct Node  {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head; // global variable - pointer to head node.

//Creates a new Node and returns pointer to it.
struct Node* GetNewNode(int x) {
	struct Node* newNode
		= (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

//Inserts a Node at head of doubly linked list
void InsertAtHead(int x) {
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}

//Inserts a Node at tail of Doubly linked list
void InsertAtTail(int x) {
	struct Node* temp = head;
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	while(temp->next != NULL) temp = temp->next; // Go To last Node
	temp->next = newNode;
	newNode->prev = temp;
}

//Prints all the elements in linked list in forward traversal order
void Print() {
	struct Node* temp = head;
	printf("Forward: ");
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

//Prints all elements in linked list in reverse traversal order.
void ReversePrint() {
	struct Node* temp = head;
	if(temp == NULL) return; // empty list, exit
	// Going to last Node
	while(temp->next != NULL) {
		temp = temp->next;
	}
	// Traversing backward using prev pointer
	printf("Reverse: ");
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

int main() {

	/*Driver code to test the implementation*/
	head = NULL; // empty list. set head as NULL.

	// INSERT YOUR CODE HERE
int choice;
int item;
do{
printf("\n *********MENU*********:\n");
printf("1. create a newnode\n2. Insert at head\n3. Insert at tail \n4. Print\n5. Reverse print\n6.Exit\n");
printf("enter your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Enter item to be inserted");
scanf("%d", &item);
GetNewNode(item);
break;
case 2:
printf("Enter item to be inserted");
scanf("%d", &item);
InsertAtHead(item);
break;
case 3:
printf("Enter item to be inserted");
scanf("%d", &item);
InsertAtTail(item);
break;
case 4:
Print();
break;
case 5:
ReversePrint();
break;
case 6:
exit(0);
default:
printf("invalid choice\n");
break;
}
}while(choice<10);
return 0;
}
