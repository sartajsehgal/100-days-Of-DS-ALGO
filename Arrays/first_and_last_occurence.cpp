#include <iostream>
using namespace std;

int first_occurrence(int arr[],int n,int key)
{
	int s=0;
	int e=n-1;
	int ans=-1;
	while(s<=e)
	{
		int mid=(s+e)/2;
		if(arr[mid]==key)
		{
			ans=mid;
			e=mid-1;
		}
		else if(key>arr[mid])
		{
			s=mid+1;
		}
		else
			e=mid-1;
	}
	return ans;
}

int last_occurrence(int arr[],int n,int key)
{
	int s=0;
	int e=n-1;
	int ans=-1;
	while(s<=e)
	{
		int mid=(s+e)/2;
		if(arr[mid]==key)
		{
			ans=mid;
			s=mid+1;
		}
		else if(key>arr[mid])
		{
			s=mid+1;
		}
		else
			e=mid-1;
	}
	return ans;
}

int main()
{
	int arr[]={1,2,4,6,7,8,8,8,8,8,8,9,10,11,15};
	int n=sizeof(arr)/sizeof(int);
	int k=8;
	cout<<"First Occurence is: "<<first_occurrence(arr,n,k)<<endl;
	cout<<"Last Occurence is: "<<last_occurrence(arr,n,k)<<endl;
}