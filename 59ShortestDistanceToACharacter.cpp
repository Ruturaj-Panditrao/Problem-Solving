/*
Problem Link :
https://leetcode.com/problems/shortest-distance-to-a-character/description/
*/

class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        // 2 Pointer
        // More Optimized,
        // No unnecessary traversal.
        // In previous solution,
        // Even if the target character was not present to the left,
        // We would still traverse the left side
        // Unncessary.
        // Instead, we make equal steps to the left and right side at the same time
        // So if we encounter the target character at any instance either from left or right,
        // It is sure shot minimum & no further traversal is needed.

        vector<int>answer;

        for(int i=0; i<s.length(); i++)
        {
            int low = i;
            int high = i;

            while(true)
            {
                if(s[low]==c)
                {
                    answer.push_back(abs(i-low));
                    break;
                }
                if(s[high]==c)
                {
                    answer.push_back(abs(high-i));
                    break;
                }

                if(low>0)
                {
                    low--;
                }
                if(high<s.length()-1)
                {
                    high++;
                }
            }
        }    

        return answer;
    }
};
