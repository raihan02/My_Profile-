#include <bits/stdc++.h>
using namespace std;
int n, d[10015];
bool havel_hakemi ()
{
    for(int i = 0; i < n; i++)
    {
        if(i == n - 1)
        {
            if(d[i] != 0)
            {
                return false;
            }
        }
        sort(d + i, d + n);
        reverse(d + i, d + n);

        for(int j = i + 1; j < i + 1 + d[i]; j++)
        {
            if(--d[j] < 0)
            {
                return false;
            }
        }
    }

    return true;
}
int main()
{
  while(cin >> n)
  {
      if(n == 0)
        break;
      memset(d,0,sizeof d);
      int sum = 0;
      bool f = 0;
      for(int i = 0; i < n; i++)
      {
          cin >> d[i];
          sum += d[i];

      }
      if(sum %2 || f)
      {
          cout<<"Not possible"<< endl;
          continue;
      }
      if(havel_hakemi())
        cout<<"Possible"<< endl;
      else
        cout<<"Not possible"<< endl;
  }
}
