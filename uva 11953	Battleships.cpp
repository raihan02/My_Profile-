#include <bits/stdc++.h>
using namespace std;
//int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; /// move up down && corner /// If we want only move in up and down , thne
//int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; /// UVA problem samle (Oil deposite )


int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};
char maze[101][101];
int n;
int r[101][101];
void dfs (int x, int y)
{
    r[x][y] = 1;

    for(int i = 0; i < 4; i++)
    {
        int a, b;
        a = x + fx[i];
        b = y + fy[i];

        if(maze[a][b] == '@')
            maze[a][b] = 'x';

        if( a >= 0 && a < n && b >= 0 && b < n && r[a][b] == 0)
        {
            r[a][b] = 1;
            if(maze[a][b] == 'x')
            {
                dfs(a , b);
            }
        }
    }
}
int main()
{
       int tes,o=0;
       cin >> tes;

      //freopen("raju.txt", "w+", stdout);

       while(tes--){
            o++;
            cin >> n;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> maze[i][j];
            }
        }
        memset(r , 0, sizeof r);
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(r[i][j] == 0)
                {
                    if(maze[i][j] == 'x')
                    {
                        dfs(i , j);
                        cnt++;
                    }
                }
            }
        }
        printf("Case %d: %d\n", o, cnt);
       }

}
