#include <iostream>
using namespace std;

int lastOccurrenceIndex(int arr[], int index, int key, int n)
{
    if(index == n)
    {
        return -1;
    }

    int lisa = lastOccurrenceIndex(arr,index+1,key,n);
    if(lisa != -1)
    {
        return lisa;
    }
    else
    {
        if(arr[index]==key) return index;
        return -1;
    }
}
int main()
{
    int arr[10] = {2,3,6,9,8,3,2,3,6,4};
    cout<<lastOccurrenceIndex(arr, 0, 2, 10); // 6
    cout<<lastOccurrenceIndex(arr, 0, 6, 10); // 8
}
