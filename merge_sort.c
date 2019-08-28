#include<stdio.h>
void Merge(int a[],int l[],int left,int mid,int right)
{
	int i,left_end,size,temp_pos;
	left_end=mid-1;
	temp_pos=left;
	size=right-left+1;
	while(left<=left_end && mid<=right)
	{
		if(a[left]<=a[mid])
		{
			l[temp_pos]=a[left];
			temp_pos++;
			left++;
		}
		else
		{
			l[temp_pos]=a[mid];
			temp_pos++;
			mid++;
		}
	}
	while(left<=left_end)
	{
		l[temp_pos]=a[left];
		temp_pos++;
		left++;
	}
	while(mid<=right)
	{
		l[temp_pos]=a[mid];
		temp_pos++;
		mid++;
	}
	for(i=0;i<=size;i++)
	{
		a[right]=l[right];
		right=right-1;
	}
}
void MergeSort(int a[],int l[],int left,int right)
{
	int mid;
	if(right>left)
	{
		mid=(right+left)/2;
		MergeSort(a,l,left,mid);
		MergeSort(a,l,mid+1,right);
		Merge(a,l,left,mid+1,right);
	}
}
main()
{
	int n,i;
	scanf("%d",&n);
	int a[n],l[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	MergeSort(a,l,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
