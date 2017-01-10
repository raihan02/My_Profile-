#include <bits/stdc++.h>
#define sc(n) scanf("%d", &n);
#define pb push_back
#define in 999999
using namespace std;
typedef pair <int, int> ii;
typedef vector <ii> vc;
vc v[1005];
int dist[1005];
void dijkastra (int src)
{
   dist[src] = 0;
   priority_queue <ii, vector<ii> , greater <ii> > pq;
   pq.push(make_pair(0, src));
   while(!pq.empty())
   {
       int d = pq.top().first;
       int u = pq.top().second;
       pq.pop();
       if(d > dist[u])
        continue;
       for(int i = 0; i < v[u].size(); i++)
       {
           ii x = v[u][i];
           if(dist[u] + x.second < dist[x.first])
           {
               dist[x.first] = dist[u] + x.second;
               pq.push(make_pair(dist[x.first], x.first));
           }
       }

   }

}
int main()
{
    int n , m;
     memset(dist, in , sizeof dist);
     printf("%d\n", dist[5]);
    sc(n);
    sc(m);


    for(int i = 0; i < m; i++)
    {
        int a, b, cost;
        sc(a);
        sc(b);
        sc(cost);
        v[a].pb(make_pair(b, cost));
    }
      dijkastra(1);
        for(int i = 1; i <= n; i++)
        printf("%d ", dist[i]);

  /**
   input
   5 6 
   1 2 1
   2 5 6
   2 3 2
   3 5 1
   3 4 1
   1 4 9
   
   source(1)
   output
   0 1 3 4 4
    
  **/


}
