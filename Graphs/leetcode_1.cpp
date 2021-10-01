#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> arr(4,0);
	for(int i=0; i<4; i++)
	{
		cin>>arr[i];
	}	
	sort(arr.begin(), arr.end());
	string str="";
	if(arr[0]<=2 and arr[1]<=3 and arr[2]<=5)
	{
		if(arr[1]<=2 and arr[1]>arr[0])
		{
			swap(arr[0],arr[1]);	
		}
		if(arr[3]<=5 and arr[3]>arr[2])
		{
			swap(arr[2],arr[3]);	
		}
		str=str+to_string(arr[0])+to_string(arr[1])+":"+to_string(arr[2])+to_string(arr[3]);
	}
	cout<<str<<endl;	
}