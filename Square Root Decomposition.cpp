#include  <bits/stdc++.h>
using namespace std;
int segmentArray[100005];
int inputArray[100005];

int preProcess(int n)
{
    int currentSegment = 0;
    int segmentSize = sqrt(n) + 1;

    for(int i = 0; i < n ;i ++)
    {
        if(i % segmentSize == 0)
        {
           // printf("%d\n", i);
            currentSegment++;

        }
        //printf("%d\n", currentSegment);
        segmentArray[currentSegment] += inputArray[i];
    }
    return segmentSize;
}
int setQuery (int segmentSize, int left, int right)
{
    int finalSum = 0;
    /// first calculate first segment
    while(left < right && left % segmentSize != 0)
    {
        finalSum += inputArray[left];
        left++;
    }

    /// calculate segment that contains right

    while(left + segmentSize <= right){
        finalSum += segmentArray[left / segmentSize];
        left += segmentSize;
    }

    /// Calculate until reach

    while(left <= right)
    {
        finalSum += inputArray[left];
        left++;
    }

    return finalSum;

}

void updateArray(int segmentSize , int iteration, int updateValue)
{
    int segmentNo;
    segmentNo = iteration / segmentSize;
    segmentArray[segmentNo] -= inputArray[iteration];
    segmentArray[iteration] += updateValue;
    inputArray[iteration] = updateValue;

}
int main()
{
    int n;

    while(cin >> n)
    {

        for(int i = 0; i < n; i++)
        {
            cin>> inputArray[i];
        }

        int segmentSIze = preProcess(n);

        int arrayRangeSum = 0;
        arrayRangeSum = setQuery(segmentSIze, 1, 4);

        printf("Total Sum = %d\n" ,arrayRangeSum);

        updateArray(segmentSIze, 4, 20);

        arrayRangeSum = setQuery(segmentSIze, 3,5);

        printf("%d\n", arrayRangeSum);

    }
}
