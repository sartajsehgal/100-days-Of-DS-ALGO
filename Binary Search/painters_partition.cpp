#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

bool isPossible(vector<int> arr,int k,int n,int mid)
{
	int sum=0,cnt=1;
	for(int i=0;i<arr.size();i++)
	{
		if(sum+arr[i]<=mid)
		{
			sum+=arr[i];
		}
		else
		{
			sum=arr[i];
			cnt++;
		}
	}
	if(cnt<=k)
		return true;
	return false;
}

int main()
{
	int k,n;
	cin >> k;
	cin >> n;
	vector<int> arr;
	int sum=0,max=INT_MIN;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		sum+=a;
		if(a>max)
			max=a;
		arr.push_back(a);
	}
	int s=max;
	int e=sum,ans;
	while(s<=e)
	{
		int mid=(s+e)/2;
		bool flag=isPossible(arr,k,n,mid); 
		if(flag)
		{
			ans=mid;
			e=mid-1;
		}
		else
		{
			s=mid+1;
		}
	}
	cout<<ans<<endl;
}