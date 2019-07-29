#include <bits/stdc++.h>
using namespace std;
bool bisection(double x)
{
    double low = 0.00,mid , high = x;

    for(int i = 1; i <= 64; i++)
    {
        mid = (high+low) / 2.0;

        if(mid*mid > x)
            high = mid;
        else
            low = mid;
    }

    cout<< mid << " " << mid * mid << endl;
}
int main()
{
    bisection(15);
}
