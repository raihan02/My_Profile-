#include <bits/stdc++.h>
using namespace std;
int hist[10005];
int large_rectangle (int n)
{
    stack <int> st;
    int i = 0;
    int mx = 0;
    int large_area= 0;
    while(i < n)
    {
        if(st.empty() || hist[st.top()] <= hist[i]){
            st.push(i++);

        }
        else
        {
            int top = st.top();
            st.pop();

            if(st.size() > 0)
            {
                large_area = hist[top] * (i - st.top() -1);
            }
            else
            {
                large_area = hist[top] * i;
            }
            mx = max(mx, large_area);
        }
    }

    while(st.size() > 0)
    {
        int top = st.top();
        st.pop();
         if(st.size() > 0)
            {
                large_area = hist[top] * (i - st.top() -1);
            }
            else
            {
                large_area = hist[top] * i;
            }
            mx = max(mx, large_area);
    }
    return mx;
}
int main()
{
    int n;
    int tes,o=0;
    scanf("%d",&tes);

    while(tes--)
    {
        o++;
        scanf("%d",&n);

        for(int i = 0; i < n; i++)
            {
                scanf("%d",&hist[i]);
            }
        int ans=  large_rectangle(n);

        printf("Case %d: %d\n", o, ans);
    }
}
