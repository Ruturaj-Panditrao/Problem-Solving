#include <iostream>
using namespace std;

int findMax(int arr[], int index, int n)
{
    if(index == n-1) return arr[index];

    int subwinner1 = findMax(arr,index+1,n);
    int subwinner2 = arr[index];
    
    return max(subwinner1,subwinner2);
}
int main()
{
    int arr[5] = {10,25,32,47,16};
    cout<<findMax(arr,0,5);
}
