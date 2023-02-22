#include <iostream>
using namespace std;

void print(int arr[], int index, int n)
{
    if(index == n) return;
    cout<<arr[index]<<" ";
    print(arr,index+1,n);
}
int main()
{
    int arr[5] = {10,20,30,40,50};
    print(arr,0,5);
}
