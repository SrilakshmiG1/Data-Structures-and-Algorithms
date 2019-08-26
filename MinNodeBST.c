//Minimum node in Binary Search Tree
#include<stdio.h>
#include<malloc.h>
typedef struct bst
{
	struct bst *left;
	int data;
	struct bst *right;
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
typedef struct Queue
{
	s *ptr;
	struct Queue *next;
}q;
q *CreateQueue()
{
	return NULL;
}
int IsEmptyQueue(q *Q)
{
	if(Q==NULL)
	{
		return 1;
	}
	return 0;
}
q *DeQueue(q *Q)
{
	if(Q!=NULL)
	{
		return Q;
	}
	return NULL;
}
q *EnQueue(q *Q,s *tree)
{
	q *node,*temp;
	node=(q*)malloc(sizeof(q));
	node->ptr=tree;
	node->next=NULL;
	if(Q==NULL)
	{
		Q=node;
	}
	else
	{
		for(temp=Q;temp->next!=NULL;temp=temp->next);
		temp->next=node;
	}
	return Q;
}
int MinNode(s *tree)
{
	s *temp;
	int min=999;
	q *Q=CreateQueue();
	if(tree==NULL)
	{
		return;
	}
	Q=EnQueue(Q,tree);
	while(!IsEmptyQueue(Q))
	{
		Q=DeQueue(Q);
		temp=Q->ptr;
		Q=Q->next;
		if(temp->data<min)
		{
			min=temp->data;
		}
		if(temp->left)
		{
			Q=EnQueue(Q,temp->left);
		}
		if(temp->right)
		{
			Q=EnQueue(Q,temp->right);
		}
		free(temp);
	}
	DeleteQueue(Q);
	return min;
}
void DeleteQueue(q *Q)
{
	q *temp;
	while(Q!=NULL)
	{
		temp=Q;
		Q=Q->next;
		temp->next=NULL;
		free(temp);
	}
}
s *Create(s *tree)
{
	int n,val;
	printf("enter no.of nodes:");
	scanf("%d",&n);
	for(;n>0;n--)
	{
		printf("enter node:");
		scanf("%d",&val);
		tree=Insert(tree,val);
	}
	return tree;
}
main()
{
	s *tree=NULL;
	int val;
	tree=Create(tree);
	val=MinNode(tree);
	printf("Minimum node: %d",val);
}
