//Static binary search tree.

#include <stdio.h>
#include <stdlib.h>

struct node {
	char data;
	struct node * left;
	struct node * right;
};

void preorder(struct node *);
void postorder(struct node *);
void inorder(struct node *);

int main() {

	struct node *a, *b ,*c, *d, *e, *f, *g, *tree;
	a = (struct node*)malloc(sizeof(struct node));
	b = (struct node*)malloc(sizeof(struct node));
	c = (struct node*)malloc(sizeof(struct node));
	d = (struct node*)malloc(sizeof(struct node));
	e = (struct node*)malloc(sizeof(struct node));
	f = (struct node*)malloc(sizeof(struct node));
	g = (struct node*)malloc(sizeof(struct node));

	tree = a;
	a->data = 'A';
	a->left = b;
	a->right = d;

	b->data = 'B';
	b->left = c;
	b->right = NULL;

	a->data = 'A';
	a->left = b;
	a->right = d;

	c->data = 'C';
	c->left = NULL;
	c->right = NULL;

	d->data = 'D';
	d->left = e;
	d->right = g;

	e->data = 'E';
	e->left = NULL;
	e->right = f;

	f->data = 'F';
	f->left = NULL;
	f->right = NULL;

	g->data = 'G';
	g->left = NULL;
	g->right = NULL;

	printf("Preorder of tree is:\n");
	preorder(tree);
	printf("\n");

	printf("Postorder of tree is:\n");
	postorder(tree);
	printf("\n");

	printf("Inorder of tree is:\n");
	inorder(tree);
	printf("\n");

return 0;
}

void preorder(struct node * tree) {
	if(tree == NULL) 
	{
		printf("Empty tree");
	}
	else 
	{
		printf("%c", tree->data);
		if(tree->left != NULL) {
			preorder(tree->left);

		}
		if(tree->right != NULL) {
			preorder(tree->right);
		}
	}
}

void postorder(struct node *tree) {
	if(tree == NULL) 
	{
		printf("Empty tree");
	} 
	else
	{
		if(tree->left != NULL){
			postorder(tree->left);
		}
		if(tree->right != NULL) {
			postorder(tree->right);
		}
		printf("%c", tree->data);
	}
}

void inorder(struct node * tree) {
	if(tree == NULL){
		printf("Empty tree");
	}
	else 
	{
		if(tree->left != NULL) {
			inorder(tree->left);
		}
		printf("%c", tree->data);
		if(tree->right != NULL) {
			inorder(tree->right);
		}
	}
}
