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
	void bfs(int);
	void bfs_start();
	void print_adjacency_list();
};

graph::graph(int n)
{
	this->v = n; //number of vertices initialised to n

	for (int i = 0; i < n; i++) //initialised visited array as false for all vertices
		visited[i] = false;
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

void graph::bfs(int i)
{
	queue<int> q;
	visited[i] = true;
	q.push(i);

	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		cout<<u<<" ";
		for(int x:adj[u])
		{
			if(visited[x]==false)
			{
				q.push(x);
				visited[x] = true;
			}
		}

	}

}

void graph::bfs_start()
{
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		bfs(i);
	}
}

int main()
{
	graph g(5); //made a graph with 5 vertices

	g.addedge(0, 1);
	g.addedge(0, 2);
	g.addedge(3, 4);
	cout << "Adjacency List\n";
	g.print_adjacency_list();
	cout << "BFS\n";
	g.bfs_start();
	return 0;
}
