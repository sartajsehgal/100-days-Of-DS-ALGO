#include <iostream>
using namespace std;

 float square_root(int n,int p)
{
	int s=0,e=n;
	float ans=-1;
	while(s<=e)
	{
		int mid=(s+e)/2;
		if(mid*mid==n)
			return mid;
		if(mid*mid<n)
		{
			ans=mid;
			s=mid+1;
		}
		else
		{
			e=mid-1;
		}
	}
	float inc=0.1;
	for(int i=1;i<=p;i++)
	{
		while(ans*ans<=n)
		{
			ans+=inc;
		}
		ans-=inc;
		inc/=10;
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	cout<<square_root(n,4)<<endl;
	return 0;
}