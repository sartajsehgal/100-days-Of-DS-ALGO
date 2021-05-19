#include <iostream>
using namespace std;

int idx;

int linear_search(int arr[],int n,int key)
{
	if(n==0)
		return -1;
	if(arr[0]==key)
		return idx-n;
	return linear_search(arr+1,n-1,key);
}

int last_occurence(int arr[],int n,int key)
{
	if(n==0)
		return -1;
	if(arr[n-1]==key)
		return n-1;
	return last_occurence(arr,n-1,key);
}

void all_occurences(int arr[],int n,int i,int key)
{
	if(i==n)
		return;
	if(arr[i]==key)
		cout<<i<<" ";
	all_occurences(arr,n,i+1,key);
}

int main()
{
	int arr[]={4,1,7,21,86,7,3,4,1,9,2};
	//int arr[]={1,2,3,4};
	int n=sizeof(arr)/sizeof(int);
	idx=n;
	int key;
	cin>>key;
	all_occurences(arr,n,0,key);
	cout<<endl;
	int res=last_occurence(arr,n,key);
	if(res==-1)
	{
		cout<<"Element not found.\n";
	}
	else
	{
		cout<<key<<" found at index: "<<res<<endl;
	}
}