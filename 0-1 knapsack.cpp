#include <bits/stdc++.h>
using namespace std;
int dp[20][20];
int val[6] = {1,4,5,7};
int wt[5] = {1,3,4,5};

int ks (int j , int cap)
{
   int i;

   for(i = 0; i <= j; i++)
   {
       for(int w = 0; w <= cap; w++)
       {
           if(i == 0 || w ==0 )
           {
               dp[i][w] = 0;
           }
           if(w < wt[i])
           {
               dp[i][w] = dp[i - 1][w];
           }
           else
           {
               dp[i][w] = max(val[i] + dp[i - 1][w - wt[i]] , dp[i -1][w]);
           }
       }
   }
}
void print(int j , int cap)
{
    for(int i = 0; i < j; i++)
    {
        for(int w = 0; w <= cap; w++)
        {
            printf("%d ", dp[i][w]);
        }
        printf("\n");
    }
}
int main()
{
    ks(4, 7);

    print(4, 7);
}
