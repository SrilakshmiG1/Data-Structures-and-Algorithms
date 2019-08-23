//Binary Search Tree Implementation
#include<stdio.h>
#include<malloc.h>
//Declare the binary search tree 
typedef struct bst
{
	struct bst *left;
	int data;
	struct bst *right;
}s;
//Declare Queue
typedef struct Queue
{
	int data;
	struct Queue *next;
}q;
//Height of  BST
int Height(s *tree)
{
	int left_height=0,right_height=0;
	if(tree==NULL)
	{
		return 0;
	}
	else
	{
		left_height=Height(tree->left);
		right_height=Height(tree->right);
	}
	if(left_height>right_height)
	{
		return left_height+1;
	}
	else
	{
		return right_height+1;
	}
}
//Search for an element
void Search(s *tree,int val)
{
	if(tree!=NULL)
	{
		if(tree->data==val)
		{
			printf("element found");
		}
		else if(val>tree->data)
		{
			Search(tree->right,val);
		}
		else if(val<tree->data)
		{
			Search(tree->left,val);
		}
	}
	else
	{
		printf("Element not found");
	}
}
//Preorder Traversal
void Preorder(s *tree)
{
	if(tree!=NULL)
	{
		printf("%d\t",tree->data);
		Preorder(tree->left);
		Preorder(tree->right);
	}
}
//Inorder Traversal
void Inorder(s *tree)
{
	if(tree!=NULL)
	{
		Inorder(tree->left);
		printf("%d\t",tree->data);
		Inorder(tree->right);
	}
}
//Postorder Traversal
void Postorder(s *tree)
{
	if(tree!=NULL)
	{
		Postorder(tree->left);
		Postorder(tree->right);
		printf("%d\t",tree->data);
	}
}
//EnQueue
q *EnQueue(q *Q,s *tree)
{
	q *temp,*node;
	if(Q==NULL && tree!=NULL)
	{
		node=(q*)malloc(sizeof(q));
		node->data=tree->data;
		node->next=NULL;
		Q=node;
	}
	else if(Q!=NULL && tree!=NULL)
	{
		for(temp=Q;temp->next!=NULL;temp=temp->next);
		node=(q*)malloc(sizeof(q));
		node->data=tree->data;
		node->next=NULL;
		temp->next=node;
	}
	return Q;
}

//DeQueue
q *DeQueue(q *Q)
{
	q *temp;
	if(Q!=NULL)
	{
		temp=Q;
		Q=Q->next;
		temp->next=NULL;
		return Q,temp;
	}
}
//Lever Order of BST	
void LevelOrder(q *Q,s *tree)
{
	q *temp;
	int i=0;
	if(tree!=NULL)
	{
		Q=EnQueue(Q,tree);
		while(Q!=NULL)
		{
			i++;
			if(i==1)
			{
				break;
			}
			Q,temp=DeQueue(Q);
			//Process current node
			printf("%d",temp->data);
			if(tree->left!=NULL)
			{
				Q=EnQueue(Q,tree->left);
			}
			if(tree->right!=NULL)
			{
				
				Q=EnQueue(Q,tree->right);
			}
		}
	}	
}
//Insert new node in bst
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
//Delete a node of BST
void Delete(s *tree,s *parent,int val)
{
	s *temp;
	if(tree==NULL)
	{
		printf("Empty Tree");
	}
	else if(val<tree->data)
	{
		Delete(tree->left,tree,val);
	}
	else if(val>tree->data)
	{
		Delete(tree->right,tree,val);
	}
	else if(tree->left!=NULL && tree->right!=NULL)
	{
		temp=tree->left;parent=tree;
		while(temp->right!=NULL)
		{
			parent=temp;
			temp=temp->right;
		}
		tree->data=temp->data;
		Delete(temp,parent,temp->data);
	}
	else if(tree->left==NULL && tree->right==NULL)
	{
		if(parent!=NULL)
		{
			if(parent->left==tree)
			{
				parent->left=NULL;
			}
			else
			{
				parent->right=NULL;
			}
		}
		free(tree);
	}
	else if(tree->left==NULL)
	{
		tree->data=tree->right->data;
		Delete(tree->right,tree,tree->right->data);
	}
	else
	{
		tree->data=tree->left->data;
		Delete(tree->left,tree,tree->left->data);
	}
	
}
//Total Nodes
int Total(s* tree)
{
	if(tree==NULL)
	{
		return 0;
	}
	else
	{
		return Total(tree->left)+Total(tree->right)+1;
	}
}
//Create BST
s *Create(s *tree)
{
	int i,n,val;
	printf("Enter Total nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter value:");
		scanf("%d",&val);
		tree=Insert(tree,val);
	}
	return tree;
}
main()
{
	s *tree=NULL,*parent=NULL;
	q *Q=NULL;
	int opt=1,val;
	while(opt)
	{
		printf("\n1.Create\n2.Search\n3.Insert\n4.Delete\n5.Zig Zag Order\n6.Inorder\n7.Preorder\n8.Postorder\n9.Level Order\n10.Height\n11.Total nodes\n12.Min Node\n14.Max Node\n15.Enter 0 to exist\nChoose:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				tree=Create(tree);
				break;
			case 2:
				printf("Enter value:");
				scanf("%d",&val);
				Search(tree,val);
				break;
			case 3:
				printf("Enter value:");
				scanf("%d",&val);
				tree=Insert(tree,val);
				break;
			case 4:
				printf("Enter value:");
				scanf("%d",&val);
				Delete(tree,parent,val);
				break;
			case 5:
				break;
			case 6:
				Inorder(tree);
				break;
			case 7:
				Preorder(tree);
				break;
			case 8:
				Postorder(tree);
				break;
			case 9:
				LevelOrder(Q,tree);
				break;
			case 10:
				val=Height(tree);
				printf("Height of BST: %d",val);
				break;
			case 11:
				val=Total(tree);
				printf("Total Nodes: %d",val);
				break;
			case 12:
				break;
			case 13:
				break;
			case 14:
				break;
			case 0:
				printf("Existed successfully");
				break;
			default:
				printf("Wrong option!!");
				break;
		}
	}
}
