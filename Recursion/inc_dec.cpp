#include <bits/stdc++.h>
using namespace std;

void dec(int n)
{
	if(n>=1)
	{
		cout<<n<<", ";
		dec(n-1);
	}
	else
		return;
}

void inc(int n)
{
	if(n>=1)
	{
		inc(n-1);
		cout<<n<<", ";
	}
	else
		return;
}

int main()
{
	int n;
	cin>>n;
	inc(n);
	cout<<endl;
	dec(n);
	return 0;
}