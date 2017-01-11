#include<bits/stdc++.h>
using namespace std;

#define ll          long long int
#define sf          scanf
#define pf          printf
#define F           first
#define S           second
#define pb          push_back
#define GCD(a, b)   __gcd(a, b)
#define LCM(a, b)   ((a*b)/GCD(a, b))

#define MOD         1000000007
#define M           10000
#define deb(x) cerr << #x << " = " << x << endl;
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p )
{
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v )
{
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ )
    {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v )
{
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ )
    {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v )
{
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ )
    {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}


#define deb(x) cerr << #x << " = " << x << endl;
#define visited 1
#define unvisited -1
typedef pair<int ,int> pi;
typedef vector <pi> vc;
int arr[100005];
vc node[100005];
priority_queue <pi> pq;

template<class T>

inline bool fs(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}
