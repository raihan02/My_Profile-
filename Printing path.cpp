#include <bits/stdc++.h>
using namespace std;
vector <int> v[1000];
int dis[1002];
vector <pair <int,  string> > vc;
#define pb push_back
void bfs (int src , int e)
{
    dis[src] = 0;
    queue <int> q;
    q.push(src);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i =0 ; i < v[u].size(); i++)
        {
            int vx = v[u][i];
            if(dis[vx] == -1)
            {
                dis[vx] = u; /// printing path
                q.push(vx);
                if(dis[vx] == e)
                return;

            }
        }
    }
}
int main()
{
   int m , q;
   int tes;
   scanf("%d", &tes);
   while(tes--){
   scanf(" %d %d", &m ,&q);


       string s1, s2;
       int in = 0;
       for(int i = 0; i <= 100; i++)
        v[i].clear();
       for(int i = 0; i < m; i++)
       {
           cin >> s1 >> s2;
            int x, y;
            x = s1[0] - 64;
            y = s2[0] - 64;
            v[x].pb(y);
            v[y].pb(x);

       }

       while(q--)
       {
           cin >> s1 >> s2;
          memset(dis , -1, sizeof dis);

         int a, b;
         a = s1[0] - 64;
         b = s2[0] - 64;
         bfs(b , a);
         printf("%c",s1[0]);
         while(a != b)
         {
             printf("%c", dis[a] + 64); /// printing path
             a = dis[a];
         }
         printf("\n");

       }
       if(tes > 0)
        printf("\n");


   }
}
