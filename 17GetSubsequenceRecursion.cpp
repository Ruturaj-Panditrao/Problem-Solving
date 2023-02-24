#include <vector>
#include <iostream>
using namespace std;

vector<string> getSubsequence(string str)
{
    if(str.length()==0)
    {
        return {""};
    }

    char ch = str[0];
    string restOfString = str.substr(1);
    vector<string> recResult = getSubsequence(restOfString);

    vector<string>myResult;

    for(auto s : recResult)
    {
        myResult.push_back(s);
        myResult.push_back(ch + s);
    }

    return myResult;
}
int main()
{
    vector<string>ans = getSubsequence("abc");
    for(auto it : ans)
    {
        cout<<it<<" ";
    }
}
