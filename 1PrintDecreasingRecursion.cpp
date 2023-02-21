#include <iostream>
using namespace std;

void printDecreasing(int n)
{
    if(n==0) return;
    cout<<n<<endl;
    printDecreasing(n-1);
    return;
}

int main()
{
    printDecreasing(5);
}
