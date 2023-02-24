#include <vector>
#include <iostream>
using namespace std;

vector<string> getMazePaths(int r, int c, int dr, int dc)
{
    if(r>dr || c>dc)
    {
        return {};
    }
    if(r==dr && c==dc)
    {
        return {""};
    }

    vector<string>paths1 = getMazePaths(r+1,c,dr,dc);
    vector<string>paths2 = getMazePaths(r,c+1,dr,dc);

    vector<string>myAns;

    for(auto it : paths1) myAns.push_back('v'+it);
    for(auto it : paths2) myAns.push_back('h'+it);

    return myAns; 
}
int main()
{
    int maze[3][3];
    // Here Since there no Obstacles or so,
    // Actual Maze is not needed, destination co-ordinates will suffice
    vector<string>mazePaths = getMazePaths(0,0,2,2);

    for(auto it : mazePaths)
    {
        cout<<it<<" ";
    }
}
