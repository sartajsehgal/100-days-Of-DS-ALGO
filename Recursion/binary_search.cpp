#include <iostream>
using namespace std;

int binary_search(int arr[],int l,int r,int key)
{
	if(l<=r)
	{
		int mid=(l+r)/2;
		if(arr[mid]==key)
		{
			return mid;
		}
		if(arr[mid]>key)
		{
			return binary_search(arr,l,mid-1,key);
		}
		else if(arr[mid]<key)
		{
			return binary_search(arr,mid+1,r,key);
		}
	}
	return -1;
}

int main()
{
	int arr[]={1,2,5,6,7,8,10,11};
	int n=sizeof(arr)/sizeof(int);
	int key;
	cin>>key;
	int res=binary_search(arr,0,n-1,key);
	if(res==-1)
	{
		cout<<"Element not found.\n";
	}
	else
	{
		cout<<key<<" found at index: "<<res<<endl;
	}
}