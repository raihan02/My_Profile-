#include <bits/stdc++.h>
using namespace std;
#define V 102
int graph[V][V];
int parent[V];
int rGraph[V][V];
bool bfs(int s, int t)
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v=0; v<V; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return (visited[t] == true);
}

int fordFulkerson(int s, int t)
{
    int u, v;
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             rGraph[u][v] = graph[u][v];



    int max_flow = 0;
    while (bfs(s,t))
    {

        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }


        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main()
{
   int n, m, s, t;
   int tes;

   cin >> n >> s >> t >> m;
   memset(graph, 0, sizeof graph);
   for(int i = 0; i < m; i++)
   {
       int a, b, w;
       cin >> a >> b >> w;
       graph[a][b] += w;
       //graph[b][a] += w;

   }

   cout<<fordFulkerson(s,t)<< endl;

}
/**
6 1 6 7
1 2 2
1 3 5
2 5 1
5 6 4
3 4 3
2 4 3
4 6 4
**/
