/// Author: Mohd. Raihan Chowdhury
/// International Islamic University Chittagong
/// Strongly Connected Component
/// Source: http://www.shafaetsplanet.com/planetcoding/?p=2531
/// Video Source: https://www.youtube.com/watch?v=ko2STYDN-vM&t=507s
/// Happy Coding :)
#include <bits/stdc++.h>
using namespace std;

const int mx = 100005;
vector <int> g[mx]; /// main graph
vector <int> r[mx]; /// reverse graph
vector <int> top;
bool visit[mx];
int comp[mx];
int inDegree[mx];
vector <int> p[mx];
void init (int n)
{
    for(int i = 0; i < n; i++)
    {
        g[i].clear();
        r[i].clear();
        p[i].clear();
    }
    memset(visit,  false, sizeof visit);
    top.clear();
    memset(inDegree , 0, sizeof inDegree);
    memset(comp, 0, sizeof comp);
}
void dfs1(int u)
{
    visit[u] = true;
    for(int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if(visit[v] == false)
            dfs1(v);
    }
    top.push_back(u);
}
void dfs2(int u , int c)
{
   visit[u] = true;
   comp[u] = c;

   for(int i = 0; i < r[u].size(); i++)
   {
       int v = r[u][i];
       if(visit[v] == false)
       {
           dfs2(v, c);
       }
   }
}
int main()
{
    int n , e;
    while(cin >> n >> e)
    {
        init(n);
        for(int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            r[b].push_back(a); /// reverse

        }

        for(int i = 0; i < n; i++)
        {
            if(visit[i] == false)
                dfs1(i);
        }
        for(int i = 0 ;  i <= n; i++)
        {
            visit[i] = 0;
        }
        int cId = 0;
        /// component
        for(int i = top.size() - 1; i >= 0; i--)
        {
            if(visit[top[i]] == false)
            {
                dfs2(top[i] , ++cId);
            }
        }
        /// indegree calculate

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < g[i].size(); j++)
            {
                if(comp[i] != comp[g[i][j]])
                {
                    inDegree[comp[g[i][j]]]++;
                }
            }
        }


        /// printing component
        for(int i = 0; i < n; i++)
        {
            p[comp[i]].push_back(i);
        }

        for(int i = 1; i <= cId; i++)
        {
            printf("{ ");
            for(int j = 0; j < p[i].size(); j++)
            {
                printf("%d ", p[i][j]);
            }
            printf("}\n");
            printf("And its indegree = %d\n", inDegree[i]);
        }

    }
}
