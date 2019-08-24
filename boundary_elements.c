//printing the boundary elements of binary elements

#include<stdio.h>
#include<malloc.h>
typedef struct bstree
{
	struct bstree *left;
	int data;
	struct bstree *right;
}s;
s *Insert(s *tree,int val)
{
	if(tree==NULL)
	{
		tree=(s*)malloc(sizeof(s));
		tree->data=val;
		tree->left=tree->right=NULL;
	}
	else if(val>tree->data)
	{
		tree->right=Insert(tree->right,val);
	}
	else
	{
		tree->left=Insert(tree->left,val);
	}
	return tree;
}
s *Create(s *tree)
{
	int n,val;
	printf("total nodes:");
	scanf("%d",&n);
	for(;n>0;n--)
	{
		printf("enter element:");
		scanf("%d",&val);
		tree=Insert(tree,val);
	}
	return tree;
}
void Leaves(s *tree)
{
	if(tree==NULL)
	{
		return;
	}
	Leaves(tree->left);
	if(tree!=NULL && tree->left==NULL && tree->right==NULL)
	{
		printf("%d\t",tree->data);
	}
	Leaves(tree->right);
}
void BoundaryElementsLeft(s *tree)
{
	if(tree==NULL)
	{
		return;
	}
	if(tree->left)
	{
		printf("%d\t",tree->data);
		BoundaryElementsLeft(tree->left);
	}
	else if(tree->right)
	{
		printf("%d\t",tree->data);
		BoundaryElementsRight(tree->right);
	}
}
void BoundaryElementsRight(s *tree)
{
	if(tree==NULL)
	{
		return;
	}
	if(tree->right)
	{
		BoundaryElementsRight(tree->right);
		printf("%d\t",tree->data);
	}
	else if(tree->left)
	{
		BoundaryElementsRight(tree->left);
		printf("%d\t",tree->data);
	}
}
void BoundaryElements(s *tree)
{
	if(tree!=NULL)
	{
		printf("%d\t",tree->data);
		BoundaryElementsLeft(tree->left);
		Leaves(tree->left);
		Leaves(tree->right);
		BoundaryElementsRight(tree->right);
	}
}
main()
{
	s *tree=NULL;
	tree=Create(tree);
	BoundaryElements(tree);
}


