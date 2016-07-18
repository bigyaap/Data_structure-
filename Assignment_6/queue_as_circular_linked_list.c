#include<stdio.h>
#include<conio.h>
typedef struct cqueue
{
 int info;
 struct cqueue *next;
}node;
node *front=NULL,*rear=NULL,*temp;
void insert();
void delet();
void traverse();
void main()
{
 int ch;
 do
 {
 printf("\npress 1 to insert the element ");
 printf("\npress 2 to delete the element");
 printf("\npress 3 to traverse the queue");
 printf("\npress 4 to exit");
 printf("\nEnter choice : ");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:
 insert();
 break;
  case 2:
 delet();
 break;
 case 3:
 traverse();
 break;
 case 4:
 exit(1);
 default:
 printf("\nInvalid choice :");
 }
 getch();
 }while(1);
}
void insert()  //inserts node
{
 node *newnode;
 newnode=(node*)malloc(sizeof(node));
 printf("\nEnter the node value : ");
 scanf("%d",&newnode->info);
 newnode->next=NULL;
 if(rear==NULL)
 front=rear=newnode;
 else
 {
 rear->next=newnode;
 rear=newnode;
 }
 rear->next=front;
}
void delet() {  //deletes a node

 temp=front;
 if(front==NULL)
 printf("\nUnderflow");
 else
 {
 if(front==rear)
 {
 printf("\nDeleted item:%d",front->info);
 front=rear=NULL;
 }
 else
 {
 printf("\nDeleted item:%d",front->info);
 front=front->next;
 rear->next=front;
 }
 temp->next=NULL;

 free(temp);
 }
}
void traverse()
{  //prints the data of each node
 temp=front;
 if(front==NULL)
 printf("\nEmpty!!!");
 else
 {
 printf("\n");
 for(;temp!=rear;temp=temp->next)
 printf("\nInfo:%d address=%u next=%u\t",temp->info,temp,temp->next);
 printf("\nInfo:%d address=%u next=%u\t",temp->info,temp,temp->next);
 }
}
