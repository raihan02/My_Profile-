#include <bits/stdc++.h>
using namespace std;
#define mx 100005
int arr[mx];
int tree[mx * 3];
void init (int node , int b , int e);
int query(int node , int b , int e , int i , int j);
void update (int node , int b , int e , int i , int value);
int main()
{
    int tes , o = 0;
    scanf("%d", &tes);
    while(tes--)
    {
        o++;
        int q ,n;

        scanf("%d %d", &n , &q);
        for(int i = 0; i < n; i++)
        {
            scanf(" %d", &arr[i]);
        }
        init(1, 0 , n - 1);
         printf("Case %d:\n", o);
        while(q--)
        {
            int ck;
            scanf("%d", &ck);
            if(ck == 1)
            {
                int i;
                scanf("%d", &i);
                printf("%d\n", arr[i]);
                arr[i] = 0;
                update(1, 0 , n - 1 , i , arr[i]);
            }
            else if(ck == 2)
            {
               int v, i;
               scanf("%d %d", &i , &v);
               arr[i] += v;
               update(1 , 0 , n - 1 , i , arr[i]);
            }
            else
            {
                int i , j;
                scanf("%d %d", &i , &j);
                printf("%d\n", query(1, 0 , n - 1, i , j));
            }
        }

    }
}
void init(int node , int b , int e)
{
    if(b == e)
    {
        tree[node] = arr[b];
        return;
    }
    int l , m , r;
    l = node * 2;
    r = node * 2 + 1;
    m = (b + e )/ 2;
    init(l , b , m);
    init(r, m +1 , e);
    tree[node] = tree[l] + tree[r];
}
int query(int node,  int b , int e , int i , int j)
{
    if(i > e or j < b)
        return 0;
    if(b >= i && e <= j)
    {
        return tree[node];
    }
    int l ,m , r;
    l = node * 2;
    r = node * 2 + 1;
    m = (b + e) / 2;
    int x , y;
    x = query(l , b , m, i , j);
    y = query(r , m + 1 , e ,i , j);

    return x + y;

}
void update(int node , int b , int e, int i , int value)
{
    if(i > e or i < b){
        return;
    }
    if(b >= i && e <= i)
    {
        tree[node] = value;
        return;
    }
    int l , m , r;
    l = node * 2;
    r = node * 2 + 1;
    m = (b + e) / 2;
    update(l , b, m , i , value);
    update(r, m + 1, e, i , value);
    tree[node] = tree[l] + tree[r];
}
