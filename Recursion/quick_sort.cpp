#include <iostream>
using namespace std;

int partition(int arr[],int s,int e)
{
	int p=e;
	int j=s;
	for(int i=s;i<p;i++)
	{
		if(arr[i]<=arr[p])
		{
			swap(arr[i],arr[j]);
			j++;
		}
	}
	swap(arr[j],arr[p]);
	return j;
}

void quick_sort(int arr[],int s,int e)
{
	if(s>=e)
		return;
	int p=partition(arr,s,e);
	quick_sort(arr,s,p-1);
	quick_sort(arr,p+1,e);
	return;
}

int main()
{
	int arr[]={2,1,7,8,6,1,5,4};
	//int arr[]={4,3,2,1};
	int n=sizeof(arr)/sizeof(int); 
	quick_sort(arr,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}