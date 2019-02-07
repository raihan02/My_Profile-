#include <bits/stdc++.h>
using namespace std;
string alternative[100], criteria[100];
int n;
int m;
struct AA
{
    double a,b,c;

} arr[150];
struct AAA
{
   double d,f,g;
}A[105];
void load()
{
    arr[1].a = 1, arr[1].b = 1, arr[1].c = 3;/// Very low
    arr[2].a = 1, arr[2].b = 3, arr[2].c = 5;/// Low
    arr[3].a = 3, arr[3].b = 5, arr[3].c = 7;/// Average
    arr[4].a = 5, arr[4].b = 7, arr[4].c = 9;/// High
    arr[5].a = 7, arr[5].b = 9, arr[5].c = 9;/// Very high
}
void load_value(int x)
{
    load();
    double mat[105][105] = {0.0}, comb[105][105] = {0.0}, A1[105][105], B1[105][105],C1[105][105];
    for(int k = 0; k < x; k++)
    {
        printf("Enter the %d number decision:\n",k+1);

        for(int i = 0; i < n; i++)
        {
            cout<<"Enter Attribute for " << alternative[i] << ":\n";
            for(int j = 0; j < m; j++)
            {
                cout<<"For " << criteria[j] << " = ";
                cout<<" Select 1: Very Low"<< endl;
                cout<<" Select 2: Low"<< endl;
                cout<<" Select 3: Average"<< endl;
                cout<<" Select 4: High"<< endl;
                cout<<" Select 5: Very High"<< endl;
                double p;
                cin >> p;
                if(k == 0)
                    A1[i][j] = p;
                if(k == 1)
                    B1[i][j] = p;
                if(k == 2)
                    C1[i][j] = p;
            }
        }

    }

    for(int k = 0; k < x; k++)
    {
        /*
        if(k == 0)
        {
            cout<<"Cand1"<< endl;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    cout<< A1[i][j] << " ";
                }
                cout<< endl;
            }
        }

        if(k == 1)
        {
            cout<<"Cand2"<< endl;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    cout<< B1[i][j] << " ";
                }
                cout<< endl;
            }
        }
        if(k == 2)
        {
            cout<<"Cand3"<< endl;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    cout<< C1[i][j] << " ";
                }
                cout<< endl;
            }

        }
        */
        double p,q,r,s;
        int x, y, z;
        int o = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                o++;
                x = A1[i][j];
                y = B1[i][j];
                z = C1[i][j];
                p = min(min(arr[x].a,arr[y].a), arr[z].a);
                q = arr[x].b + arr[y].b + arr[z].b;
                q/= 3.0;
                r = max(max(arr[x].c,arr[y].c), arr[z].c);
                A[o].d = p;
                A[o].f = q;
                A[o].g = r;
            }
        }
    }
    int k = 0;
    double mx = 0.0, mn = 999999.0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            k++;
            cout<<A[k].d << " " << A[k].f << " " << A[k].g << "     ";
        }
        
        cout<< endl;
    }
}



int main()
{
   load();
    cout<<"Enter the number of Alternative"<< endl;
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++)
    {
        getline(cin, alternative[i]);
    }

    cout<<"Enter the number of Criteria"<< endl;
    cin >> m;
    getchar();
    for(int i = 0; i < m; i++)
    {
        getline(cin, criteria[i]);
    }

    int x;
    cout<<"Enter the number of decision maker" << endl;
    cin >> x;

    load_value(x);

}
/*
4
c1
c2
c3
c4
3
cs
k
ps
3
3 5 4
4 5 3
5 3 2
2 3 5
4 5 4
4 4 3
5 4 1
2 3 1
3 4 4
4 3 3
4 3 2
1 2 1
*/



