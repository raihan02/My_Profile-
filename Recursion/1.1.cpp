/*
Write a recursive program to remove all odd integers from an array.
You must not use any extra array or print anything in the function. 
Just read input, call the recursive function, then print the array in main().
*/
#include <bits/stdc++.h>
using namespace std;
int arr[100] ={0};
void rev (int i, int *n, int j)
{
    if(i == *n)
    {
        *n = j;
        return;
    }
    if(arr[i] % 2 == 0){
        arr[j++] = arr[i];
    }
    rev(i+1, n, j);
}
int main()
{

   int n;
   cin >> n;

   for(int i = 0; i < n; i++)
    cin >> arr[i];
    rev(0, &n, 0);

    for(int i = 0; i < n; i++)
        cout<< arr[i] << " ";


}
/*

*/
