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
int main()
{
    
}
