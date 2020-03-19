
// Undirected Graph
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
        cin >> f >> s;
        g[f][s] = 1;
        g[s][f] = 1;
    }
    cout << "\nPrint BFS:" << endl;
    printBFS(g, V, 0);

    cout << "\nPrint DFS:" << endl;
    printDFS(g, V, 0);

    // Delete dynamically allocated memory.
    for (int i = 0; i < V; i++)
        delete[] g[i];
    delete[] g;

    return 0;
}
