#include <iostream>
using namespace std;

void printPermutations(string ques, string ans)
{
    if(ques.length()==0)
    {
        cout<<ans<<" ";
        return;
    }

    for(int i =0 ; i<ques.length(); i++)
    {
        char ch = ques[i];
        string leftPart = ques.substr(0,i);
        string rightPart = ques.substr(i+1);
        string roq = leftPart + rightPart;
        printPermutations(roq,ans+ch);
    }
}
int main()
{
    printPermutations("abc","");
}
