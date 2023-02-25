#include <iostream>
using namespace std;

void printStairPaths(int n, string ans)
{
    if(n==0) 
    {
        cout<<ans<<" ";
        return;
    }

    if(n>=1) printStairPaths(n-1, ans + "1");
    if(n>=2) printStairPaths(n-2, ans + "2");
    if(n>=3) printStairPaths(n-3, ans + "3");

    return;
}
int main()
{
    printStairPaths(5,"");
}
