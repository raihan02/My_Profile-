#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll x,y, d;
void ex_euclid(ll a, ll b){
    if(b == 0){
        x = 1;
        y = 0;
        d = a;
        return;
    }
    ex_euclid(b, a % b);
    ll x1, y1;
    x1 = y;
    y1 = x - a/b*y;
    x = x1;
    y = y1;
}
int main()
{
    ll a, b;

    while(cin >> a >> b)
    {
       ex_euclid(a,b);
       printf("%lld %lld %lld\n",x,y,d);
    }
}
