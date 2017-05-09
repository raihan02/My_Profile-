#include <bits/stdc++.h>
using namespace std;
double soln (double x)
{
   double low = 0.0 , high = x , mid;
   while(high -low > .0001)
   {
       mid = (high + low) / 2;

       if(mid * mid > x)
       {
           high = mid;
       }
       else
       {
           low = mid;
       }
   }
   cout<<mid * mid << endl;
   return mid;
}
int main()
{
    double x1, x2, x0, f0, f1, f2, f3;

    while(cin >> x1)
    {
        double res = soln(x1);
        cout<< res << endl;
    }
}
