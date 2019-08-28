#include<stdio.h>
int Partition(int a[],int low,int high)
{
	int left,right,pivot_item=a[low],temp;
	left=low;
	right=high;
	while(left<right)
	{
		while(a[left]<=pivot_item)
		{
			left++;
		}
		while(a[right]>pivot_item)
		{
			right--;
		}
		if(left<right)
		{
			temp=a[left];
			a[left]=a[right];
			a[right]=temp;
		}
	}
	a[low]=a[right];
	a[right]=pivot_item;
	return right;
}
void QuickSort(int a[],int low,int high)
{
	int pivot;
	if(high>low)
	{
		pivot=Partition(a,low,high);
		QuickSort(a,low,pivot-1);
		QuickSort(a,pivot+1,high);
	}
}
main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	QuickSort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
