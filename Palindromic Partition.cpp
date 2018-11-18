int solve(char *str)
{
  int n = strlen(str);
    bool p[max1][max1];
    int C[max1];

    int i , j , k , l;
    for(int i = 0; i < n; i++)
    {
        p[i][i] = true;
    }
    for(int x = 2; x <= n; x++)
    {
        for(int i = 0; i < n - x + 1; i++)
        {
            j = i + x - 1;
            if(x == 2)
                p[i][j] = (str[i] == str[j]);
            else
                p[i][j] =  (str[i] == str[j]) && p[i+1][j-1];
        }
    }


    for(int i = 0; i < n; i++)
    {
        if(p[0][i] == true)
            C[i] = 0;
        else
        {
            C[i] = inf;
            for(j = 0; j < i; j++)
            {
                if(p[j+1][i] == true && 1+C[j]<C[i])
                    C[i] = 1 +  C[j];
            }
        }
    }
    return C[n - 1];
}

int main()
{
    char str[max1];
    ft{
        cin >> str;
        printf("Case %d: ",c);
    printf("%d\n", solve(str) + 1);
    }
}
