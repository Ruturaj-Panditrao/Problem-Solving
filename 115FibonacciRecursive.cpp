#include <iostream>
using namespace std;

// Recursive Fibonacci Series
// Note :
// 0th Number has been considered 0
// 1st Number has been considered 1

int fibonacci(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}
int main()
{
    cout<<fibonacci(10);
}
