#include <bits/stdc++.h>
using namespace std;
int U[10001], V[10001] , W[10001];
int dist[10001];
 int node , edge;
bool bell_man(int src)
{
    dist[src] = 0;

    bool negative_cycle = false;
    for (int step = 1; step <= node; step++)
    {
         bool update = false;
        for(int i = 1; i <= edge; i++)
        {
            int u = U[i];
            int v = V[i];
            if(dist[v] > dist[u] + W[i])
            {
                update = true;
                dist[v] = dist[u] + W[i];
                if(step == node)
                    negative_cycle = true;
            }
        }
        if(update == false)
        {
            return false;
        }

    }
    return negative_cycle;

}
int main()
{

   memset(dist, 100, sizeof dist);
   cout<< dist[10]<< endl;
    cin >> node >> edge;

    for(int i = 1; i <= edge; i++)
    {
        cin >> U[i] >> V[i] >> W[i];
    }
    bool x = bell_man(1);
    if(x == 0)
    {
        for(int i = 1; i <= node; i++)
        {
            cout<< dist[i] << endl;
        }
    }
    else
    {
        cout<<"Negative Cycle" << endl;
    }
}
