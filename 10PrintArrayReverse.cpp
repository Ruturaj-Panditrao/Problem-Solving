#include <iostream>
using namespace std;

void printReverse(int arr[], int index, int n)
{
    if(index==n) return;
    printReverse(arr,index+1,n);
    cout<<arr[index]<<" ";
}
int main()
{
    int arr[5] = {10,20,30,40,50};
    printReverse(arr,0,5);
}
