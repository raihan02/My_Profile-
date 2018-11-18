#include <bits/stdc++.h>
using namespace std;
int n;bool T[100][100];
bool subsetSum(int input[], int total)
{

    // = [input.length + 1][total + 1];
    for (int i = 0; i <= n; i++)
    {
        T[i][0] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= total; j++)
        {
            if (j - input[i - 1] >= 0)
            {
                T[i][j] = T[i - 1][j] || T[i - 1][j - input[i - 1]];
            }
            else
            {
                T[i][j] = T[i-1][j];
            }
        }
    }

    return T[n][total];

}
void soln (int n , int total)
{

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= total; j++)
        {
            if(T[i][j] == 0)
                printf("F ");
            else

            printf("T "); //, T[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int arr1[] = {2, 3, 7, 8 , 10};
    n = 5;
     int res = subsetSum(arr1, 11);
     printf("%d\n", res);
     soln(n, 11);

}
