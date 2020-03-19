#include <bits/stdc++.h>
using namespace std;
int findMinVertex(bool *visited, int *dist, int V)
{
    int minVertex = -1;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && (minVertex == -1 || dist[minVertex] > dist[i]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}
void Dijkstras(int **g, int V)
{
    int *dist = new int[V];
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        dist[i] = INT_MAX;
    }

    dist[0] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        //Find the min Vertex and mark it visited
        int minVertex = findMinVertex(visited, dist, V);
        visited[minVertex] = true;

        // Visiting the neighbours of min Vertex
        for (int j = 0; j < V; j++)
        {
            if (g[minVertex][j] != 0 && !visited[j])
            {
                if (dist[j] > g[minVertex][j]+dist[minVertex])
                {
                    // Update if current weight is less than the path
                    //through the chosen minVertex
                    dist[j] = g[minVertex][j]+dist[minVertex];
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
       cout<<i<<" "<<dist[i]<<endl;
    }
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
        int f, s, w;
        cin >> f >> s >> w;
        g[f][s] = w;
        g[s][f] = w;
    }
    
    Dijkstras(g, V);

    // Delete dynamically allocated memory.
    for (int i = 0; i < V; i++)
        delete[] g[i];
    delete[] g;

    return 0;
}

