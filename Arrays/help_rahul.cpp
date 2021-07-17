#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int solution(int arr[],int n,int minIndex,int key)
{
	if(key==arr[minIndex])
		return minIndex;
	if(key>arr[n-1])
	{
		auto it=lower_bound(arr,arr+minIndex,key);
		if(*it==key)
		{
			return it-arr;
		}
	}
	auto nit=lower_bound(arr+minIndex,arr+n,key);
	if(*nit==key)
	{
		return nit-arr;
	}
	return -1;
}

int main() {
	int min=INT_MAX;
	int n,minIndex=0;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i]<min)
		{
			min=arr[i];
			minIndex=i;
		}
	}
	int key;
	cin>>key;
	cout<<solution(arr,n,minIndex,key);
	return 0;
}