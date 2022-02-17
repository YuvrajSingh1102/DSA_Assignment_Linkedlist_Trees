#include<stdio.h>
#include<stdlib.h>

struct node
{
        int info;
        struct node *link;
};

struct node *addatbeg(struct node *first,int data);
struct node *addatend(struct node *first,int data);
struct node *addatpos(struct node *first,int data,int pos);
struct node *del(struct node *first,int data);
void display(struct node *first);
void count(struct node *first);
struct node* copy(struct node *first); // Copy function is not working properly. i have tried but not get the expected output.

int main()
{
        struct node *first=NULL;
        int op,data,item,pos;

        while(1)
        {
                
                
                
                printf("1.Add at beginning\n");
		printf("2.Add at end\n");
		printf("3.Add at position\n");
		printf("4.Delete\n");
		printf("5.Display\n");
		printf("6.Count\n");
		printf("7.Copy\n");
               	printf("8.Quit\n\n");

                printf("Enter your choice : ");
                scanf("%d",&op);

                switch(op)
                {
                 case 1:
                        printf("Enter the element to be inserted : ");
                        scanf("%d",&data);
                        first=addatbeg(first,data);
                        break;
                 case 2:
                        printf("Enter the element to be inserted : ");
                        scanf("%d",&data);
                        first=addatend(first,data);
                        break;
                 
                 case 3:
                        printf("Enter the element to be inserted : ");
                        scanf("%d",&data);
                        printf("Enter the position at which to insert : ");
                        scanf("%d",&pos);
                        first=addatpos(first,data,pos);
                        break;

                 case 4:
                        printf("Enter the element to be deleted : ");
                        scanf("%d",&data);
                        first=del(first, data);
                        break;

		 case 5:
                        display(first);
                        break;

		case 6:
                        count(first);
                        break;

		case 7:
			first = copy(first);
			display(first);
			break;
           
                 case 8:
                         exit(1);
                 default:
                         printf("Invalid Input\n");
                }
        }

        return 0;
}



void display(struct node *first)
{
        struct node *p;
        if(first==NULL)
        {
                printf("List is empty\n");
                return;
        }
        p=first;
        printf("List is :\n");
        while(p!=NULL)
        {
                printf("%d ",p->info);
                p=p->link;
        }
        printf("\n\n");
}

void count(struct node *first)
{
        struct node *p;
        int cnt=0;
        p=first;
        while(p!=NULL)
        {
                p=p->link;
                cnt++;
        }
        printf("Number of elements are %d\n",cnt);
}

struct node *addatbeg(struct node *first,int data)
{
        struct node *tmp;
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=data;
        tmp->link=first;
        first=tmp;
        return first;
}

struct node *addatend(struct node *first,int data)
{
        struct node *p,*tmp;
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=data;
        p=first;
        while(p->link!=NULL)
                p=p->link;
        p->link=tmp;
        tmp->link=NULL;
        return first;
}


struct node *addatpos(struct node *first,int data,int pos)
{
        struct node *tmp,*p;
        int i;
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=data;
        if(pos==1)
        {
                tmp->link=first;
                first=tmp;
                return first;
        }
        p=first;
        for(i=1; i<pos-1 && p!=NULL; i++)
                p=p->link;
        if(p==NULL)
                printf("There are less than %d elements\n",pos);
        else
        {
                tmp->link=p->link;
                p->link=tmp;
        }
        return first;
}

struct node *del(struct node *first,int data)
{
        struct node *tmp,*p;
        if(first==NULL)
        {
                printf("List is empty\n");
                return first;
        }

        if(first->info==data)
        {
                tmp=first;
                first=first->link;
                free(tmp);
                return first;
        }

        p=first;
        while(p->link!=NULL)
        {
                if(p->link->info==data)
                {
                        tmp=p->link;
                        p->link=tmp->link;
                        free(tmp);
                        return first;
                }
                p=p->link;
        }
        printf("Element %d not found\n",data);
        return first;
}

struct node* copy(struct node *first)
	  {
	    struct node *new,*save,*pred,*begin;
	    new = (struct node *)malloc(sizeof(struct node));
	    if(first == NULL){
	     printf("empty\n");
	      return NULL;
	     }
	     
	     if(new== NULL){
	     printf("underflow");
	    }
	
	    new->info = first->info;
	    begin = new;
	    save= first;
	
	    pred= new;
	    while(save->link!=NULL)
	    {
	      if(new ==NULL){
	      printf("underflow");
	      return NULL;
	    }
	     new->info = save->info;
	     new->link = new;
	     pred = new;
	     save = save->link; 
	    }
	    new->link = NULL;
	   return begin;
}

