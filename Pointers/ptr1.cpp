#include <iostream>
using namespace std;

int main()
{
	int a=10281;
	cout<<&a<<endl;

	float b=241.21;
	cout<<&b<<endl;

	// &c doesn't print the address of char but we have to 
	// explicitly typecast it to void * or int * and fool the compiler that 
	// it is not a char and this happens due to << operator.
	char c='a';
	cout<<(void *)&c<<endl; 

	int *ptr=&a;
	cout<<sizeof(ptr)<<endl;

	char *cptr=&c;
	cout<<sizeof(cptr)<<endl;

	char *ptr2=&c;
	cout<<*ptr2<<endl;

}