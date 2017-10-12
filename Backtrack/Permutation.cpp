void solve(string s, int i, int j)
{

    if(i == j)
    {
        cnt++;
        cout<<s<< endl;
        return;
    }

    for(int k = i; k <= j; k++)
    {
        if(cnt == pc)
        {
            break;
        }
        swap(s[i], s[k]);
        solve(s, i + 1, j);
        swap(s[i], s[k]);
    }
}
