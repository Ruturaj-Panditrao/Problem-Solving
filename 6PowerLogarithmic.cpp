#include <iostream>
using namespace std;

int power(int x, int n)
{
    if(n==0) return 1;
    int sub = power(x,n/2) * power(x,n/2);
    if(n%2==0) return sub;
    else return x*sub;
}
int main()
{
    cout<<power(3,5);
}
