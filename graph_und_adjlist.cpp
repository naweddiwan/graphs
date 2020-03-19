//Undirected Graph

#include <bits/stdc++.h>
using namespace std;
// adding edge undirectedly.
void add_edge(vector<vector<int>> &adj, int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
//printing graph using vertices.
void print_graph(vector<vector<int>> adj, int V)
{
	for (int v = 0; v < V; ++v)
	{
		cout << "Adj list of vertex: " << v << endl;
		cout << v << ": [";
		int n = adj[v].size();
		for (int j = 0; j < n; j++)
		{
			if (j == n - 1)
				cout << adj[v][j];
			else
				cout << adj[v][j] << ", ";
		}
		cout << "]" << endl
			 << endl;
	}
}
//BFS traversal of the graph.
void BFS(vector<vector<int>> adj, int V, int s)
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	visited[s] = true;

	list<int> queue;
	queue.push_back(s);

	while (!queue.empty())
	{
		s = queue.front();
		cout << s << " ";
		queue.pop_front();
		for (auto it : adj[s])
		{
			if (!visited[it])
			{
				visited[it] = true;
				queue.push_back(it);
			}
		}
	}
}
// DFS traversal of the graph.
void DFS(vector<vector<int>> adj, int V, int s)
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
	visited[s] = true;

	stack<int> st;
	st.push(s);
	while (!st.empty())
	{
		s = st.top();
		cout << s << " ";
		st.pop();
		for (auto it : adj[s])
		{
			if (!visited[it])
			{
				visited[it] = true;
				st.push(it);
			}
		}
	}
	delete [] visited;
}

int main()
{
	int V, E;
	cin >> V >> E; // V : no. of vertex and E: no. of edgees

	vector<vector<int>> adj(V);

	// add_edge(adj, 0,1);
	// add_edge(adj, 0,4);
	// add_edge(adj, 1,2);
	// add_edge(adj, 1,3);
	// add_edge(adj, 1,4);
	// add_edge(adj, 2,3);
	// add_edge(adj, 3,4);

	for (int i = 0; i < E; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		add_edge(adj, v1, v2);
	}
	cout << "Adjaceny List:" << endl;
	print_graph(adj, V);

	cout << "BFS:\n";
	BFS(adj, V, 0);

	cout << "\nDFS:\n";
	DFS(adj, V, 0);

	return 0;
}