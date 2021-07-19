#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> arr,int n,int m,int mid)
{
	int std=1;
	int cs=0;
	for(int i=0;i<n;i++)
	{
		if(cs+arr[i]>mid)
		{
			std++;
			cs=arr[i];
			if(std>m)
				return false;
		}
		else
		{
			cs+=arr[i];
		}
	}
	return true;
}

int max_pages()
{
	int n,m;
	cin >> n >> m;
	vector<int> arr;
	int sum=0,ans=INT_MAX;
	for(int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
		sum+=a;
	}
	int s=arr[n-1];
	int e=sum;
	if(n<m)
		return -1;
	while(s<=e)
	{
		int mid=(s+e)/2;
		if(possible(arr,n,m,mid))
		{
			ans=min(ans,mid);
			e=mid-1;
		}
		else
		{
			s=mid+1;
		}
	}
	return ans;
}

int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		cout<<max_pages()<<endl;
	}
	return 0;
}