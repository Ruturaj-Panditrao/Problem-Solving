#include <iostream>
using namespace std;

void printSubsequence(string ques, string ans)
{
    if(ques.length()==0)
    {
        cout<<ans<<" ";
        return;
    }

    char ch = ques[0]; 
    // Decision has been taken for first character,
    // So we just pass on Rest of the Question
    string roq = ques.substr(1);

    printSubsequence(roq,ans+ch); // Yes waali Call
    printSubsequence(roq,ans+""); // No waali Call
}
int main()
{
    printSubsequence("abc","");
}
