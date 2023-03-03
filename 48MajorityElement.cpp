/*
Problem Link :
https://leetcode.com/problems/majority-element/
*/

class Solution
{
public:
    int majorityElement(vector<int>& nums) 
    {
        int reqfreq = nums.size()/2;
        unordered_map<int,int>m;
        int ans = 0;
        for(int i=0; i<nums.size();i++)
        {
            m[nums[i]]++;
        }

        for(auto it : m)
        {
            if(it.second > reqfreq)
            {
                ans = it.first;
            }
        }

        return ans;
    }
};
