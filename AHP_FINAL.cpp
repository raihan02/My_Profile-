#include <bits/stdc++.h>
using namespace std;
string factor[11], alternate[11];
vector <double> vp, vk, vt;
double lemda, CR, CI;
double RI[11] = {0.0, 0.0, 0.58, 0.9, 1.12, 1.24, 1.32,  1.41,  1.45, 1.49};
vector <double> level[100];
void load (int n)
{
    printf("The Factors are:\n\n");

    for(int i = 0; i < n; i++)
    {
        getline(cin, factor[i]);
    }
}
double mat[100][100];
double p_vector[100][100], A_prime[100][100];
void compo (int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            mat[i][j] = 0;
        }
    }
    double scale;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(i == j)
            {
                scale = 1.0;
            }
            else
            {
                cout<< "For " << factor[i] << " to  " << factor[j] <<":";

                printf("\n9 7 5 7 3 1 3 5 7 9\n");
                cin >> scale;
            }
            mat[i][j] = scale;
            mat[j][i] = (1.0/ scale);
        }
    }
}
void priority_vector (int n)
{
    double sum  = 0.0;

    for(int i = 0; i < n; i++)
    {
        sum = 0.0;
        for(int j = 0; j < n; j++)
        {
            p_vector[i][j] = mat[i][j];
            sum += mat[j][i];
        }

        vp.push_back(sum);
    }

    for(int i = 0; i < vp.size(); i++)
    {
        p_vector[n][i] = vp[i];
    }
    /// Priority Matrix print
    /*
     printf("Priority Vector:\n");
     for(int i = 0; i <= n; i++)
     {
         for(int j = 0; j < n; j++)
         {
             cout<< p_vector[i][j] <<" ";
         }
         cout<< endl;
     }*/
}

void A_vector(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            A_prime[i][j] = mat[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            A_prime[j][i] = (A_prime[j][i] / vp[i]);
        }
    }

    for(int i = 0; i < n; i++)
    {
        double sum = 0.0;
        for(int j = 0; j < n; j++)
        {
            ///cout<< A_prime[i][j] << " ";
            sum += A_prime[i][j];
        }
        vk.push_back(sum);

    }

    for(int i = 0; i < vk.size(); i++)
    {
        vt.push_back((double)(1/(double)n) * vk[i]);
    }

    /// Priority vector or W
    /*
    for(int i = 0; i < vt.size(); i++)
    {
        cout<< vt[i] << endl;
    }
    */

}
void display(int n)
{
    for(int i = 1; i <= 20; i++)
        printf("-");
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // cout<<setw(10)<< mat[i][j] << " ";
        }
        //cout<< endl;
    }

    double arr[100][100] = {0};

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arr[j][i] = vt[i] * mat[j][i];
        }
    }

    for(int i = 1; i <= 20; i++)
        printf("-");
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            //cout<<setw(10)<< arr[i][j] << " ";
        }
        //cout<< endl;
    }
    vector <double> ws,wa;

    for(int i = 0; i < n; i++)
    {
        double sum = 0.00;
        for(int j = 0; j < n; j++)
        {
            sum += arr[i][j];
        }
        ws.push_back(sum);
    }

    for(int i = 0; i < ws.size(); i++)
    {
        // cout<< ws[i] << endl;
        wa.push_back(ws[i]/vt[i]);
    }

    //printf("___________\n");
    double sum = 0.0;
    for(int i = 0; i < wa.size(); i++)
    {
        //cout<< wa[i] << endl;
        //wa.push_back(vt[i]/wa[i]);
        sum += wa[i];
    }
    double lemda = sum/ n;



    double a,b,c,d, CI;
    a = lemda - n;

    CI =  a/(n-1);


    double CR = CI / RI[n-1];
    cout<<"Lemda Max = " <<  lemda << endl;
    cout<<"CI = " << CI << endl;
    cout<<"CR = " << CR << endl;
    cout<<"Priority Vector " << endl;
    printf("----------------\n");
    for(int i = 0; i < vt.size(); i++)
    {
        cout<< vt[i] << endl;
    }
    if(CR > 0.1)
        cout<<"Try Again" << endl;
    else
    {
        cout<<"Accepted" << endl;
        cout<< endl;

    }
    wa.clear();
    ws.clear();



}

void lemda_max (int n)
{
    lemda = 0.0;
    for(int i = 0; i < vp.size(); i++)
    {
        //cout<< vp[i] << " " << vt[i] << endl;
        lemda += (vp[i] * vt[i]);
    }
    /// lemda_max count
    /*
     cout<< lemda << endl;
     */
}
void consistaency_ration(int n)
{
    CI = (lemda - n) / (n - 1);
    CR = CI / RI[n - 1];


}
void clear(int n)
{
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            A_prime[i][j] = 0.0;
            p_vector[i][j] = 0.0;
            mat[i][j] = 0.0;
        }
        factor[i].clear();
    }
    CR = 0.0;
    CI = 0.0;
    lemda = 0.0;
    vt.clear();
    vp.clear();
    vk.clear();
}
void ff(int x)
{
    level[x].push_back(CR);
    for(int i = 0; i < vt.size(); i++)
    {
        level[x].push_back(vt[i]);
    }
}
void checking (int n)
{
    if(CR < 0.1)
    {
        printf("Accepted\n");
    }
    else
    {
        printf("Try Again\n");
    }
    cout<<"CR " <<CR << endl; //end;
    cout<<"Lemda Max " << lemda << endl;
    cout<<"Priority Vector " << endl;
    printf("----------------\n");
    for(int i = 0; i < vt.size(); i++)
    {
        cout<< vt[i] << endl;
    }
}
int main()
{
    int n;
    printf("Enter the dimension and factor\n\n");

    cin >> n;
    clear(n);

    getchar();
    load(n);
    for(int i = 0; i < n; i++)
        alternate[i] = factor[i];
    compo(n);
    //display(n);
    priority_vector(n);
    A_vector(n);
    lemda_max(n);
    consistaency_ration(n);

    //checking(n);
    display(n);
    int x = 1;
    //check(n);
    ff(x);
    for(int i = 0; i < n; i++)
    {
        //cout<<"Consider " << alternate[i] << ": ";
        int p;
        cout<<"How Many Factors for " << alternate[i] << endl;
        cin >> p;
        clear(p);
        getchar();
        load(p);
        compo(p);
        //display(n);
        priority_vector(p);
        A_vector(p);
        lemda_max(p);
        consistaency_ration(p);
        // checking(p);
        display(p);
        ff(x + 1);

    }


}
/*
4
a
b
c
d
5
4
7
0.5
3
3

*/
