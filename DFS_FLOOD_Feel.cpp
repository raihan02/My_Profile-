#include <bits/stdc++.h>
using namespace std;
int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; /// move up down && corner /// If we want only move in up and down , thne 
int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; /// UVA problem samle (Oil deposite )
int row , col; 
/*
for up down right left
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};
*/char maze[101][101];
int r[101][101];
void dfs (int x, int y)
{
    r[x][y] = 1;

    for(int i = 0; i < 8; i++)
    {
        int a, b;
        a = x + fx[i];
        b = y + fy[i];

        if( a >= 0 && a < row && b >= 0 && b < col && r[a][b] == 0)
        {
            r[a][b] = 1;
            if(maze[a][b] == '@')
            {
                dfs(a , b);
            }
        }
    }
}
int main()
{
    while(cin >> row >> col)
    {
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                cin >> maze[i][j];
            }
        }
        memset(r , 0, sizeof r);
        int cnt = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(r[i][j] == 0)
                {
                    if(maze[i][j] == '@')
                    {
                        dfs(i , j);
                        cnt++;
                    }
                }
            }
        }
        cout<< cnt << endl;
    }
}
