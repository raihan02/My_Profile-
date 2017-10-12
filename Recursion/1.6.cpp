// Max element of ana array 
#include <bits/stdc++.h>
using namespace std;
int arr[100];
int mx (int i, int n)
{
   if(i == n - 1)
   {
       return arr[i];
   }
   int m = mx(i + 1, n);
   if(m < arr[i])
    return arr[i];
   else
    return m;

}
int main()
{
   int n;
   cin >> n;
   for(int i = 0; i < n; i++)
    cin >> arr[i];

  int x  =mx(0,n);

   cout<<x<< endl;
}
