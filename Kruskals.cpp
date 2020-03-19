#include <bits/stdc++.h>
using namespace std;
struct graph
{
    int src;
    int dest;
    int wt;
};

bool comp(graph a, graph b)
{
    return a.wt < b.wt;
}
int find_parent(int vertex, int parent[])
{
    if (vertex == parent[vertex])
        return vertex;
    else
        return find_parent(parent[vertex], parent);
}
int main()
{
    int V, E;
    cin >> V >> E;

    graph *edge = new graph[E];
    for (int i = 0; i < E; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;

        edge[i].src = v1;
        edge[i].dest = v2;
        edge[i].wt = wt;
    }
    sort(edge, edge + E, comp);

    int *parent = new int[V];
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    vector<graph> mst;

    int count = 0;
    int index = 0;
    while (count < V - 1)
    {
        int srcparent = find_parent(edge[index].src, parent);
        int destparent = find_parent(edge[index].dest, parent);
        if (srcparent != destparent)
        {

            parent[srcparent] = destparent;
            mst.push_back(edge[index]);
            count++;
        }
        index++;
    }

    for (auto it : mst)
    {
        if (it.src < it.dest)
            cout << it.src << " " << it.dest << " " << it.wt << endl;
        else
            cout << it.dest << " " << it.src << " " << it.wt << endl;
    }

    delete[] edge;
    delete[] parent;
    return 0;
}
