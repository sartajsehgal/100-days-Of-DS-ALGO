#include <iostream>
#include <climits>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	cout<<"Enter the array: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n-1;i++)
	{
		int minIndex=i;
		for(int j=i;j<n;j++)
		{
			if(arr[j]<arr[minIndex])
			{
				minIndex=j;
			}
		}
		swap(arr[minIndex],arr[i]);
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}