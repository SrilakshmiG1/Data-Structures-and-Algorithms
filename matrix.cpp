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
