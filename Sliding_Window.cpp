#include <iostream>
using namespace::std;
int main()
{
    int maxSum = 0, windowSum = 0;
    
    int arr[100], n, k;
    cin >> n >> k;
    
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i < k){
            windowSum += arr[i]; // Calculate first window
        }
    }
    
    maxSum = windowSum;
    
    for(int i = k; i < n; i++){
        windowSum += arr[i] - arr[i - k];
        
        maxSum = max(maxSum, windowSum);
    }
    
    cout<< windowSum << endl;
    
    
}
