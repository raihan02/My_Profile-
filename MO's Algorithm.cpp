/**
  Topic Name: Mo's Algorithm
  Name: Mohd. Raihan Uddin
  iOS Developer at Twinbit limited
**/
#include <bits/stdc++.h>
using namespace std;
const int Max = 1000006;
int k, arr[Max], ans[Max], sum = 0;

struct Query
{
    int index, L, R;
    bool operator < (const Query &other) const
    {
        int block_own = L/k;
        int block_other = other.L/k;
        if(block_own == block_other)
            return R < other.R;
        return block_own < block_other;
    }
} query[Max];

void add(int index)
{
    sum+=arr[index];
}

void remove(int index)
{
    sum-=arr[index];
}

int main()
{
    int n;


    cin>>n;
    k = sqrt(n);
   
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++)
    {
        cin >> query[i].L >> query[i].R;
        query[i].index = i;
    }

    sort(query, query+q);

    for(int i = 0; i < q; i++)
    {
        cout<< query[i].L << " " << query[i].R <<  " "  << query[i].index <<endl;
    }
    int L=0, R=-1;
    for(int i=0;i<q;i++){
        while(R<query[i].R) add(++R);
        while(L<query[i].L) remove(L++);
        while(R>query[i].R) remove(R--);
        while(L>query[i].L) add(--L);
        ans[query[i].index] = sum;
    }
    for(int i=0;i<q;i++){
        cout << ans[i] << "\n";
    }
    return 0;
}
