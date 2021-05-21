#include <iostream>
#include <list>
#include <map>
#include <cstring>
using namespace std;

class Graph
{
	map<string,list<pair<string,int>>> l;
public:
	void addEdge(string a, string b, bool isbidir, int wt)
	{
		l[a].push_back(make_pair(b,wt));
		if(isbidir)
			l[b].push_back(make_pair(a,wt));
	}

	void displayGraph()
	{
		for(auto n:l)
		{
			string key = n.first;
			list nbrs = n.second;
			cout<<key<<" -> ";
			for(auto nbr:nbrs)
			{
				cout<<nbr.first<<" "<<nbr.second<<",";
			} 
			cout<<endl;
		}
	}
};

int main()
{
	Graph g;
	g.addEdge("A","B",true,20);
	g.addEdge("D","B",true,30);
	g.addEdge("A","C",true,10);
	g.addEdge("C","D",true,40);
	g.addEdge("A","D",false,50);
	g.displayGraph();
}
