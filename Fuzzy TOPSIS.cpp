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

} A[105];
struct AAAA
{
    double aa,bb,cc;
} B[105];
struct W
{
    double a,b,c;
} weight[100];
struct ABC
{
    double a,b, c;
} ara[104][104];

void load1()
{
    weight[1].a = 5, weight[1].b = 7, weight[1].c = 9;
    weight[2].a = 7, weight[2].b = 9, weight[2].c = 9;
    weight[3].a = 3, weight[3].b = 5, weight[3].c = 7;
}
void load()
{
    arr[1].a = 1, arr[1].b = 1, arr[1].c = 3;/// Very low
    arr[2].a = 1, arr[2].b = 3, arr[2].c = 5;/// Low
    arr[3].a = 3, arr[3].b = 5, arr[3].c = 7;/// Average
    arr[4].a = 5, arr[4].b = 7, arr[4].c = 9;/// High
    arr[5].a = 7, arr[5].b = 9, arr[5].c = 9;/// Very high
}
struct AAAAA
{
    double a,b,c;
}C[105];
void load_value()
{
    load();
    load1();
    double mat[105][105] = {0.0}, comb[105][105] = {0.0}, A1[105][105], B1[105][105],C1[105][105];


    for(int i = 0; i < n; i++)
    {
        cout<<"Enter Attribute for " << alternative[i] << ":\n";
        for(int j = 0; j < m; j++)
        {
            cout<<"For " << criteria[j] << " :\n ";
            cout<<" Select 1: Very Low"<< endl;
            cout<<" Select 2: Low"<< endl;
            cout<<" Select 3: Average"<< endl;
            cout<<" Select 4: High"<< endl;
            cout<<" Select 5: Very High"<< endl;
            double p;
            cin >> p;
            A1[i][j] = p;
        }
    }
    vector <double> v, vt;
    bool flag[1005] = {0};
    double r1 = 0.0, r2 = 9999999.0;
    for(int i = 0; i < m; i++)
    {
        bool f = 0;
        for(int j = 0; j < n; j++)
        {
            ///  cout<< A1[j][i] <<" " ;
            if(i + 1 == m)
            {
                f = 1;
                int p = A1[j][i];
                r2 = min(r2, arr[p].a);
                continue;
            }

            int p = A1[j][i];
            r1 = max(r1, arr[p].c);


        }
        if(f == 1)
        {
            v.push_back(r2);
            vt.push_back(r2);
        }
        else
            v.push_back(r1);
        //cout<< endl;
    }

    sort(vt.begin(),vt.end());

    int k = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            k++;
            int p = A1[i][j];
            //printf("%.2lf %.2lf %.2lf  -> %.0lf |    ", arr[p].a,arr[p].b,arr[p].c, v[j]);
            if(j == m -1)
            {
                ara[i][j].a = v[j]/arr[p].a;
                ara[i][j].b = v[j]/arr[p].b;
                ara[i][j].c = v[j]/arr[p].c;

            }
            else
            {
                ara[i][j].a = arr[p].a/v[j];
                ara[i][j].b = arr[p].b/v[j];
                ara[i][j].c = arr[p].c/v[j];
            }

        }
        //cout<< endl;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            //printf("%.2lf %.2lf %.2lf  -> %.0lf |    ", ara[i][j].a,ara[i][j].b,ara[i][j].c, v[j]);

            ara[i][j].a *= weight[j+1].a;
            ara[i][j].b *= weight[j+1].b;
            ara[i][j].c *= weight[j+1].c;
        }
        // cout<< endl;
    }
    int u,o, xx,yy;
    double sum = 0.0, mx = 0.0, res, mn = 999999.0;
    for(int i = 0; i < m; i++)
    {
        sum = 0.0, mx = 0.0, mn = 999999.0, res = 0.0;
        for(int j = 0; j < n; j++)
        {
           // printf("%.2lf %.2lf %.2lf  -> %.0lf |    ", ara[j][i].a,ara[j][i].b,ara[j][i].c, v[j]);
            sum =  ara[j][i].b + ara[j][i].c;
            if(sum > mx)
            {
                mx = sum;
                u = i;
                o = j;
            }
            res =  ara[j][i].a + ara[j][i].b;

            if(res < mn)
            {
                mn = res;
                xx = i;
                yy = j;
            }
        }
        B[i].aa = ara[o][u].a;
        B[i].bb = ara[o][u].b;
        B[i].cc = ara[o][u].c;

        C[i].a = ara[yy][xx].a;
        C[i].b = ara[yy][xx].b;
        C[i].c = ara[yy][xx].c;
    }

    double sum1 = 0.0, pp = (1.0/3.0);
    double matrix[105][105];
    for(int i = 0; i < m; i++)
    {
       for(int j = 0; j < n; j++)
       {
           sum1 =  pow((ara[j][i].a - B[i].aa),2) + pow((ara[j][i].b - B[i].bb),2) + pow((ara[j][i].c - B[i].cc),2);

           sum1 = sum1 * pp;

           sum1 = sqrt(sum1);
           //printf("%.2lf ", sum1);

           matrix[j][i] = sum1;
       }
       //cout<< endl;
    }
    double matrix1[105][105];
    for(int i = 0; i < m; i++)
    {
       for(int j = 0; j < n; j++)
       {
           sum1 =  pow((ara[j][i].a - C[i].a),2) + pow((ara[j][i].b - C[i].b),2) + pow((ara[j][i].c - C[i].c),2);
           sum1 = sum1 * pp;
           sum1 = sqrt(sum1);
           //printf("%.2lf ", sum1);
           matrix1[j][i] = sum1;
       }
       //cout<< endl;
    }

    vector <double> di_pos , di_neg;
    for(int i = 0; i < n; i++)
    {
        double sum3 =0.0, sum4 =0.0;
        for(int j = 0; j < m; j++)
        {
            sum3 += matrix[i][j];
            sum4 += matrix1[i][j];
            //printf("%.2lf ", matrix1[i][j]);
        }
        di_pos.push_back(sum3);
        di_neg.push_back(sum4);
        //cout<< endl;
    }

    vector < pair <double, int> > ran;
    for(int i = 0; i < di_pos.size(); i++)
    {
        double ans = di_neg[i] / (di_neg[i] + di_pos[i]);
        ran.push_back(make_pair(ans, i));
       // cout<< di_pos[i] << " " << di_neg[i] << endl;
    }
    sort(ran.begin() , ran.end());
    reverse(ran.begin(), ran.end());
    for(int i = 0; i < di_pos.size(); i++)
    {
        cout<<alternative[ran[i].second] << " "  << ran[i].first   <<  endl;
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
    load_value();

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
3 5 4
4 5 3
5 3 2
2 3 5
*/

