#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
        int data;
        struct Node *next;
}node;
void insert(node *pointer, int data)
{
        node *start = pointer;
        /* Iterate through the list till we encounter the last node.*/
        while(pointer->next!=start)
        {
                pointer = pointer -> next;
        }
        /* Allocate memory for the new node and put data in it.*/
        pointer->next = (node *)malloc(sizeof(node));
        pointer = pointer->next;
        pointer->data = data;
        pointer->next = start;
}
int find(node *pointer, int key)
{
        node *start = pointer;
        pointer =  pointer -> next; //First node is dummy node.
        /* Iterate through the entire linked list and search for the key. */
        while(pointer!=start)
        {
                if(pointer->data == key) //key is found.
                {
                        return 1;
                }
                pointer = pointer -> next;//Search in the next node.
        }
        return 0;
}
void delete(node *pointer, int data)
{
        node *start = pointer;
        /* Go to the node for which the node next to it has to be deleted */
        while(pointer->next!=start && (pointer->next)->data != data)
        {
                pointer = pointer -> next;
        }
        if(pointer->next==start)
        {
                printf("Element %d is not present in the list\n",data);
                return;
        }
        /* pointer points to a node and the node next to it has to be removed */
        node *temp;
        temp = pointer -> next;
        /*temp points to the node which has to be removed*/
        pointer->next = temp->next;
        /*We removed the node which is next to the pointer (which is also temp) */
        free(temp);
        /* Because we deleted the node, we no longer require the memory used for it .
           free() will deallocate the memory.
         */
        return;
}
void print(node *start,node *pointer)
{
        if(pointer==start)
        {
                return;
        }
        printf("%d ",pointer->data);
        print(start,pointer->next);
}
int main()
{
        /* start always points to the first node of the linked list.
           temp is used to point to the last node of the linked list.*/
        node *start,*temp;
        start = (node *)malloc(sizeof(node));
        temp = start;
        temp -> next = start;
        /* Here in this code, we take the first node as a dummy node.
           The first node does not contain data, but it used because to avoid handling special cases
           in insert and delete functions.
         */
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print\n");
        printf("4. Find\n");
        printf("5. Exit\n");
        while(10)
        {
                int query;
                printf("Enter choice:");
                scanf("%d",&query);
                if(query==1)
                {
                        int data;
                        printf("Enter data be inserted:");
                        scanf("%d",&data);
                        insert(start,data);
                }
                else if(query==2)
                {
                        int data;
                        printf("Enter data to be deleted:");
                        scanf("%d",&data);
                        delete(start,data);
                }
                else if(query==3)
                {
                        printf("The list is: ");
                        print(start,start->next);
                        printf("\n");
                }
                else if(query==4)
                {
                        int data;
                        printf("Enter the data you want to search:");
                        scanf("%d",&data);
                        int status = find(start,data);
                        if(status)
                        {
                                printf("Element Found\n");
                        }
                        else
                        {
                                printf("Element Not Found\n");

                        }
                }
                else {
                    exit(0);
                }
        }


}
