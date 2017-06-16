#include <bits/stdc++.h>
using namespace std;
long dp[40][20];
void clr1()
{
    for(int i = 0; i < 40; i++)
        for(int j = 0; j < 20; j++)
           dp[i][j] = -1;
}
int b_c (int n, int r)
{
    if(n == r || r == 0)
        return 1;
    if(dp[n][r] != -1)
        return dp[n][r];
    else
    {
        dp[n][r] = b_c(n -1, r - 1) + b_c(n - 1, r);
        return dp[n][r];
    }
}
int main()
{
     clr1();

     int n, r;
     while(cin >> n >> r)
     {
         cout<<b_c(n, r) << endl;
     }
}
