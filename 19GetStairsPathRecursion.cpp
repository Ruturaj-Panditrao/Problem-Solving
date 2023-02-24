#include <vector>
#include <iostream>
using namespace std;

vector<string> getStairPath(int n)
{   
    if(n<0)
    {
        return {};
    }
    if(n==0)
    {
       return {""};
    }

     vector<string>path1,path2,path3;
    // if(n-1 >= 0)
    {
        path1 = getStairPath(n-1);
    }
    // if(n-2 >=0)
    {
        path2 = getStairPath(n-2);
    }
    // if(n-3 >=0)
    {
        path3 = getStairPath(n-3);
    }

    vector<string>myAns;

    for(auto it : path1) {myAns.push_back('1' + it);}
    for(auto it : path2) {myAns.push_back('2' + it);}
    for(auto it : path3) {myAns.push_back('3' + it);}

    return myAns;

}

int main()
{
    vector<string>paths = getStairPath(5);

    for(auto it : paths)
    {
        cout<<it<<" ";
    }
}
