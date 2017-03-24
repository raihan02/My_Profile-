#include <bits/stdc++.h>
using namespace std;
#define mem(x,y) memset(x, y, sizeof(x))
#define inf 1<<28
#define pb push_back
#define fin(prob) freopen("prob.in", "r", stdin)
#define fout(prob) freopen("prob.out", "w", stdout)
#define si(a) int a; scanf("%d", &a);
#define sll(a) ll a; scanf("%lld", &a);
#define sllu(a) unsigned ll a; scanf("%llu", &a);
#define sd(a) double a; scanf("%lf", &a);
#define deb(x) cerr<< #x <<"="<<x<<endl;
#define debug cout<<"Love you" << endl
const double pi=2*acos(0);
typedef string st;
typedef vector <int> vi;
typedef vector <string> vs;
typedef pair <int, int> ii;
typedef long long ll;
typedef vector < pair <int, int> > vii;
typedef priority_queue<int,vector<int>,greater<int> > min_heap;
bool pali(string temp, int i, int j)
{
    if(i>=j) return true;
    if(temp[i]==temp[j]) return pali(temp, i+1, j-1);
    return false;
}
template <class T> inline T gcd(T a, T b)
{
    if(a<0) return gcd(-a, b);
    if(b<0) return gcd(a,-b);
    return (b==0) ? a : gcd(b, a%b);
}
template <typename F, typename S> ostream &operator << (ostream & os, const map<F,S>&v)
{
    os<<"[";
    typename map<F,S>::const_iterator it;

    for(it=v.begin(); it!=v.end(); it++)
    {
        if(it != v.begin()) os<<",";
        os<< it ->first<<"="<<it->second;
    }
    return os<<"]";
}
int arr[101][101];
int next[101][101];
vector <int> path;
void build ()
{
    for(int i = 1; i <= 101; i++)
    {
        for(int j = 1; j <= 101; j++)
        {
            if(i == j)
                arr[i][j] = 0;
            arr[i][j] = inf;
        }
    }
}
void floyd(int n)
{
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(arr[i][j] > arr[i][k] + arr[k][j]){
                arr[i][j] =  (arr[i][j] ||(arr[i][k] && arr[k][j]));

                }
            }
        }
    }
}
void find_path(int i , int j)
{

   while(i != j)
   {
       printf("%d ", i);
        i = next[i][j];
   }
   printf("\n");
}
int main()
{
    build();
    si(node);
    si(edge);

    for(int i = 1; i <= edge; i++)
    {
        // int a, b, cost;
        si(a);
        si(b);
        arr[a][b] = 1;

    }
    floyd(node);

   for(int i = 1; i <= node; i++)
       {
           for(int j = 1; j <= node; j++)
           {
               if(arr[i][j] == inf)
               {
                   printf("0 ");
                   continue;
               }
               printf("%d ", arr[i][j]);
           }
           printf("\n");
       }
}

/*
 4 5
 1 2
 1 3
 3 4
 3 2
 2 4
*/
