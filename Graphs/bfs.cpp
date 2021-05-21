#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;

class Graph {
	map<int,list<int>> l;
public:
	void addEdge(int x,int y)
	{
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void bfs(int src)
	{
		map<int,bool> visited;
		queue<int> q;

		q.push(src);
		visited[src]=true;

		while(q.empty()==false)
		{
			int n = q.front();
			q.pop();
			cout<<n<<" ";
			for(int nbr:l[n])
			{
				if(!visited[nbr])
				{
					q.push(nbr);
					visited[nbr]=true;
				}
			}
		}
	}
};

int main()
{
	Graph g;
	g.addEdge(0,1);
	g.addEdge(0,3);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.bfs(0);
}