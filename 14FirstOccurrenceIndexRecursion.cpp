#include <iostream>
using namespace std;

// int firstOccurrenceIndex(int arr[], int key, int index, int n)
// {
//     if(index == n)
//     {
//         return -1;
//     }

//     int c1 = arr[index];
//     int c2 = firstOccurrenceIndex(arr,key,index+1,n);

//     if(c1 == key) return index;
//     else return c2;
// }

int firstOccurrenceIndex(int arr[], int key, int index, int n)
{
    if(index == n) 
    {
        return -1;
    }
    if(arr[index]==key) return index;
    else return firstOccurrenceIndex(arr,key,index+1,n);
}
int main()
{
    int arr[10] = {2,3,6,9,8,3,2,6,2,4};
    cout<<firstOccurrenceIndex(arr,2,0,10); // 0
    cout<<firstOccurrenceIndex(arr,6,0,10); // 2
}
