#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll prefix[100001];
void setPrefix (string s)
{
    int i = 0 ,j = -1;
    int len = s.length();
    prefix[0] = -1;
    while(i < len)
    {
        while( j >= 0 && s[i] != s[j])
        {
            j = prefix[j];

        }
        i++;
        j++;
        prefix[i] = j;
    }
}
bool kmp_algorithm(string s , string s1)
{
    int n = s.length();
    int m = s1.length();
   int i = 0 , j = 0;

   setPrefix(s1);
   int c = 0;
   while(i < n)
   {
       while(j >= 0 and s[i] != s1[j])
       {
           j = prefix[j];
       }
       i++;
       j++;
       if(j == m)
       {
           return true;
       }
   }
   return false;

}
int main()
{
    string s1 = "abcdefg";
    string s2 = "dek";
    bool x = kmp_algorithm(s1,s2);

    cout<<x<< endl;
}
