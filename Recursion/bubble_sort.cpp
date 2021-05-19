#include <iostream>
using namespace std;

void bubble_sort(int arr[],int n,int i)
{
	if(n==1)
		return;
	if(i==n-1)
		return bubble_sort(arr,n-1,0);
	if(arr[i]>arr[i+1])
		swap(arr[i],arr[i+1]);
	bubble_sort(arr,n,i+1);
	return;
}

void bubble_sort1(int arr[],int n)
{
	if(n==1)
	{
		return;
	}
	for(int i=0;i<n-1;i++)
	{
		if(arr[i]>arr[i+1])
		{
			swap(arr[i],arr[i+1]);
		}
	}
	bubble_sort1(arr,n-1);
}

int main()
{
	int arr[]={1,6,2,7,8,3};
	int n=sizeof(arr)/sizeof(int);
	//bubble_sort(arr,n,0);
	bubble_sort1(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}