// Learn about Euler Tree and Euler Path
#include <iostream>
using namespace std;

void zigzag(int n)
{
    if(n==0)
    {
        return;
    }
    cout<<n<<" ";  // Pre Area
    zigzag(n-1);
    cout<<n<<" ";  // In Area
    zigzag(n-1);
    cout<<n<<" ";  // Post Area
    return;
}
int main()
{
    zigzag(3);
}
