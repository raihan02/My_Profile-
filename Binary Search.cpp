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
            return index;
        }
        else if(key > arr[mid])
            begin_ = mid + 1;
        else if(key < arr[mid])
            end_ = mid - 1;
    }
    return index;
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

    int ans = Binary_search(arrSize, item);

    if(ans == -1)
    {
        cout<<"Not found"<< endl;
    }
    else
    {
        cout<<"Found at position " << ans << endl;
    }
}
