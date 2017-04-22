#include <bits/stdc++.h>
using namespace std;
int arr[1001] , lis[1001];
int mx;
void LIS (int n)
{
    for(int i = 0; i <= n; i++)
    {
        lis[i] = 1;
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i] > arr[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
            }
        }
    }


    for(int i = 0; i < n; i++)
    {
        if(mx < lis[i])
            mx =lis[i];
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    mx = -1;
    LIS(n);
    printf("%d\n",mx);
}
