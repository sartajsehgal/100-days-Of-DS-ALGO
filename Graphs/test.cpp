#include <iostream>
#include <unordered_map>
#include <list>
#include <cstring>
#include <queue>
using namespace std;

class Graph
{
	unordered_map<int,list<int>> mp;
public:
	void addEdge(int x, int y, bool isbidir)
	{
		mp[x].push_back(y);
		if(isbidir)
		{
			mp[y].push_back(x);
		}
	}

	void bfs(int s)
	{
		unordered_map<int,bool> visited;
		queue<int> q;
		q.push(s);
		visited[s] = true;
		while(!q.empty())
		{
			int temp = q.front();
			q.pop();
			cout<<temp<<" ";
			for(auto nbr : mp[temp])
			{
				if(visited[nbr]==false)
				{
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
	}

	int dfs(int s)
	{
		unordered_map<int,bool> visited;
		for()
	}
};

int main()
{
	Graph g;
	g.addEdge(0,1,true);
	g.addEdge(0,3,true);
	g.addEdge(1,2,true);
	g.addEdge(2,3,true);
	g.addEdge(3,4,true);
	g.addEdge(4,5,true);
	g.bfs(0);
}