#include <vector>
#include <iostream>
using namespace std;

int fibonacci(int n, vector<int>&qb)
{
    if(n==0 || n==1)
    {
        return n;
    }

    if(qb[n]!=0)
    {
        return qb[n];
    }

    int fib1 = fibonacci(n-1,qb);
    int fib2 = fibonacci(n-2,qb);
    int fibn = fib1 + fib2;

    qb[n] = fibn;

    return fibn;
}
int main()
{
    vector<int>qb(11,0);
    cout<<fibonacci(10,qb);
}
