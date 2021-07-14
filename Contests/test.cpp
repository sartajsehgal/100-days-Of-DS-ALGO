#include <iostream>
#include <vector>
#include <algorithm>
#define int long long int
using namespace std;

vector<int> solution(int n,int m)
{
    vector<int> solution;
    vector<int> dif;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        for(int j=a;j<=b;j++)
        {
            dif.push_back(j);
        }
    }
    sort(dif.begin(),dif.end());
    // cout<<"DIf array\n";
    // for(auto j=dif.begin();j!=dif.end();++j)
    //     {
    //         cout<<*j<<" ";
    //     }
    for(int i=0;i<m;i++)
    {
        int a;
        cin>>a;
        //cout<<"Student "<<i+1<<": "<<a<<endl;
        if(binary_search(dif.begin(),dif.end(),a))
        {
            auto b=lower_bound(dif.begin(),dif.end(),a);
            solution.push_back(*b);
            dif.erase(b);
        }
        else
        {
            auto b=upper_bound(dif.begin(),dif.end(),a);
            if(b==dif.begin())
            {
                solution.push_back(*b);
                dif.erase(b);
            }
            else
            {
                if(*b-a<a-*(b-1))
                {
                    solution.push_back(*b);
                    dif.erase(b);
                }
                else if(*b-a>a-*(b-1))
                {
                    solution.push_back(*(b-1));
                    dif.erase(b-1);
                }
                else
                {
                    solution.push_back(*(b-1));
                    dif.erase(b-1);
                }
            }
        }
    }
    return solution;
}

int32_t main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int n,m;
        cin>>n>>m;
        vector<int> sol=solution(n,m);
        cout<<"Case #"<<i+1<<": ";
        for(auto j=sol.begin();j!=sol.end();++j)
        {
            cout<<*j<<" ";
        }
        cout<<endl;
    }
}