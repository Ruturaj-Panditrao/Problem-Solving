/*
Problem Link :
https://leetcode.com/problems/jewels-and-stones/
*/

class Solution 
{
public:
    int numJewelsInStones(string jewels, string stones) 
    {
        long long int counter =0;
        unordered_set<int>s;
        for(int i=0; i<jewels.size();i++)
        {
            s.insert(jewels[i]);
        }    

        for(int i=0; i<stones.size();i++)
        {
            if(s.find(stones[i])!=s.end())
            {
                counter++;
            }
        }

        return counter;
    }
};
