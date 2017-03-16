#include <bits/stdc++.h>
using namespace std;
vector <int> node[101];
#define pb push_back
int L[100];
int T[100];
int P[101][22];
void dfs(int from, int u, int dep)
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
int lca_query (int N, int p, int q)  // N= Number of vertex
{
    int tmp, log,i;
    if(L[p] < L[q])
    {
        tmp = p;
        p = q;
        q =tmp;
    }
    log = 1;
    while(1)
    {
        int next = log + 1;
        if((1<<next)>L[p])
            break;
        log++;
    }
    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])
            p = P[p][i];

    if (p == q)
        return p;

    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];

    return T[p];
}
void lca_init(int N)
  {
      memset (P,-1,sizeof(P));
      int i, j;
       for (i = 0; i < N; i++)
          P[i][0] = T[i];

      for (j = 1; 1 << j < N; j++)
         for (i = 0; i < N; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];
 }
int main()
{

  node[0].pb(1);
  
	node[0].pb(2);
	node[2].pb(3);
	node[2].pb(4);
	dfs(0, 0, 0);
	lca_init(5);
	printf( "%d\n", lca_query(5,1,3));
	return 0;
}
