#include <iostream>
using namespace std;

int getbit(int n,int pos)
{
    return ((n & (1<<pos))!=0);
}

int setbit(int n,int pos)
{
    return (n | (1<<pos));
}

int clearbit(int n,int pos)
{
    return (n & ~(1<<pos));
}

int updatebit(int n,int pos,int val)
{
    int mask=~(1<<pos);
    n=(n & mask);
    return (n | (val<<pos));
}

int main() {
    cout<<getbit(8,0)<<endl; //0101
    cout<<setbit(5,0)<<endl;
    cout<<clearbit(5,2)<<endl;
    cout<<updatebit(5,1,1);
}
