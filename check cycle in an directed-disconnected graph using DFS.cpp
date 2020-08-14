#include <bits/stdc++.h>

using namespace std;

class graph
{
	int v;				  //number of vertices
	vector<int> adj[100]; //adjacency list
	bool visited[100];
	bool parent[100];
public:
	graph(int);
	void addedge(int, int);
	bool check_cycle();
	bool modified_dfs(int);
	void print_adjacency_list();
};

graph::graph(int n)
{
	this->v = n; //number of vertices initialised to n

	for (int i = 0; i < n; i++) //initialised visited array and parent array as false for all vertices
		{
			visited[i] = false;
			parent[i] = false;
		}
}

void graph::addedge(int a, int b)
{
	adj[a].push_back(b);
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

bool graph::modified_dfs(int node)
{
	visited[node] = true;
	parent[node] = true;

	for(auto i:adj[node])
	{
		if(visited[i]==false)
		{
			if(modified_dfs(i)==true)
				return true;
		}
		else if(parent[i]==true)	// i.e if visited[i]==true but i is not parent of the current node
			return true;
	}
	parent[node]=false;

	return false;
}

bool graph::check_cycle()
{
	for(int i=0;i<v;i++)
		if(visited[i]==false)
			if(modified_dfs(i)==true)
				return true;
	return false;	
}

int main()
{
	graph g(5); //made a graph with 5 vertices

	g.addedge(0, 2);
	g.addedge(1, 0);
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
