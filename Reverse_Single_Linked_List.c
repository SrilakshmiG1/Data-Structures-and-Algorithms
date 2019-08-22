//Program to reverse the single linked list
#include<stdio.h>
#include<malloc.h>
typedef struct LList
{
	int data;
	struct LList *next;
}s;
s *Create(s *head)
{
	s *temp,*node;
	int n,i;
	printf("total nodes:");
	scanf("%d",&n);
	printf("enter values:");
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
s *Reverse(s *head)
{
	s *p1,*p2,*p3,*temp;
	if(head==NULL)
	{
		printf("Empty list!!");
	}
	else if(head->next==NULL)
	{
		return head;
	}
	else if(head->next->next==NULL)
	{
		temp=head->next;
		head->next=NULL;
		temp->next=head;
		head=temp;
	}
	else 
	{
		p1=head;
		p2=p1->next;
		p3=p2->next;
		p1->next=NULL;
		while(p3!=NULL)
		{
			p2->next=p1;
			p1=p2;
			p2=p3;
			p3=p3->next;
		}
		p2->next=p1;
		head=p2;
	}
	return head;
}
void Display(s *head)
{
	s *ptr;
	if(head==NULL)
	{
		printf("Empty List");
	}
	else
	{
		for(ptr=head;ptr!=NULL;ptr=ptr->next)
		{
			printf("%d\t",ptr->data);
		}
	}
}
main()
{
	s *head=NULL;
	head=Create(head);
	Display(head);
	head=Reverse(head);
	printf("\n");
	Display(head);
}
