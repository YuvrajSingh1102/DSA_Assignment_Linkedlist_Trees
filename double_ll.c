//Doubly linkedlist.
	
#include <stdio.h>
#include <stdlib.h>
	
struct node
{
	int data;
	struct node *prev;
	struct node *next;
}*head, *last;
	
int insertFirst(int );	
int insertEnd(int );
int display();
int delete(int );
	
int main()
{
	int x, op=0, del;
	
	while(op<8)
	{
	printf("\n1.Insert an element at first\n2.Insert an element at last\n3.Display linkedlist\n4.Delete an Element\n5.Exit\n");
	scanf("%d", &op);
	switch(op)
	{
	case 1:
	printf("Enter an element: ");
	scanf("%d", &x);
	insertFirst(x);
	break;
	
	case 2:
	printf("Enter an element: ");
	scanf("%d", &x);
	insertEnd(x);
	break;
	
	case 3:
	display();
	break;
		
	case 4:
	printf("Enter the number do you want to delete: ");
	scanf("%d", &del);
	delete(del);
	break;
	
	case 5:
	return 0;

	default:
	printf("Invalid input !! Please try again.");
	}

	}
}

int insertFirst(int x)
{
	struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	
	newNode -> data = x;
		
	if(head == NULL)
	{
	newNode -> prev = NULL;
	newNode -> next = NULL;
	head = last = newNode;

	return 0;
	}
	
	head -> prev = newNode;
	newNode -> next = head;
	newNode -> prev = NULL;
	head = newNode;

}
	
int insertEnd(int x)
{
		
	struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	
	newNode -> data = x;
	
	if(head == NULL)
	{
	newNode -> prev = NULL;
	newNode -> next = NULL;
	head = last = newNode;

	return 0;
	}
	
	last -> next = newNode;
	newNode -> next = NULL;
	newNode -> prev = last;
	last = newNode;

}
				
int display()
	{
	struct node *temp;
	if(head==NULL)
	{
	printf("Linkedlist is empty.\n");
	return 0;
	}
	printf("Elements of linkedlist is: ");
	temp = head;
	while(temp != NULL)
	{
	printf("%d ", temp -> data);
	temp = temp -> next;
	}
	printf("\n");
}
	
int delete(int x)
{
	struct node *temp;
	if(head == NULL)
	{
	printf("Linked list is empty\n");
	return 0;
	}
	if(x == head -> data)
	{
	if(head == last)
	{
	head = last = NULL;

	return 0;
	}
	
	head = head -> next;
	head -> prev = NULL;
		

	}
	else if(x == last -> data)
	{
	last = last -> prev;
	last -> next = NULL;

	}
	else
	{
	temp = head;
	while(temp != NULL)
	{
	temp = temp -> next;
	if(x == temp -> data)
	{
	break;
	}
	}	
	if(x != temp -> data)
	{
	printf("Element not found\n");
	return 0;
	}
	temp -> prev -> next = temp -> next;
	temp -> next -> prev = temp -> prev;
	printf("%d deleted successfully\n", x);
	}
}
