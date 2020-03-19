// Directed Graph
#include <bits/stdc++.h>
using namespace std;
void printBFS(int **g, int V, int start)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    visited[start] = true;

    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int front = q.front();
        cout << front << " ";
        q.pop();
        for (int i = 0; i < V; i++)
        {
            if (g[front][i] == 1 && visited[i] == false)
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
void printDFS(int **g, int V, int start)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    visited[start] = true;

    stack<int> s;
    s.push(start);
    while (!s.empty())
    {
        int top = s.top();
        cout << top << " ";

        s.pop();
        for (int i = 0; i < V; i++)
        {
            if (g[top][i] == 1 && visited[i] == false)
            {
                s.push(i);
                visited[i] = true;
            }
        }
    }
}

void printtopolgical(int **g, int V)
{

    // vertices. Initialize all indegrees as 0.
    vector<int> in_degree(V, 0);

    // Traverse adjacency lists to fill indegrees of
    // vertices.  This step takes O(V+E) time
    for (int u = 0; u < V; u++)
    {
        for (int i = 0; i < V; i++)
        {
            if (g[u][i] == 1)
                in_degree[i]++;
        }
    }

    // Create an queue and enqueue all vertices with
    // indegree 0
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (in_degree[i] == 0)
            q.push(i);

    // Initialize count of visited vertices
    int cnt = 0;

    // Create a vector to store result (A topological
    // ordering of the vertices)
    vector<int> top_order;

    // One by one dequeue vertices from queue and enqueue
    // adjacents if indegree of adjacent becomes 0
    while (!q.empty())
    {
        // Extract front of queue (or perform dequeue)
        // and add it to topological order
        int u = q.front();
        q.pop();
        top_order.push_back(u);

        // Iterate through all its neighbouring nodes
        // of dequeued node u and decrease their in-degree
        // by 1

        for (int i = 0; i < V; i++)
        {
            if (g[u][i] == 1)
            {
                if (--in_degree[i] == 0)
                    q.push(i);
            }
        }
        cnt++;
    }

    // Check if there was a cycle
    if (cnt != V)
    {
        cout << "There exists a cycle in the graph\n";
        return;
    }

    // Print topological order
    for (int i = 0; i < top_order.size(); i++)
        cout << top_order[i] << " ";
    cout << endl;
}

int main()
{
    int V, E;
    cin >> V >> E;
    int **g = new int *[V];
    for (int i = 0; i < V; i++)
    {
        g[i] = new int[V];
        for (int j = 0; j < V; j++)
            g[i][j] = 0;
    }

    for (int i = 0; i < E; i++)
    {
        int f, s;
        cin >> f >> s; // edge from f to s : f ---> s
        g[f][s] = 1;
    }
    cout << "\nPrint BFS:" << endl;
    printBFS(g, V, 0);

    cout << "\nPrint DFS:" << endl;
    printDFS(g, V, 0);

    cout << "\nPrint Topological:" << endl;
    printtopolgical(g, V);

    // Delete dynamically allocated memory.
    for (int i = 0; i < V; i++)
        delete[] g[i];
    delete[] g;

    return 0;
}