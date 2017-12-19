#include <bits/stdc++.h>
using namespace std;
struct node
{
    int u, v, w;
    node(int a, int b, int c)
    {
        u = a;
        v = b;
        w = c;
    }
    bool operator < (const node& p) const
    {
        return w < p.w;
    }
};
vector <node> edge;
int par[10005];
int find (int u)
{
    if(u != par[u])
        par[u] = find(par[u]);

    return par[u];
}
int krush_kal (int n)
{
    sort(edge.begin(), edge.end());
    for(int i = 1; i <= n; i++)
    {
        par[i] = i;
    }
    int cnt = 0;
    int cost = 0;
    for(int i = 0; i < (int)edge.size(); i++)
    {
        int u , v;
        u = find(edge[i].u);
        v = find(edge[i].v);

        if(u != v)
        {
            cnt++;
            cost += edge[i].w;
            if(cnt == n - 1)
                break;
        }
    }
    return cost;
}
int main()
{
     int n, m;

     while(cin >> n >> m)
     {
         for(int i = 0; i < m; i++)
         {
             int u, v, w;
             cin >> u >> v >> w;
             edge.push_back(node(u, v, w));
         }
        cout<< krush_kal(n) << endl;
        edge.clear();
     }

}
