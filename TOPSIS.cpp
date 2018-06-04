/**
       786
Name: Mohd. Raihan Uddin
International Islamic University of Chittagong
Algorithm: TOPSIS (Multi Criteria Decision Making (MCDM) ) Based on mobile
github_link: github.com/raihan02


**/
#include <bits/stdc++.h>
using namespace std;
map <string, int> look;
string alternative[100], attribute[100];
map <string, int> mp;
int alt, atr;
double A[105][105], A_norm[105][105];
vector <double> vv[100];
double w[100];
vector <double> sj_plus, sj_minus , nor, best, worst, summ, p;
map <int, string> m;
void show ()
{
    printf("\n\nThe Attributes Matrix are:\n");
    for(int i = 1; i <= alt; i++)
    {
        for(int j =1; j <= atr; j++)
        {
            printf("%5.0lf ", A[i][j]);
        }
        printf("\n");
    }
    printf("Weighted value:\n");
    for(int i = 1; i <= atr; i++)
        printf("%.2lf ", w[i]);
    cout<< endl;
}
void normalization()
{
    double res =  0.00, sum = 0;

    nor.push_back(0.0);
    for(int i = 1; i <= atr; i++)
    {
        res = 0.00;
        for(int j = 1; j <= alt; j++)
        {
            res +=  A[j][i] * A[j][i];
        }

        nor.push_back(sqrt(res));
    }
    //cout<< endl;
    for(int i = 1; i <= atr; i++)
    {
       // cout<<nor[i] << " ";
        for(int j = 1; j <= alt; j++)
        {
            //cout<< A[j][i] << " " ;

            A_norm[j][i] = A[j][i] / nor[i];
        }
        //cout<< endl;
    }
    /*
    printf("Normalize Matrix\n\n");
    for(int i = 1; i <= alt; i++)
    {
        for(int j = 1; j <= atr;j++)
        {
            printf("%5.3lf ", A_norm[i][j]);
        }
        printf("\n");
    }*/

}
void weighted_normalize()
{
    for(int i = 1; i <= atr; i++)
    {
        for(int j = 1; j <= alt; j++ )
        {
            A_norm[j][i] *= w[i];
        }
    }
    /*
    printf("Weighted normalize Matrix\n\n");
    for(int i = 1; i <= alt; i++)
    {
        for(int j = 1; j <= atr;j++)
        {
            printf("%5.4lf ", A_norm[i][j]);
        }
        printf("\n");
    }
    */
}
map <string, double> B,W;
vector <pair <double, int > > vvv, vkb;
void best_worst()
{
   best.push_back(0.0);
   worst.push_back(0.0);
    for(int i = 1; i <= atr; i++)
    {
        double mn = 9999999.0, mx = 0.0, mn1 = 9999999.0, mx1 = 0;
        bool f = 0;
        for(int j = 1; j <= alt; j++)
        {
            if(m[i] == "Price or cost")
            {
                f = 1;
                if(mn> A_norm[j][i])
                    mn = A_norm[j][i];
                if(mx1 < A_norm[j][i])
                    mx1 = A_norm[j][i];

            }
            else
            {
                if(mx < A_norm[j][i])
                {
                    mx = A_norm[j][i];
                }
                if(mn1 > A_norm[j][i])
                    mn1 = A_norm[j][i];
            }
        }
        if(f){
            worst.push_back(mx1);
            best.push_back(mn);
        }
        else{
            worst.push_back(mn1);
            best.push_back(mx);
        }
    }
    cout<< endl;
    //for(int i = 1; i < best.size(); i++)
        //cout<< best[i] <<" " << worst[i] << endl;
}

void euclid_distance_formula()
{
    double res = 0.0, sum = 0.0;
    sj_plus.push_back(0.0);
    sj_minus.push_back(0.0);
    summ.push_back(0.0);
    for(int i = 1; i <= alt; i++)
    {
        res = 0.00;
         sum = 0.0;
        for(int j = 1; j <= atr; j++)
        {
            res += pow((A_norm[i][j] - best[j]), 2);
            sum += pow((A_norm[i][j] - worst[j]), 2);
            //cout<<A_norm[i][j] << " ";
        }
       // cout<< endl;
        sj_plus.push_back(sqrt(res));
        sj_minus.push_back(sqrt(sum));
        summ.push_back(sqrt(res) + sqrt(sum));
    }

    /*
    for(int i = 1; i < sj_plus.size(); i++)
    {
        cout<< sj_plus[i] << " " << sj_minus[i] << endl;
    }
    */
}
void performance()
{
    double ans = 0.00;
     p.push_back(0.0);
    for(int i = 1; i < summ.size(); i++)
    {
        ans = sj_minus[i] / (sj_minus[i] + sj_plus[i]);
        p.push_back(ans);
    }
     /*
    for(int i = 1; i < p.size(); i++)
    {
        cout<<p[i] << endl;
    }
    */

}
void rank_clc ()
{
    vvv.push_back(make_pair(0.00, 0));
   for(int i = 1; i < p.size(); i++)
   {
       vvv.push_back(make_pair(p[i], i));
   }
   /*
   for(int i = 1; i < vvv.size(); i++)
   {
       cout<<vvv[i].first << " " << vvv[i].second << endl;
   }
   */
}

void show_final_Result ()
{
    sort(vvv.begin(), vvv.end());

    reverse(vvv.begin(), vvv.end());

    printf("\n\n\nFinal Ranking:\n\n");

    for(int i = 0; i < vvv.size()-1; i++)
    {
        ///cout<<vvv[i].first << " " << vvv[i].second << endl;
        cout<<"Rank " << i+1 << " = " <<alternative[vvv[i].second] << " , Performance = " <<vvv[i].first << endl<< endl;
    }

}
int main()
{

    look["Excellent"] = 5;
    look["Average"] = 3;
    look["Good"] = 4;
    look["Low"] =1;
    look["Below_Average"]= 2;
    printf("Enter the number of alternative:\n");
    cin >> alt;
    printf("Enter the number of Attribute\n");
    cin >> atr;
    printf("Alternatives are:\n");
    getchar();
    for(int i = 1; i <= alt; i++)
    {
        printf("Enter %d alternative:\n",i);
        string s;
        getline(cin, s);
        alternative[i] = s;

    }
    printf("Attributes are:\n");
    //getchar();
    for(int i = 1; i <= atr; i++)
    {
        printf("Enter %d alternative:",i);
        getline(cin , attribute[i]);
         m[i] = attribute[i];
        w[i] = 1.0/ (double)atr;
    }
    for(int i = 1; i <= alt; i++)
    {
          cout<<"Enter Attribute for " << alternative[i] << ":\n";
          for(int j = 1; j <= atr; j++)
          {
                cout<<"For " << attribute[j] << " = ";
                if(attribute[j] == "Looks")
                {
                    string s;
                    cin >> s;
                    A[i][j] = look[s];
                }
                else
                {
                    int x;
                    cin >> x;
                    A[i][j] = x;
                }
          }
    }
    //show();
    normalization();
    weighted_normalize();
    best_worst();
    euclid_distance_formula();
    performance();
    rank_clc();
    show_final_Result();

    printf("Alhamdulillah\n\n");

}
/*
5
4
mobile1
mobile2
mobile3
mobile4
mobile5
Price or cost
Storage space
Camera
Looks
250 16 12 Excellent
200 16 8 Average
300 32 16 Good
275 32 8 Good
225 16 16 Below_Average
*/


