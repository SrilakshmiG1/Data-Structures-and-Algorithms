//Level Order
#include<stdio.h>
#include<malloc.h>
typedef struct bst
{
	struct bst *left;
	int data;
	struct bst *right;
}s;

typedef struct Queue
{
	s *ptr;
	struct Queue *next;
}q;
q *CreateQueue()
{
    q *Q=NULL;
	return Q;
}
void EnQueue(q *Q,s *tree)
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
		temp=node;
	}
}
int IsEmptyQueue(Q)
{
	if(Q==NULL)
	{
		return 1;
	}
	return 0;
}

s *DeQueue(q *Q)
{
	s *temp;
	if(Q!=NULL)
	{
		temp=Q->ptr;
		Q=Q->next;
		return temp;
	}
	return NULL;
}
void DeleteQueue(q *Q)
{
	q *temp;
	if(Q==NULL)
	{
		return;
	}
	while(Q!=NULL)
	{
		temp=Q;
		Q=Q->next;
		temp->next=NULL;
		free(temp);
	}
}
void LevelOrder(s *tree)
{
	s *temp;
	q *Q=CreateQueue();
	if(!tree)
	{
		return;
	}
	EnQueue(Q,tree);
	while(!IsEmptyQueue(Q))
	{
		temp=DeQueue(Q);
		printf("%d",temp->data);
		if(temp->left)
		{
			EnQueue(Q,temp->left);
		}
		if(temp->right)
		{
			EnQueue(Q,temp->right);
		}
	}
	DeleteQueue(Q);
}


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
	printf("enter no.of nodes:");
	scanf("%d",&n);
	for(;n>0;n--)
	{
		printf("Enter node:");
		scanf("%d",&val);
		tree=Insert(tree,val);
	}
	return tree;
}
void Display(s *tree)
{
	if(tree!=NULL)
	{
		printf("%d\t",tree->data);
		Display(tree->left);
		Display(tree->right);
	}
}
main()
{
	s *tree=NULL;
	tree=Create(tree);
	Display(tree);
	LevelOrder(tree);
}
