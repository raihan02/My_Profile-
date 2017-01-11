#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
#define mem(a , b) memset(a , b , sizeof(a))
int in[1005];
vector <int> vertex[1005];
int main()
{
   int n , m;

   while(cin >> n >> m)
   {
       mem(in , 0);
       for(int i = 1; i <= m; i++)
       {
           int x , y;
           cin >> x >> y;
           vertex[x].push_back(y);
           in[y]++;
       }
       queue<int> q;
       for(int i = 1; i <= n; i++)
       {
           if(in[i] == 0)
           q.push(i);

       }
       vector <int> vc;
       while(!q.empty())
       {
           int u = q.front();
           vc.push_back(u);
           q.pop();
           for(int i = 0; i < vertex[u].size(); i++)
           {
               int v = vertex[u][i];
               in[v]--;
               if(in[v] == 0)
               {
                   q.push(v);
               }
           }
       }
       for(int i = 0; i < vc.size() - 1; i ++)
        printf("%d ", vc[i]);
       printf("%d\n", vc[vc.size() - 1]);
      vc.clear();
      for(int i = 1; i <= n; i++)
       vertex[i].clear();
   }
}
