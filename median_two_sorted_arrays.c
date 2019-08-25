//Median of two sorted arrays
#include<stdio.h>
int max(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	return b;
}
int min(int a,int b)
{
	if(a<b)
	{
		return a;
	}
	return b;
}
int getmedian(int arr[],int n)
{
	if (n % 2 == 0) 
		return (arr[n / 2] + 
				arr[n / 2 - 1]) / 2; 
	else
		return arr[n / 2]; 
} 


int median(int a1[],int a2[],int n)
{
	int m1,m2;
	m1=getmedian(a1,n);
	m2=getmedian(a2,n);
	if(m1==m2)
	{
		printf("median:%d",m1);
	}
	else if(n==0)
	{
		printf("empty arrays");
	}  
	else if(n==1)
	{
		printf("%d",(m1+m2)/2);
	}
	else if(n==2)
	{
		return (max(a1[0],a2[0])+min(a1[1],a2[1]))/2;
	}
	else
	{
		if(m1>m2)
		{
			if(n%2==0)
			{
				return median(a1+n/2-1,a2,n-n/2+1);
			}
			return median(a1+n/2-1,a2,n-n/2);
		}
		if(n%2==0)
		{
			return median(a2+n/2-1,a1,n-n/2+1);
		}
		return median(a2+n/2,a1,n-n/2);
	}
}

main()
{
	int n,i,m1,m2,med;
	printf("enter size of an array:");
	scanf("%d",&n);
	int arr1[n],arr2[n];
	printf("enter array1 elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr1[i]);
	}
	printf("enter array2 elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr2[i]);
	}
	med=median(arr1,arr2,n);
	printf("%d",med);	
}
