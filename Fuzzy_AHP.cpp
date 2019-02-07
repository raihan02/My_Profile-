#include <bits/stdc++.h>
using namespace std;
map <string, string> mp;
string criteria_matrix[15];
string criteria[15];
struct A1
{
    double x,y,z;

} arr[150];

struct A2
{
    double x,y,z;

} A[150];

struct A3
{
    double x,y,z;
}Fuzzy_Weights[150];

void load()
{
    /// Storing fuzzy number
    arr[1].x = 1.0, arr[1].y =1.0, arr[1].z =1.0;
    arr[2].x = 2.0, arr[2].y =3.0, arr[2].z =4.0;
    arr[3].x = 4.0, arr[3].y =5.0, arr[3].z =6.0;
    arr[4].x = 6.0, arr[4].y =7.0, arr[4].z =8.0;
    arr[5].x = 9.0, arr[5].y =9.0, arr[5].z =9.0;
    arr[6].x = 0.250, arr[6].y =0.333, arr[6].z = 0.500;
    arr[7].x = 0.166, arr[7].y =0.200, arr[7].z = 0.250;
    arr[8].x = 0.125, arr[8].y =0.142, arr[8].z = 0.166;
    arr[9].x = 0.111, arr[9].y =0.111, arr[9].z = 0.111;
    /// storing intermediate fuzzy number
    arr[10].x = 1.0, arr[10].y = 2.0, arr[10].z = 3.0;
    arr[11].x = 3.0, arr[11].y = 4.0, arr[11].z = 5.0;
    arr[12].x = 5, arr[12].y = 6, arr[12].z = 7;
    arr[13].x = 7, arr[13].y = 8, arr[13].z = 9;
    arr[14].x = 0.333, arr[14].y = 0.500, arr[14].z = 1.000;
    arr[15].x = 0.200, arr[15].y = 0.250, arr[15].z = 0.333;
    arr[16].x = 0.142, arr[16].y = 0.166, arr[16].z = 0.200;
    arr[17].x = 0.111, arr[17].y = 0.125, arr[17].z = 0.142;
}



void load_value (int n)
{
    load();
    double scale;
    double mat[100][100] = {0};
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {

            if(i == j)
            {
                mat[i][j] = 1.0;
                continue;
            }
            cout<< "For " << criteria[i] << " to  " << criteria[j] <<":";
            printf("\n1 2 3 4 5 6 7 8 9\n");
            cout<<"Select 1 for equal importance"<< endl;
            cout<<"Select 2 for moderately importance"<< endl;
            cout<<"Select 3 for strongly importance"<< endl;
            cout<<"Select 4 for very strongly importance"<< endl;
            cout<<"Select 5 for extremely strongly importance"<< endl;
            cout<<"Select 6 for moderately importance (inverse)"<< endl;
            cout<<"Select 7 for strongly importance (inverse)"<< endl;
            cout<<"Select 8 for very strongly importance (inverse)"<< endl;
            cout<<"Select 9 for extremely strongly importance (inverse)"<< endl;
            cin >> scale;
            mat[i][j] = scale;
        }

    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(mat[i][j] == 2)
            {
                mat[j][i]= 6;
            }
            else if(mat[i][j] == 3)
            {
                mat[j][i]= 7;
            }
            else if(mat[i][j] == 4)
            {
                mat[j][i]= 8;
            }
            else if(mat[i][j] == 5)
            {
                mat[j][i]= 9;
            }
            else if(mat[i][j] == 9)
            {
                mat[j][i]= 5;
            }
            else if(mat[i][j] == 8)
            {
                mat[j][i]= 4;
            }
            else if(mat[i][j] == 7)
            {
                mat[j][i]= 3;
            }
            else if(mat[i][j] == 6)
            {
                mat[j][i]= 2;
            }
            else if(mat[i][j] == 10)
            {
                mat[j][i] = 14;
            }
            else if(mat[i][j] == 11)
            {
                mat[j][i] = 15;
            }
            else if(mat[i][j] == 12)
            {
                mat[j][i] = 16;
            }
            else if(mat[i][j] == 13)
            {
                mat[j][i] = 17;
            }
            else if(mat[i][j] == 17)
            {
                mat[j][i] = 13;
            }
            else if(mat[i][j] == 16)
            {
                mat[j][i] = 12;
            }
            else if(mat[i][j] == 15)
            {
                mat[j][i] = 11;
            }
            else if(mat[i][j] == 14)
            {
                mat[j][i] = 10;
            }
        }
    }
    double a, b, c;
    double sum1, sum2, sum3;
    double p = 1.0/(double)n;
    //cout<< p << endl;
    for(int i = 0; i < n; i++)
    {
        sum1 = 1.0, sum2 = 1.0, sum3 = 1.0;
        for(int j = 0; j < n; j++)
        {
            int g = mat[i][j];
            sum1 *= arr[g].x;
            sum2 *= arr[g].y;
            sum3 *= arr[g].z;

            //cout<<arr[g].x << " ";

        }
        //cout<< endl;
        //cout<<"Check "  <<i << " " << sum1 << endl;
        sum1 = pow(sum1, p);
        sum2 = pow(sum2, p);
        sum3 = pow(sum3, p);
        A[i].x = sum1;
        A[i].y = sum2;
        A[i].z = sum3;
    }
    /*
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout<< mat[i][j] << " ";
        }
        cout<< endl;
    }
    */

}

int main()
{

    int n;
    cout<<"Enter the number of Criteria" << endl;
    cin >> n;
    cout<<"Enter the number of criteria"<< endl;
    getchar();
    for(int i = 0; i < n; i++)
    {
        getline(cin, criteria[i]);
    }
    load();

    //cout<<"Check "<< arr[17].x << endl;
    load_value(n);
    //cout<< arr[10].x << endl;
    double res1 = 0.0, res2= 0.0, res3 =0.0;

    for(int i = 0; i < n; i++)
    {
        //printf("%.2lf %.2lf %.2lf\n", A[i].x,A[i].y,A[i].z);
        res1 += A[i].x;
        res2 += A[i].y;
        res3 += A[i].z;
    }

   // cout<< res1 << " " << res2 << " " << res3 << endl;
   double a,b,c;
   for(int i = 0; i < n; i++)
   {
       a = A[i].x * (1.0/res3);
       b = A[i].y * (1.0/res2);
       c = A[i].z * (1.0/res1);
      // cout<<a << " "  << b << " "<< c << endl;
       Fuzzy_Weights[i].x = a;
       Fuzzy_Weights[i].y = b;
       Fuzzy_Weights[i].z = c;

   }
   cout<<"Fuzzy Weighted Values are:" << endl;
   double ans =0.0;
      double Defuzzification[150] = {0.0};
   for(int i = 0; i < n; i++)
   {
       cout<< Fuzzy_Weights[i].x << " " << Fuzzy_Weights[i].y << " " << Fuzzy_Weights[i].z << endl;
       ans = (Fuzzy_Weights[i].x  + Fuzzy_Weights[i].y + Fuzzy_Weights[i].z)/3;
       Defuzzification[i] = ans;

   }

   cout<<"Defuzzification Values are: "<< endl;

   for(int i = 0; i < n; i++)
   {
       cout<< Defuzzification[i] << endl;
   }



}
