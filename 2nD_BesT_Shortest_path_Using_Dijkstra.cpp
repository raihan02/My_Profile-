#include <bits/stdc++.h>
using namespace std;
#define mx 5005
typedef long long int ll;
#define inf 1e18
struct e
{
    int to , w;
    e(){}
    e(int a, int b)
    {
        to = a;
        w = b;
    }
};
struct s
{
    int city , cost;
    s(){}
    s(int a, int b)
    {
        city = a;
        cost= b;
    }
    bool operator < (const s &p) const
    {
        return p.cost < cost;
    }
};
vector <e > vertex[mx];
vector <ll> dis[mx];
void dijkstra (int src , int n)
{
    priority_queue <s> pq;
    int u , v , w;
    pq.push(s(src, 0));
    while(!pq.empty())
    {
         s current = pq.top();
         u = current.city;
         w = current.cost;
        pq.pop();
        if(dis[u].size() == 0)
            dis[u].push_back(w);
        else if(dis[u].back() != w)
        {
            dis[u].push_back(w);
        }
        if(dis[u].size() > 2)
            continue;
            for(int i = 0; i < vertex[u].size(); i++)
            {
                e n = vertex[u][i];
                v = n.to;
                if(dis[v].size() == 2)
                    continue;
                int ds = n.w + current.cost;
                pq.push(s(v, ds));
            }

    }
    printf("%lld\n", dis[n][1]);
}
int main()
{
    int tes,o=0;
    scanf(" %d", &tes);
    while(tes--)
    {
        o++;
        int n, ex;
        scanf("%d %d", &n , &ex);
        for(int i = 0; i < ex; i++)
        {
            int a, b , cst;
            scanf("%d %d %d", &a, &b, &cst);
            vertex[a].push_back(e(b, cst));
             vertex[b].push_back(e(a, cst));
        }
        printf("Case %d: ",o);
        dijkstra(1, n);
        vector <e> t1[mx];
        vector<ll> dp[mx];
        swap(dp, dis);
        swap(t1, vertex);

    }

}
