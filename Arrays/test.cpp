#include <bits/stdc++.h>
using namespace std;

int main()
{
	char str[]="My name is Sartaj Bir Singh";
	char *ptr=strtok(str," ");
	cout<<ptr<<endl;
	while(ptr!=NULL)
	{
		ptr=strtok(NULL," ");
		cout<<ptr<<endl;
	}
}