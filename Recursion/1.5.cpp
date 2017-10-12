//GCD
#include <bits/stdc++.h>
using namespace std;
int gcd (int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main()
{
   int n, m;
   while(cin >> n >> m)
   {
       cout<< gcd(n, m)<< endl;
   }
}
