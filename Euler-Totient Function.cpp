/// Phi(n) = n * (1 - 1/p1) (1 - 1/p2) .. (1 - 1/pk) 
#include <bits/stdc++.h>
using namespace std;
int phi[1000006] , mark[10000006];
void Euler_Totient(int n)
{
    for(int i = 1; i <= n; i++)
    {
        phi[i] = i;
    }
    phi[1] =1;
    mark[1]=1;
    for(int i = 2; i <= n; i++)
    {
        if(!mark[i]) // if i is prime 
        {
            for(int j = i; j <= n; j += i)
            {
                mark[j] = 1;
                ///phi[j] is divisable by i
               
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}
int main()
{
    Euler_Totient(9);

    cout<<phi[9]<< endl;
}
