#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool isPossible(vector<int> cooks,int p,int n,int mid)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		float discriminant=1+8*((float)mid/(float)cooks[i]);
		float sq_disc=sqrt(discriminant);
		float x=(-1+sq_disc)/2;
		int no_of_pratas=floor(x);
		if(no_of_pratas>0)
			sum+=no_of_pratas;
	}
	if(sum>=p)
		return true;
	return false;
}

int minutes_for_order(vector<int> cooks,int p,int n)
{
	sort(cooks.begin(),cooks.end());
	int s=0;
	int e=((p*(p+1))/2)*cooks[n-1];
	int ans=0;
	while(s<=e)
	{
		int mid=(s+e)/2;
		bool prata_possible=isPossible(cooks,p,n,mid);
		if(prata_possible)
		{
			ans=mid;
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
		int p;
		cin>>p;
		int n;
		cin>>n;
		vector<int> cooks;
		for(int i=0; i<n; i++)
		{
			int a;
			cin>>a;
			cooks.push_back(a);
		}
		cout<<minutes_for_order(cooks,p,n)<<endl;
	}
}