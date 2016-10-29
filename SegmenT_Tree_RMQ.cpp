#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define mx 100005
int arr[mx];
int tree[mx * 3];
void init (int node , int b , int e)
{
    if(b == e)
    {
        tree[node] = arr[b];
        return;
    }
    int right , left , mid;
    left = node * 2;
    right = node * 2 + 1;
    mid = (b + e) / 2;
    init(left , b , mid);
    init(right , mid +1 , e);
    tree[node] = min(tree[left] , tree[right]);
}
int query (int node , int b , int e, int i , int j)
{
    if(i > e or j < b)
        return mx;


    if(b >= i and e <= j)
    {
        return tree[node];
    }

    int left , right , mid;
    left = node * 2;
    right = node * 2 + 1;
    mid = (b + e) / 2;
    int x = query(left , b , mid , i , j);
    int y = query(right , mid + 1, e , i , j);

    return min(x , y);
}
int main()
{
   int tes , o = 0;
   scanf("%d", &tes);
   while(tes--)
   {
       o++;
       int n , q;
       scanf("%d", &n);
       scanf("%d", &q);

       for(int i = 1; i <= n; i++)
       {
           scanf("%d", &arr[i]);
       }
       printf("Case %d:\n",o);
       init(1, 1, n);
       while(q--)
       {
           int x,  y;
           scanf("%d %d", &x, &y);
           printf("%d\n",query(1 , 1 , n , x,  y));
       }
   }
}
