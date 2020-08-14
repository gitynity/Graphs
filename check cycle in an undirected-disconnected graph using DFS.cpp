#include <bits/stdc++.h>

using namespace std;

class graph
{
	int v;				  //number of vertices
	vector<int> adj[100]; //adjacency list
	bool visited[100];
public:
	graph(int);
	void addedge(int, int);
	bool check_cycle();
	bool modified_dfs(int,int);
	void print_adjacency_list();
};

graph::graph(int n)
{
	this->v = n; //number of vertices initialised to n

	for (int i = 0; i < n; i++) //initialised visited array as false for all vertices
		{
			visited[i] = false;
		}
}

void graph::addedge(int a, int b)
{
	adj[a].push_back(b);
	adj[b].push_back(a);
}

void graph::print_adjacency_list()
{
	for (int i = 0; i < v; i++)
	{
		cout << i << "---";
		for (auto x : adj[i])
			cout << x << " ";
		cout << "\n";
	}
}

bool graph::modified_dfs(int node , int parent)
{
	visited[node] = true;
	
	for(auto i:adj[node])
	{
		if(visited[i]==false)
		{
			if(modified_dfs(i,node)==true)
				return true;
		}
		else if(i!=parent)	// i.e if visited[i]==true but i is not parent of the current node
			return true;
	}
	return false;
}

bool graph::check_cycle()
{
	for(int i=0;i<v;i++)
		if(visited[i]==false)
			if(modified_dfs(i,-1)==true)
				return true;
	return false;	
}

int main()
{
	graph g(5); //made a graph with 5 vertices

	g.addedge(0, 1);
	g.addedge(0, 2);
	g.addedge(2, 3);
	g.addedge(3, 1);
	cout << "Adjacency List\n";
	g.print_adjacency_list();

	if(g.check_cycle())
	cout<<"Cycle exists\n";
	else 
	cout<<"No cycle\n";
	return 0;
}
