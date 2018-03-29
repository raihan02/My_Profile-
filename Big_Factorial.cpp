#include <bits/stdc++.h>
using namespace std;
int f[367][785];
void fun()
{
    f[0][0] = 1;
    f[1][0] = 1;

    for(int i = 2; i < 367; i++)
    {
        for(int j = 0; j < 785; j++)
        {
            f[i][j] = f[i][j] + f[i - 1][j] * i;
            if(f[i][j] > 9)
            {
                f[i][j + 1] = f[i][j] / 10;
                f[i][j] %= 10;
            }
        }
    }

}
int main()
{
   fun();
   int n;
   while(cin >> n)
   {
       int cnt;

       for(cnt = 785 - 1; cnt >= 0; cnt--)
       {
           if(f[n][cnt] != 0)
            break;
       }

       for(int i = cnt; i >= 0; i--)
       {
           cout<< f[n][i];
       }
       cout<< endl;

   }


}
