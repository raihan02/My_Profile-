#include <bits/stdc++.h>
using namespace std;
int parent[1005] , ran[1005] , find_group[1005];
void built (int n)
{
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
       ran[i] = 0;
    }
}
bool myfn(int i, int j) { return i<j; }
int make_friend (int n)
{
    if(parent[n] == n) return n;
    else return parent[n] = make_friend(parent[n]);
}
void make_union(int a , int b)
{
     if(ran[a] > ran[b])
    {
       parent[b] = a  ;
    }
    else
    {
       parent[a] = b ;
        if(ran[a] == ran[b])
            ran[b]++ ;
    }
}
int main()
{
    int m , n;
    cin >> n >> m;
    built(n);
     for(int i = 0 ; i < m; i++)
        {
            int a, b;
            cin>>a>>b;
            int pa = make_friend(a);
            int pb = make_friend(b);

            if(pa != pb)
            {
                make_union(pa, pb);
            }
        }

    for(int i = 1; i <= n; i++)
        printf("%d ",parent[i]);
    printf("\n");
    for(int i = 1; i <= n; i++)
        printf("%d ",ran[i] );
    printf("\n");
}
