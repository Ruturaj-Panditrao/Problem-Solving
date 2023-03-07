/*
Problem Link :
https://leetcode.com/problems/maximum-value-after-insertion/description/
*/

class Solution 
{
public:
    string maxValue(string n, int x) 
    {
        string answer = "";
        if(n[0]!='-')
        {
            // Positive Number
            // Need to Maximize
            //73,6 -> 763
            //13,2 -> 213
            long long int index = -1;
            for(long long int i=0; i<n.length();i++)
            {
                if((n[i]-'0')<x)
                {
                    index = i;
                    break;
                }
            }
            
            if(index!=-1)
            {
            n.insert(index,to_string(x));
            answer = n;
            }
            else
            {
                answer+=n;
                answer+=to_string(x);
            }
        }
        else
        {
            // Negative Number Case
            answer += '-';
            n = n.substr(1);
            // Minimize The Number
            // 73,6 -> 736
            // 13,2 -> 123

              int index = -1;
            for(int i=0; i<n.length();i++)
            {
                if((n[i]-'0')>x)
                {
                    index = i;
                    break;
                }
            }

            if(index == -1)
            {
                answer+=n;
                answer+=to_string(x);
            }
            else
            {
             n.insert(index,to_string(x));
             answer+=n;
            }
        }    

        return answer;
    }
};
