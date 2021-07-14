#include <bits/stdc++.h>
#define int long long int
using namespace std;

int solution()
{
	int arr[3][3];
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(i==1 && j==1)
			{
				continue;
			}
			else
			{
				cin>>arr[i][j];
			}
		}
	}
	int count=0;
	if(arr[0][1]-arr[0][0]==arr[0][2]-arr[0][1])
	{
		count++;
	}
	if(arr[2][1]-arr[2][0]==arr[2][2]-arr[2][1])
	{
		count++;
	}
	if(arr[1][0]-arr[0][0]==arr[2][0]-arr[1][0])
	{
		count++;
	}
	if(arr[1][2]-arr[0][2]==arr[2][2]-arr[1][2])
	{
		count++;
	}
	vector<int> f;
	unordered_map<int,int> mp;
	int a,b;
	a=abs(arr[0][1]-arr[2][1]);
	if(arr[0][1]<arr[2][1])
	{
		f.push_back(arr[0][1]+(a/2));
		mp[arr[0][1]+(a/2)]=0;
	}
	else
	{
		f.push_back(arr[2][1]+(a/2));
		mp[arr[2][1]+(a/2)]=0;
	}
	b=abs(arr[1][0]-arr[1][2]);
	if(arr[1][0]<arr[1][2])
	{
		f.push_back(arr[1][0]+(b/2));
		mp[arr[1][0]+(b/2)]=0;
	}
	else
	{
		f.push_back(arr[1][2]+(b/2));
		mp[arr[1][2]+(b/2)]=0;
	}
	b=abs(arr[0][0]-arr[2][2]);
	if(arr[0][0]<arr[2][2])
	{
		f.push_back(arr[0][0]+(b/2));
		mp[arr[0][0]+(b/2)]=0;
	}
	else
	{
		f.push_back(arr[2][2]+(b/2));
		mp[arr[2][2]+(b/2)]=0;
	}
	b=abs(arr[0][2]-arr[2][0]);
	if(arr[0][2]<arr[2][0])
	{
		f.push_back(arr[0][2]+(b/2));
		mp[arr[0][2]+(b/2)]=0;
	}
	else
	{
		f.push_back(arr[2][0]+(b/2));
		mp[arr[2][0]+(b/2)]=0;
	}
	for(auto i=f.begin();i!=f.end();++i)
	{
		mp[*i]++;
	}
	int max=0;
	for(auto i=mp.begin();i!=mp.end();++i)
	{
		if(i->second>=max)
		{
			max=i->second;
		}
	}
	count+=max;
	return count;
}

int32_t main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
        int sol=solution();
        cout<<"Case #"<<i+1<<": "<<sol<<endl;
	}
}