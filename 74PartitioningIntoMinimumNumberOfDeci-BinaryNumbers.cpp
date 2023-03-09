/*
Problem Link :
https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
*/

class Solution
{
public:
    int minPartitions(string n)
    {
        long long int maxx = n[0];
        char ans = n[0];

        for(int i=1; i<n.length(); i++)
        {
            if(n[i] >maxx)
            {
                maxx = n[i];
                ans = n[i];
            }
        }    

        long long int answer = ans-'0';
        return answer;
    }
};
