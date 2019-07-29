#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int Binary_search (int arr_size, int key)
{
    int begin_ , end_,  mid;
    begin_ = 0;
    end_ = arr_size - 1;
    int index = -1;
    while(begin_ <= end_)
    {
        mid = (begin_ + end_) / 2;
        if(key == arr[mid])
        {
            index = mid;
            end_ = mid - 1;
        }
        else if(key > arr[mid])
            begin_ = mid + 1;
        else if(key < arr[mid])
            end_ = mid - 1;
    }
    return begin_;
}
int main()
{
    int arrSize;
    cin >> arrSize;

    for(int i = 0; i < arrSize; i++)
    {
        cin >> arr[i];
    }

    int item;
    cin >> item;

    sort(arr, arr + arrSize);

    int lower_bound_  = Binary_search(arrSize, item);
    cout<<lower_bound_ << endl;
}
