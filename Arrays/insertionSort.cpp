#include <iostream>
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
	for(int i=1;i<=n-1;i++)
	{
		int cur=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>cur)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=cur;
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}