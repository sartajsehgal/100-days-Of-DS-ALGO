#include <bits/stdc++.h>
using namespace std;

class Graph
{
	unordered_map<int,list<int>> mp;
public:
	void addEdge(int a,int b)
	{
		mp[a].push_back(b);
	}
	void bfs(int val,int src)
	{
		queue<int> q;
		unordered_map<int,bool> visited;
		unordered_map<int,int> parent;

		q.push(src);
		visited[src] = true;

		while(!q.empty() && q.front()!=val)
		{
			int n= q.front();
			q.pop();
			
				for(auto nbr:mp[n])
				{
					if(!visited[nbr])
					{
						parent[nbr]=n;
						visited[nbr]=true;
						q.push(nbr);
					}
				}
			
		}
		vector<int> ans;
		ans.push_back(val);
		int nxt = parent[val];
		while(nxt!=src)
		{
			ans.push_back(nxt);
			nxt=parent[nxt];
		}
		reverse(ans.begin(),ans.end());
		cout<<src<<" ";
		for(auto i=ans.begin();i!=ans.end();++i)
		{
			cout<<*i<<" ";
		}
		cout<<endl;
	}
};

int main()
{
	int m,n,s;
	cin>>n>>m>>s;
	Graph g;
	int size=m*n;
	for(int i=0;i<size;i++)
	{
		int x;
		cin>>x;
		vector<int> v;
		for(int j=0;j<8;j++)
		{
			int a;
			cin>>a;
			v.push_back(a);
		}
		if(v[0]==1)
			g.addEdge(x,x-m);
		if(v[1]==1)
			g.addEdge(x,x-m+1);
		if(v[2]==1)
			g.addEdge(x,x+1);
		if(v[3]==1)
			g.addEdge(x,x+m+1);
		if(v[4]==1)
			g.addEdge(x,x+m);
		if(v[5]==1)
			g.addEdge(x,x+m-1);
		if(v[6]==1)
			g.addEdge(x,x-1);
		if(v[7]==1)
			g.addEdge(x,x-m-1);
	}

	g.bfs(1,s);
	g.bfs(m,s);
	g.bfs(size-m+1,s);
	g.bfs(size,s);
}