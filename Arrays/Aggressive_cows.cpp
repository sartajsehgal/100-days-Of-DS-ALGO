#include<iostream>
#include<algorithm>
#include<vector>
#define int long long int
using namespace std;

int agg_cows()
{
	int n,c;
	cin>>n>>c;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	int e=*(v.end()-1)-*v.begin();
	//cout<<"Val of e: "<<e<<endl;
	int s=0,ans=0;
	while(s<=e)
	{
		int mid=(s+e)/2;
		int i=0,j=0,k=1;
		while(k<=n)
		{
			if(v[k]-v[j]>=mid)
			{
				i++;
				j=k;
				k++;
			}
			else
			{
				k++;
			}
		}
		//cout<<"i: "<<i<<"e: "<<e<<"mid: "<<mid<<endl;
		if(i>=c)
		{
			//cout<<"hello"<<endl;
			s=mid+1;
			ans=mid;
		}
		else
		{
			//cout<<"hello else"<<endl;
			e=mid-1;
		}
	}
	return ans;
}

int32_t main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cout<<agg_cows()<<endl;
	}
}