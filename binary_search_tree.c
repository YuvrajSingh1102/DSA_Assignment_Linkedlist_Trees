//Tree traversal.

#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
        int data;
        struct tree *l;
        struct tree *r;

}tree;

tree* Min(tree *node)
{
        if(node==NULL)
        {
                 
                return NULL;
        }
        if(node->l)  
                return Min(node->l);
        else 
                return node;
}
tree* Max(tree *node)
{
        if(node==NULL)
        {
                 
                return NULL;
        }
        if(node->r) 
                Max(node->r);
        else 
                return node;
}

tree * Insert(tree *node,int data)
{
        if(node==NULL)
        {
                tree *temp;
                temp = (tree *)malloc(sizeof(tree));
                temp -> data = data;
                temp -> l = temp -> r = NULL;
                return temp;
        }

        if(data >(node->data))
        {
                node->r = Insert(node->r,data);
        }
        else if(data < (node->data))
        {
                node->l = Insert(node->l,data);
        }
       
        return node;

}

tree * Delete(tree *node, int data)
{
        tree *temp;
        if(node==NULL)
        {
                printf("\nElement Not Found\n");
        }
        else if(data < node->data)
        {
                node->l = Delete(node->l, data);
        }
        else if(data > node->data)
        {
                node->r = Delete(node->r, data);
        }
        else
        {
                 
                if(node->r && node->l)
                {
                        
                        temp = Min(node->r);
                        node -> data = temp->data; 
                       
                        node -> r = Delete(node->r,temp->data);
                }
                else
                {
                       
                        temp = node;
                        if(node->l == NULL)
                                node = node->r;
                        else if(node->r == NULL)
                                node = node->l;
                        free(temp);  
                }
        }
        return node;

}

tree * Find(tree *node, int data)
{
        if(node==NULL)
        {
                 
                return NULL;
        }
        if(data > node->data)
        {
                 
                return Find(node->r,data);
        }
        else if(data < node->data)
        { 
                return Find(node->l,data);
        }
        else
        {
                 
                return node;
        }
}

void PrintInorder(tree *node)
{
        if(node==NULL)
        {
                return;
        }
        PrintInorder(node->l);
        printf("%d ",node->data);
        PrintInorder(node->r);
}

void PrintPreorder(tree *node)
{
        if(node==NULL)
        {
                return;
        }
        printf("%d ",node->data);
        PrintPreorder(node->l);
        PrintPreorder(node->r);
}

void PrintPostorder(tree *node)
{
        if(node==NULL)
        {
                return;
        }
        PrintPostorder(node->l);
        PrintPostorder(node->r);
        printf("%d ",node->data);
}

int main()
{
        tree *root = NULL;
        root = Insert(root, 60);
        root = Insert(root, 70);
        root = Insert(root, 5);
        root = Insert(root, 17);
        root = Insert(root, 45);
        root = Insert(root, 32);
        root = Insert(root, 10);
        root = Insert(root, 13);
        PrintInorder(root);
        printf("\n");
        root = Delete(root,5);
        root = Delete(root,-1);
        PrintInorder(root);
        printf("\n");
        tree * temp;
        temp = Min(root);
        printf("Min:- %d\n",temp->data);
        temp = Max(root);
        printf("Max:- %d\n",temp->data);
        temp = Find(root,17);
        if(temp==NULL)
        {
                printf("Element 17 not found\n");
        }
        else
        {
                printf("Element 17 Found\n");
        }
        temp = Find(root,12);
        if(temp==NULL)
        {
                printf("Element 12 not found\n");
        }
        else
        {
                printf("Element 12 Found\n");
        }
}


