//Ques-Construct a BST and find type of unbalancing if any,
// an unbalance node is one in which the balance factor is not among {-1, 0, 1}.

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
} node;

node* createnode();

node* createnode()
{
	int data;
	node *temp;
	temp=(node*)malloc(sizeof(node));

	if(temp==NULL)
	{
		printf("Memory not allocated\n");
		return NULL;
	}

	printf("Enter data(-1 for no node):\n");
	scanf("%d",&data);

	if(data==-1)
		return NULL;

	temp->data=data;
	printf("Enter left child of %d:\n",data );
	temp->left=createnode();
	printf("Enter right child of %d:\n",data );
	temp->right=createnode();

	return temp;

}

int checkUnbalance(node* temp)
{
	int l,r;
	if(!temp)
		return 0;
	else
	{
		l=checkUnbalance(temp->left);
		r=checkUnbalance(temp->right);
		int max= l>r ? l:r;
		if(abs(l-r)>1)
		{
			printf(" %d is an Unbalanced node\n",temp->data );
		}
		else
			printf(" %d is a Balanced node\n",temp->data );	
		return (1+max);
	}
}

int main()
{
	node* root;
	root=createnode();
	checkUnbalance(root);

	return 0;
}