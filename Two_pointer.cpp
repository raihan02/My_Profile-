#include <bits/stdc++.h>
using namespace std;
int main()
{
   int A[100], B[100];
   int n,m;
   cin >> n >> m;
   for(int i = 0; i < n; i++)
   {
       cin >> A[i];
   }

   for(int i = 0; i < n; i++)
   {
       cin >> B[i];
   }
   sort(A,A+n);
   sort(B, B+n);
   int low = 0 , high = n-1;
   int cnt = 0;
   while(low < n)
   {
       while(A[low] + B[high] > m && high > 0)
        high--;

       if(A[low] + B[high] == m)
        cnt++;
       low++;
   }

   cout<<cnt<< endl;
}
