/*
Write a recursive program to determine whether a given integer is prime or not.
*/
#include <bits/stdc++.h>
using namespace std;
int solve (int i , int n)
{
    if(i <= sqrt(n))
    {
        if(n % i == 0)
            return true;
        solve(i + 1, n);
    }
    return false;

}
int main()
{
   int n;
   while(cin >> n)
   {
       if(solve(2, n) == true)
        printf("Not prime\n");
       else
        printf("Prime\n");
   }
}
