//Circular linkedlist.
	
#include <stdio.h>
#include <stdlib.h>
	
struct node
{
	int data;
	struct node *next;
}*head, *last;

int insertFirst(int );
int insertEnd(int );
int insertInSorted(int );
int display();
int delete(int );

int main()
{
	int x, op=0, del;	
		
	
	while(op<7)
	{
	printf("\n1.Insert an element at start\n2.Insert an element at end\n3.Insert an element in between in sorted list\n4.Display the linkedlist\n5.Delete Element\n6.Exit\n");
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
	printf("Enter an element: ");
	scanf("%d", &x);
	insertInSorted(x);
	break;
	
	case 4:
	display();
	break;
	
	case 5:
	printf("Enter the number do you want to delete: ");
	scanf("%d", &del);
	delete(del);
	break;
	
	case 6:
	return 0;

	default: 
	printf("Invalid input !!! Please try again.");
	}
		
	}
}

int insertFirst(int x)
{
	struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	
	if(newNode==NULL)
	{
	printf("Underflow\n");
	return 0;
	}
	newNode -> data = x;
	
	if(head == NULL)
	{
	newNode -> next = newNode;
	head = last = newNode;
	}
	else
	{
	newNode -> next = head;
	head = newNode;
	last -> next = head;
	}
	
		
}
	
int insertEnd(int x)
{
	struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	
	if(newNode==NULL)
	{
	printf("Underflow\n");
	return 0;
	}
		
	newNode -> data = x;
	
	if(head == NULL)
	{
	newNode -> next = newNode;
	head = last = newNode;
	}
	else
	{
	last -> next = newNode;
	newNode -> next = head;
	last = newNode;
	}
}
	
int insertInSorted(int x)
{
	struct node *newNode;
	struct node *save;
	newNode = (struct node*)malloc(sizeof(struct node));
	
	if(newNode==NULL)
	{
	printf("Underflow\n");
	return 0;
	}
	
	newNode -> data = x;
	
	if(head == NULL)
	{
	newNode -> next = newNode;
	head = last = newNode;
	return 0;
	}
	
	if(x <= head -> data)
	{
	newNode -> next = head;
	head = newNode;
	last -> next = head;
	return 0;
	}
	
	if(x >= last -> data)
	{
	newNode -> next = head;
	last -> next = newNode;
	last = newNode;
	return 0;
	}
	
	save = head;
		
	while(save -> next != last -> next && newNode -> data >= save -> next -> data)
	{
	save = save -> next;
	}
	newNode -> next = save -> next;
	save -> next = newNode;
	
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
	while(temp -> next != last -> next)
	{
	printf(" %d ", temp -> data);
	temp = temp -> next;
	}
	printf("%d \n", last -> data);
		
}
	
int delete(int num)
{
	if(head==NULL)
	{
	printf("Linkedlist is empty.\n");
	return 0;
	}
	struct node *save;
	struct node *prec;
	save = head;
	while(save -> data != num && save -> next != last -> next)
	{
	prec = save;
	save = save -> next;
	}
		
	if(save -> data != num)
	{
	printf("Element not found\n");
	return 0;
	}
		
		
	if(num == head -> data)
	{
	if(head -> next == head)
	{
	head = last = NULL;
	
	return 0;
	}
	head = head -> next;
	last -> next = head;
	
	}
	else
	{
	if(num == last -> data)
	{
	last = prec;
	prec -> next = head;

	return 0;
	}
	prec -> next = save -> next;

	free(save);
	}
		
}
