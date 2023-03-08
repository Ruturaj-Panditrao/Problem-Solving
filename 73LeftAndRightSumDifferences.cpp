/*
Problem Link :
https://leetcode.com/problems/left-and-right-sum-differences/description/
*/

class Solution 
{
public:
    vector<int> leftRigthDifference(vector<int>& nums)
    {
        vector<int>leftToRight = nums;
        vector<int>rightToLeft = nums;


        for(int i=1; i<nums.size(); i++)
        {
            leftToRight[i]+=leftToRight[i-1];
        }    

        for(int i = nums.size()-2; i>=0; i--)
        {
            rightToLeft[i]+=rightToLeft[i+1];
        }

        for(int i=0; i<nums.size(); i++)
        {
            nums[i] = abs(leftToRight[i]-rightToLeft[i]);
        }

        return nums;
    }
};
