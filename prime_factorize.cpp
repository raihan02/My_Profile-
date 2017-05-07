#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int prime[3000000] , nPrime;
int mark[10000002];
int factor[300];
int ck;
void sieve(int n)
{
    int i , j , limit = sqrt(n * 1.) + 2;
    mark[1] = 1;
    for(int i = 4; i <= n; i += 2)
        mark[i] = 1;
    prime[nPrime++] = 2;
 
    for(i = 3; i <= n; i++)
    {
        if(mark[i] == 0)
        {
            prime[nPrime++] = i;
            if(i <= limit)
            {
                for(j = i * i; j <= n; j+= i * 2)
                {
                    mark[j] = 1;
                }
            }
        }
    }
}
void prime_factor (int n)
{
    ck = 0;
    for(int i = 0; prime[i] <= sqrt(n); i++)
    {
        while(n % prime[i] == 0)
        {
           factor[ck++] = prime[i];
            n = n / prime[i];
        }
    }
    if(n > 1)
    {
        factor[ck++] = n;
    }
}
int main()
{
    sieve(100);
    int n;
    while(cin >> n)
    {
        prime_factor(n);
        for(int i = 0; i < ck; i++)
        {
            printf("%d ", factor[i]);
        }
        printf("\n");
    }
}
