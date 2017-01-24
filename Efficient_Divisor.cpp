#include <bits/stdc++.h>
using namespace std;
int divisor[10001];

int main()
{
    int n;
    while(cin >>n)
    {
        int c = 0;
        vector <int> vs;
        for(int i = 1; i <= sqrt(n); i++)
        {
            if(n % i == 0)
            {

                vs.push_back(i);
                if(n / i == i)
                    continue;
                vs.push_back(n/i);
            }
        }
      for(int i = 0; i <vs.size(); i++)
        printf("%d ", vs[i]);
    }
}
