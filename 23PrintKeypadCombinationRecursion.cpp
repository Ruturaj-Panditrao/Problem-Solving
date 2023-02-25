#include <vector>
#include <iostream>
using namespace std;

void printKeypadCombination(string ques, string ans, vector<string>&keypad)
{
    if(ques.length()==0)
    {
        cout<<ans<<" ";
        return;
    }

    char ch = ques[0];
    string roq = ques.substr(1);
    // We need to locate string Corresponding to character ch in the Keypad

    for(auto character : keypad[ch-'0'])
    {
        // Important is that Remember, our Answer String is Initially Empty
        // So pass on answer + character,
        // SO that correct answer is passed on further
        // We are adding to answer, in each step, as answer is initially an empty stringp
        printKeypadCombination(roq, ans + character, keypad);
    }
}

int main()
{
    vector<string>keypad = {"?!", "abc", "def", "ghi", "jkl", "mnop", "qrst", "uv", "wxyz", ".,"};
                        //   0      1      2      3      4      5       6      7      8       9

    printKeypadCombination("573", "", keypad);
}
