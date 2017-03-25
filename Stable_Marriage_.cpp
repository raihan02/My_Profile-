#include <bits/stdc++.h>
using namespace std;
int pref[220][110];
int n;
bool check (int w, int m, int m1)
{
    for(int i = 0; i < n; i++)
    {
        if(pref[w][i] == m1)
            return true;
        if(pref[w][i] == m)
            return false;
    }
}
void stable_marriage()
{
    int p[110];
    bool free[110];
    memset(p, -1, sizeof p);
    memset(free, false, sizeof free);
    int cnt  =n;
    while (cnt > 0)
    {

        int m;
        for (m = 0; m < n; m++)
            if (free[m] == false)
                break;
        for (int i = 0; i < n && free[m] == false; i++)
        {
            int w = pref[m][i];
            if (p[w-n] == -1)
            {
                p[w-n] = m;
                free[m] = true;
                cnt--;
            }

            else
            {
                int m1 = p[ w- n];
                if (check(w, m, m1) == false)
                {
                    p[w-n] = m;
                    free[m] = true;
                    free[m1] = false;
                }
            }
        }

    }
    cout << "Woman   Man" << endl;
        for (int i = 0; i < n; i++)
            cout << " " << i+n << "\t" << p[i] << endl;
}
int main()
{
    int tes;
    cin >> tes;
    while(tes--)
    {

        cin >> n;

        for(int i = 0; i < n * 2; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> pref[i][j];


            }
        }
        stable_marriage();
    }



}
