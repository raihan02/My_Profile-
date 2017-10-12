#include <bits/stdc++.h>
using namespace std;
int mat[4][4]  =  { {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
    };

int rat[4][4] ={0};
bool safe (int x, int y)
{
    if(x >= 0 && x < 4 && y >= 0 && y < 4 && mat[x][y] == 1)
        return true;
    return false;
}
bool solve(int x, int y)
{
    if(x == 3 && y == 3){
        rat[x][y] = 1;
        return true;
    }

    if(safe(x, y) == true)
    {
         rat[x][y] = 1;
        if(solve(x + 1, y) == true)
            return true;
        if(solve(x, y + 1 ) == true)
            return true;

        rat[x][y] = 0;
        //return false;
    }
    //return false;

}
int main()
{

    solve(0,0);

    for(int i = 0;i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%d ", rat[i][j]);
        }
        printf("\n");
    }
}
