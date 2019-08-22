#include<stdio.h>
#include<malloc.h>
typedef struct list
{
	int data;
	struct list *next;
}s;
s *Create(s *head)
{
	s *temp,*node;
	int i,n;
	printf("Enter no.of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		node=(s*)malloc(sizeof(s));
		scanf("%d",&node->data);
		node->next=NULL;
		if(head==NULL)
		{
			head=node;
			temp=node;
		}
		else
		{
			temp->next=node;
			temp=node;
		}
	}
	return head; 
}
s *Merge(s *head1,s *head2)
{
	if(head1==NULL && head2==NULL)
	{
		printf("both are empty lists");
		return head1;
	}
	else if(head1!=NULL && head2==NULL)
	{
		return head1;
	}
	else if(head1==NULL && head2!=NULL)
	{
		return head2;
	}
	else
	{
		s *ptr1=head1,*ptr2=head2,*node,*temp;
		node=(s*)malloc(sizeof(s));
		temp=node;
		while(ptr1!=NULL && ptr2!=NULL)
		{
			if(ptr1->data<=ptr2->data)
			{
				temp->next=ptr1;
				temp=ptr1;
				ptr1=ptr1->next;
			}
			else
			{
				temp->next=ptr2;
				temp=ptr2;
				ptr2=ptr2->next;
			}
		}
		if(ptr1==NULL)
		{
			temp->next=ptr2;
		}
		else{
			temp->next=ptr1;
		}
		temp=node;
		temp=temp->next;
		node->next=NULL;
		free(node);
		return temp;
	}
}
main()
{
	s *head1=NULL,*head2=NULL,*ptr;
	head1=Create(head1);
	head2=Create(head2);
	ptr=Merge(head1,head2);
	for(;ptr!=NULL;ptr=ptr->next)
	{
		printf("%d\t",ptr->data);
	}
}



Enter no.of nodes:5
10
23
45
68
97
Enter no.of nodes:5
12
34
56
67
78
10      12      23      34      45      56      67      68      78      97
--------------------------------
Process exited after 31.67 seconds with return value 0
Press any key to continue . . .
