#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int ncr (int n , int r)
{
    if(r == n)
        return 1;
    if(r == 1)
        return n;
        if(dp[n][r] != -1)
            return dp[n][r];
     return dp[n][r] = ncr(n -1, r)+ ncr(n - 1 , r - 1);

}
int main()
{
    int n , r;
    while(cin >> n >> r)
    {
        memset(dp, -1, sizeof dp);
        cout<< ncr(n, r) << endl;
    }
}
