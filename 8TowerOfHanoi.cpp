#include <iostream>
using namespace std;

void TowerOfHanoi(int n, string src, string dest, string helper)
{
    if(n==0) return;

    TowerOfHanoi(n-1,src,helper,dest);
    cout<<n<<"["<<src<<"->"<<dest<<"]"<<endl;
    TowerOfHanoi(n-1,helper,dest,src);
}

int main()
{
    // Number of Disks
    int n = 3; 
    // Source : 10
    // Destination : 11
    // Helper Node : 12

    TowerOfHanoi(3,"10","11","12");
}
    
