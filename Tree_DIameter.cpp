#include <bits/stdc++.h>
using namespace std;
typedef pair<int , int> pi;
typedef vector<pi> vc;
#define inf 1061109567
vc vertex[30005];
int dist[30005];
int tree_diameter (int src , int n)
{

    memset(dist, inf , sizeof dist);
    dist[src] = 0;
    queue<int> q;
    q.push(src);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i = 0; i < vertex[u].size(); i++)
        {
            int v , cost;
            v = vertex[u][i].first;
            cost =  vertex[u][i].second;

            if(dist[v] > dist[u] + cost)
            {
                dist[v] = dist[u] + cost;
                q.push(v);
            }
        }

    }
    int res = 0, pos = 0;
    for(int i = 0; i < n; i++)
    {
        if(dist[i] > res)
        {
            res = dist[i];
            pos = i;
        }
    }

    return pos;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tes , o = 0;
    cin >> tes;
    while(tes--)
    {
        o++;
        int n;
        cin >> n;

        for(int i = 0; i < n - 1; i++)
        {
            int a, b , cost;
            cin >> a >> b >> cost;
            vertex[a].push_back(make_pair(b , cost));
            vertex[b].push_back(make_pair(a , cost));
        }
        int f_cost = tree_diameter(0 , n);
        int s_cost = tree_diameter(f_cost , n);

        printf("Case %d: %d\n", o, dist[s_cost]);

        for(int i = 0; i < n; i++)
        {
            vertex[i].clear();
        }
    }
}
