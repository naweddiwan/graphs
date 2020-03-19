#include <bits/stdc++.h>
using namespace std;
int findMinVertex(bool *visited, int *weight, int V)
{
    int minVertex = -1;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && (minVertex == -1 || weight[minVertex] > weight[i]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}
void prims(int **g, int V)
{
    int *weight = new int[V];
    int *parent = new int[V];
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        weight[i] = INT_MAX;
    }

    weight[0] = 0;
    parent[0] = -1;
    for (int i = 0; i < V - 1; i++)
    {
        //Find the min Vertex and mark it visited
        int minVertex = findMinVertex(visited, weight, V);
        visited[minVertex] = true;

        // Visiting the neighbours of min Vertex
        for (int j = 0; j < V; j++)
        {
            if (g[minVertex][j] != 0 && !visited[j])
            {
                if (weight[j] > g[minVertex][j])
                {
                    // Update if current weight is less than the path
                    //through the chosen minVertex
                    weight[j] = g[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    for (int i = 1; i < V; i++)
    {
        if (parent[i] < i)
            cout << parent[i] << " " << i << " " << weight[i] << endl;
        else
            cout << i << " " << parent[i] << " " << weight[i] << endl;
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
    prims(g, V);

    // Delete dynamically allocated memory.
    for (int i = 0; i < V; i++)
        delete[] g[i];
    delete[] g;

    return 0;
}

