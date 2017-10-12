/*Write a recursive solution to print the polynomial series for any input n:
1 + x + x2 + ................. + xn-1
*/
#include <bits/stdc++.h>
using namespace std;
void solve (int i , int n)
{
   if(i < n)
   {
       if(i == 0)
        printf("1");
       else
       {
           printf("+x");
           if(i > 1)
            printf("^%d",i);
       }
       solve(i + 1,n);
   }
}
int main()
{
    solve(0,5);
}
