#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <climits>
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
		cout<<endl;
	}

	void single_source_shortest_path(int src)
	{
		map<int,int> distance;
		queue<int> q;

		for(auto node:l)
		{
			distance[node.first]=INT_MAX;
		}

		q.push(src);
		distance[src]=0;

		while(!q.empty())
		{
			int n=q.front();
			q.pop();
			for(auto nbr:l[n])
			{
				if(distance[nbr]==INT_MAX)
				{
					q.push(nbr);
					distance[nbr]=distance[n]+1;
				}
			}
		}

		for(auto val:distance)
		{
			cout<<"The distance of node "<<val.first<<" is "<<val.second<<endl;
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
	g.single_source_shortest_path(0);
}