#include <iostream>
using namespace std;

void printDecreasingIncreasing(int n)
{
    if(n==0) return;

    cout<<n<<endl;
    printDecreasingIncreasing(n-1);
    cout<<n<<endl;
    return;
}

int main()
{
    printDecreasingIncreasing(5);
    // Expected Output
    // 5 4 3 2 1 1 2 3 4 5
}
