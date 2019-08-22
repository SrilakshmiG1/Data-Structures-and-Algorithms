Given a Matrix mat of N*N size, the task is to complete the function constructLinkedMatrix(), 
that constructs a 2D linked list representation of the given matrix.

Input : 2D matrix 
1 2 3
4 5 6
7 8 9

Output :
1 -> 2 -> 3 -> NULL
|    |    |
v    v    v
4 -> 5 -> 6 -> NULL
|    |    |
v    v    v
7 -> 8 -> 9 -> NULL
|    |    |
v    v    v
NULL NULL NULL



#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int val;
	struct node *right;
	struct node *down;
}s;
s *head=NULL,*ptr1,*ptr2,*ne,*temp;

main()
{
	int n,i,j;
	printf("enter size:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			ne=(s*)malloc(sizeof(s));
			printf("enter value:");
			scanf("%d",&ne->val);
			ne->down=ne->right=NULL;
			if(head==NULL)
			{
				head=ne;
				temp=ne;
				ptr1=head;
				ptr2=head;
			}
			else if(temp==NULL)
			{
				temp=ne;
				ptr1->down=temp;
				ptr2=ptr1->right;
				ptr1=ptr1->down;
			}
			else
			{
				temp->right=ne;
				temp=ne;
				if(i>0)
				{
					ptr2->down=temp;
					ptr2=ptr2->right;
				}
			}
		}
		temp=temp->right;
	}
	for(ptr1=ptr2=head;ptr1!=NULL;)
	{
		printf("%d\t",ptr2->val);
		ptr2=ptr2->right;
		if(ptr2==NULL)
		{
			ptr1=ptr1->down;
			ptr2=ptr1;
		}
	}
}



enter size:3
enter value:1
enter value:2
enter value:3
enter value:4
enter value:5
enter value:6
enter value:7
enter value:8
enter value:9
1       2       3       4       5       6       7       8       9
--------------------------------
Process exited after 15.51 seconds with return value 0
Press any key to continue . . .

