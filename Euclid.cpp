///Euclid
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    int t;
    cin >> a >> b;

    while(b != 0)
    {
       t = b;
       b = a % b;
       a = t;
    }
    cout <<a << endl;

}
