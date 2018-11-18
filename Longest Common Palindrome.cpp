#include <bits/stdc++.h>
using namespace std;
#define max1 10
int L[max1][max1];
char s[max1];
int LPS (char *s)
{
    int n , j;
    n = strlen(s);

    for(int i = 0; i < n; i++)
        L[i][i] = 1;

    for(int cl = 2; cl <= n; cl++)
    {
        for(int i  = 0; i < n - cl + 1; i++)
        {
            j = i + cl - 1;
            if(s[i] == s[j] and cl == 2)
            {
                L[i][j] = 2;
            }
            else if(s[i] == s[j])
            {
                L[i][j] = L[i + 1][j - 1] + 2;
            }
            else
            {
                L[i][j] = max(L[i][j - 1], L[i + 1][j]);
            }

        }
    }
    return L[0][n - 1];
}
int main()
{
    char s[10] ="BABB";

    printf("%d\n" , LPS(s));
}
