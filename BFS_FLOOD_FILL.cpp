#include <bits/stdc++.h>
#define inf 1<<30

using namespace std;
typedef pair <int, int> pi;
char maze[101][101];
int dist[101][101];
int reach[101][101];
int fx[]= {0,-1, 0,1};
int fy[]= {1, 0,-1,0};
int row ,col;

int bfs_flood_fill(int i , int j)
{
   reach[i][j] = 1;
   dist[i][j]  = 0;

   queue<pi> q;
   q.push(make_pair(i,j));
   while(!q.empty())
   {
       int a , b;

       a = q.front().first;
       b = q.front().second;
       q.pop();
       for(i = 0; i < 4; i++)
       {
           int x , y;
           x = a + fx[i];
           y = b + fy[i];

           if(x >= 0 and x < row and y >= 0 and y < col and maze[x][y] != 'm' and maze[x][y] != '#'and reach[x][y] == -1)
           {
               dist[x][y] = min(dist[a][b] + 1 , dist[x][y]);
               reach[x][y] = 1;
               q.push(make_pair(x,y));

           }
       }

   }

}
void setx ()
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j ++)
        {
            reach[i][j] = -1;
            dist[i][j] = inf;
        }
    }
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int tes, o =0;
   cin >> tes;

   while(tes--)
   {
       o++;
       cin >> row >> col;
       int x, y , a1 , a2 , b1 , b2, c1, c2;
       for(int i = 0; i < row; i++)
       {
           for(int j = 0; j < col; j++)
           {
               cin >> maze[i][j];
               if(maze[i][j] == 'h')
               {
                  x = i;
                  y = j;
               }
               if(maze[i][j] == 'a')
               {
                   a1 = i;
                   a2 = j;
               }
               if(maze[i][j] == 'b')
               {
                   b1 = i;
                   b2 = j;
               }
               if(maze[i][j] == 'c')
               {
                   c1 = i;
                   c2 = j;
               }
           }
       }
       setx();
       bfs_flood_fill(x,y);

      int mx = max(max(dist[a1][a2], dist[b1][b2]) , dist[c1][c2]);

      cout<<"Case "<< o << ": " << mx << endl;

   }


}
