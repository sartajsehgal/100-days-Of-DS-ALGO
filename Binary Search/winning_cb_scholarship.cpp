#include <iostream>
#define int long long int
using namespace std;

bool isPossible(int n,int m,int x,int y,int mid)
{
	if(mid*x<=m+(n-mid)*y)
		return true;
	return false;
}

int32_t main()
{
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	int s=0,e=n,ans=0;
	while(s<=e)
	{
		int mid=(s+e)/2;
		bool canGiveScholarship=isPossible(n,m,x,y,mid);
		//cout<<"s: "<<s<<" mid: "<<mid<<" e: "<<e<<endl;
		if(canGiveScholarship)
		{
			ans=mid;
			s=mid+1;
		}
		else
		{
			e=mid-1;
		}
		//cout<<"s: "<<s<<" mid: "<<mid<<" e: "<<e<<endl;
	}
	cout<<ans<<endl;
}