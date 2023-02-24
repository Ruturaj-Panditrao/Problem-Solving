#include <vector>
#include <iostream>
using namespace std;

vector<string> getKeypadCombination(string str, vector<string>&keypad)
{
    if(str.length()==0)
    {
        return {""};
    }

    char ch = str[0];
    string ros = str.substr(1);

    vector<string> recCombinations = getKeypadCombination(ros,keypad);

    vector<string>myAns;

    for(auto character : keypad[ch-'0'])
    {
        for(auto s : recCombinations)
        {
            myAns.push_back(character + s);
        }
    }

    return myAns;
}

int main()
{
    vector<string>keypad = {"?!", "abc", "def", "ghi", "jkl", "mnop", "qrst", "uv", "wxyz", ".,"};
                        //   0      1      2      3      4      5       6      7      8       9

    vector<string>keypadCombinations = getKeypadCombination("573", keypad);

    for(auto it : keypadCombinations)
    {
        cout<<it<<" ";
    }
}
