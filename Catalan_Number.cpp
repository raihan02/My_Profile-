/// Mohd. Raihan Chowdhury 
/// International Islamic University Chittagong
/// Topic: Catalan number( counting the number of possible binary search with keys)
/// Source: https://www.youtube.com/watch?v=2NZF2UKyh0g
/** 
            (2n) !
      cn = --------------
           (n +1)! * n !
 **/
/// Happy Coding :) 
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll cat[1000006];
void catalan (ll n)
{
    cat[0] = cat[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        cat[i] = 0;
        for(int j = 0; j < i; j++)
        {
            cat[i] += cat[j] * cat[i - j - 1];
        }
    }
    //return cat[n];
}
int main()
{
    catalan(10000);
    ll n;
    while(cin >> n)
    {
        cout<<cat[n]<< endl;
    }

}

/// Another Approach

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int fact[100];
void catalan ()
{
    fact[0] = 1;
    for(int i = 1; i <= 10; i++)
    {
        fact[i] = fact[i - 1] * i;
    }
}
int main()
{
    catalan();
    int n;
    while(cin >> n)
    {
       // printf("%d\n", fact[n]);
        printf("%d\n", fact[2 * n] / (fact[n + 1] * fact[n])); /// 
        
      /** 
            (2n) !
      cn = --------------
           (n +1)! * n !
      **/
        
                                                                     
    }

}
