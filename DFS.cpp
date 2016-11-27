#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int dis[10001];
vector <int> node[1001];
vector <int> vc;
void dfs(int u)
{
    int v;
    dis[u] = 1;
    for(int i = 0; i < node[u].size(); i++)
    {
        v = node[u][i];
        if(dis[v] == -1)
        {
            dfs(v);
        }

    }
    vc.push_back(v);

}
int main()
{
  int n , m;
  while(cin >> n >> m)
  {
      memset(dis, -1 ,sizeof dis);
      for(int i = 0; i < m ;i++)
      {
          int a, b;
          cin >> a >> b;
          node[a].pb(b);
          node[b].pb(a);
      }
      int c = 0;
      for(int i = 1; i <= n; i++)
      {
          if(dis[i] == -1)
          {
              dfs(i);
              c++;
          }
      }
      cout<<c<< endl;
  }

}
