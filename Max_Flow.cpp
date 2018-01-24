#include <bits/stdc++.h>
using namespace std;
vector < pair < int, int > > gg[103];
int arr[103][103];
int n, src, sink;
int par[105];
bool bfs ()
{
    bool visit[103];
    memset(visit, false, sizeof visit);

    stack <int> q;

    q.push(src);

    int ff;
    visit[src] = true;
    while(!q.empty())
    {
        ff = q.top();
        q.pop();

        for(int i = 0; i < gg[ff].size(); i++)
        {
            int xx = gg[ff][i].first;

            if(visit[xx] == false && arr[ff][xx] > 0)
            {
                visit[xx] = true;
                par[xx] = ff;
                q.push(xx);
            }
        }
    }

    return visit[sink] == 1;

}
int main()
{
    int m;
    int tes;

    memset(arr, 0, sizeof arr);
    cin >> n >> src >> sink >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        arr[a][b] += cost;
        arr[b][a] += cost;
        gg[a].push_back(make_pair(b, cost));
        gg[b].push_back(make_pair(a, cost));
    }
    /*
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    */
    int res = 0, flow;
    while(bfs())
    {
        cout<<"Yes" << endl;
        int p,k = sink;
        flow = 999999999;
        while(k != src)
        {
            p = par[k];
            flow = min(flow,arr[k][p]);
            k =par[k];
        }
        k = sink;
        while(k != src)
        {
            p = par[k];
            arr[k][p] -= flow;
            arr[p][k] -= flow;
            k = par[k];
        }

        res += flow;
    }
    cout<< res << endl;
}
/**
6 1 6 7
1 2 2
1 3 5
2 5 1
5 6 4
3 4 3
2 4 3
4 6 4
**/
