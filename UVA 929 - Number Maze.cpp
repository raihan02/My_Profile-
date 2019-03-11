#include <bits/stdc++.h>
#define sc(n) scanf("%d", &n);
#define pb push_back
#define in 99999999

using namespace std;
int reach[1001][1001];
int row,col;
typedef pair <int, pair <int, int> > ii;

int dist[1005][1005];
int fx[]= {0,-1, 0,1};
int fy[]= {1, 0,-1,0};
int maze[1005][1005];
void dijkastra (int a, int b)
{

    priority_queue <ii, vector<ii>, greater <ii> > pq;
    dist[a][b] = maze[a][b];
    pq.push(make_pair(maze[a][b],make_pair(a,b)));
    while(!pq.empty())
    {
        int d = pq.top().first;
        int u, v,x,y,cost;
        u = pq.top().second.first;
        v = pq.top().second.second;
        pq.pop();

        for(int i = 0; i < 4; i++)
        {

            x = u + fx[i];
            y = v + fy[i];
            cost = maze[x][y];
            if(x >= 0 and x < row and y >= 0 and y < col)
            {
                if(dist[u][v] + cost < dist[x][y])
                {
                    dist[x][y] = dist[u][v] + cost;
                    pq.push(make_pair(dist[x][y], make_pair(x,y)));

                }
            }
        }

    }

}

int main()
{
    int tes;
    cin >> tes;
    while(tes--)
    {
        cin >> row >> col;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                cin >> maze[i][j];
                dist[i][j] = in;
            }
        }
        dijkastra(0,0);
        cout<< dist[row-1][col-1]<< endl;
    }
}
