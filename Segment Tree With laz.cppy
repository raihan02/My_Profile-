#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll arr[100005];
struct info
{
    ll sum , prop;
}tree[100005 * 3];
void update (ll node , ll b , ll e , ll i , ll j , ll x)
{

    if (i > e || j < b)
        return;
    if (b >= i && e <= j)
    {
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x;
        return;
    }
    ll l = node * 2;
    ll r = (node * 2) + 1;
    ll mid = (b + e) / 2;
    update(l, b, mid, i, j, x);
    update(r, mid + 1, e, i, j, x);
    tree[node].sum = tree[l].sum + tree[r].sum + (e - b + 1) * tree[node].prop;
}
ll Q (ll node, ll b , ll e , ll i , ll j , ll carry = 0)
{

    if(i > e or j < b)
    {
        return 0;
    }
    if(b >= i && e <= j)
    {
        return tree[node].sum + carry * ((e - b + 1));
    }
    ll mid , l , r;
    l = node * 2;
    r = node * 2+ 1;
    mid = (b + e) / 2;
    ll x = Q(l ,b , mid, i, j,carry+ tree[node].prop);
    ll y = Q(r ,mid + 1 , e, i , j,carry+ tree[node].prop);
    return x + y;
}
int main()
{
   ll n  , q;
   int tes , o = 0;
   scanf(" %d", &tes);
   while(tes--)
   {
       o++;
      memset(tree, 0 , sizeof tree);
       scanf(" %lld %lld" ,&n , &q);
       printf("Case %d:\n",o);
       while(q--)
       {
           int ck;
           ll i ,j , vl;
           scanf(" %d", &ck);
           if(ck == 0)
           {
               scanf("%lld %lld %lld", &i , &j , &vl);
                i++;
                j++;

               update(1 , 1 , n, i, j, vl);
           }
           else if(ck == 1)
           {

               scanf("%lld %lld", &i , &j);
                i++;
                j++;
               ll sum = Q(1 , 1 , n, i, j );

               printf("%lld\n", sum);
           }
       }
   }

}
