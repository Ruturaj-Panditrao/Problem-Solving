/*
Problem Link :
https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
*/

class Solution 
{
public:
    bool check(vector<int>& nums) 
    {
        long long int curBigThanNextCount = 0;
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i]>nums[i+1])
            {
                curBigThanNextCount++;
            }
    
        }
        if(nums[0]<nums[nums.size()-1]) curBigThanNextCount++;
        if(curBigThanNextCount == 0 || curBigThanNextCount == 1) return true;
        else return false;
    }
};
