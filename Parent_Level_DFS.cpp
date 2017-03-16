#include <bits/stdc++.h>
using namespace std;
vector <int> node[101];
#define pb push_back
int L[100];
int T[100];
void dfs(int from , int u , int dep)
{
    T[u] = from;
    L[u] = dep;

    for(int i = 0; i < node[u].size(); i++)
    {
        int v = node[u][i];
        if(v == from)
            continue;
        dfs(u, v, dep + 1);
    }
}
int main()
{

   node[0].pb(1);
   node[0].pb(2);
   node[1].pb(4);
   node[1].pb(3);
   dfs(0,0,0);
   for(int i = 0; i <= 4; i++)
   {
       printf("%d %d\n",T[i], L[i]);
   }

  return 0;
}
