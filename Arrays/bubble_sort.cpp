#include <iostream>
using namespace std;

int main()
{
	int arr[8]={2,5,1,8,6,9,4,3};
	int n=8;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
			}
		}
	}
	for(int i=0;i<8;i++)
	{
		cout<<arr[i]<<", ";
	}
}