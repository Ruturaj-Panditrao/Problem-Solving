#include <vector>
#include <iostream>
using namespace std;

void printEncodings(string ques, string ans, vector<string>&encodings)
{
    if(ques.length()==0)
    {
        cout<<ans<<" ";
        return;
    }

    int ch = ques[0]-'0';
    if(ch == 0)
    {
        return;
    }
    else
    {
    string tempa = encodings[ch];
    string roqa = ques.substr(1);
    printEncodings(roqa, ans + tempa, encodings);
    }

    if(ques.length()>=2)
    // {
        // for(int i=0; i<ques.length()-1; i++)
        {
        int ch1 = ques[0]-'0';
        int ch2 = ques[1]-'0';
        int total = ch1*10 + ch2;
        if(total > 26)
        {
            return;
        }
        else
        {
        string temp = encodings[ch1*10 + ch2];
        string roq = ques.substr(2);
        printEncodings(roq, ans + temp , encodings);
        }
        // }      
    }

    return;

}
int main()
{
    vector<string>encodings = {"","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p",
    "q","r","s","t","u","v","w","x","y","z"};

    printEncodings("12345","",encodings);
}
