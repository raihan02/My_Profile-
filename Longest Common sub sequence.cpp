#include <bits/stdc++.h>
using namespace std;
int pr[1005][1005], dp[1005][1005];
string x, y;

int lcs (int m, int n)
{
   for(int i = 1; i <= m; i++)
        dp[i][0] = 0;
    for(int j = 0; j <= n; j++)
        dp[0][j] = 0;
   for(int i = 1; i <= m; i++)
   {
       for(int j = 1; j <= n; j++)
       {
           if(x[i-1] == y[j - 1])
           {
               dp[i][j] = dp[i - 1][j - 1] + 1;
               pr[i][j] = 1;
           }
           else if(dp[i - 1][j] >= dp[i][j - 1])
           {
               dp[i][j] = dp[i - 1][j];
               pr[i][j] = 2;
           }
           else
           {
               dp[i][j] = dp[i][j - 1];
               pr[i][j] = 3;
           }
       }
   }

   return dp[m][n];
}

int main()
{
    while(getline(cin,x ))
    {
        getline(cin, y);
        memset(dp,0,sizeof dp);
        int m = x.size(), n = y.size();
       int ans  = lcs(m,n);

       cout<< ans << endl;
        /*
        for(int i = 0; i <= m; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                cout<< dp[i][j] << " ";
            }
            cout<< endl;
        }
        */

    }
}
