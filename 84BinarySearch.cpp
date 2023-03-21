/*
Problem Link :
https://leetcode.com/problems/binary-search/?envType=study-plan&id=algorithm-i
*/

class Solution 
{
public:
    int search(vector<int>& nums, int target)
    {
        long long int start = 0;
        long long int end = nums.size()-1;

        long long int mid = start + (end-start)/2;

        long long int answer = -1;

        while(start<=end)
        {
            if(nums[mid]==target)
            {
                answer = mid;
                break;
            }    

            if(nums[mid]<target)
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }

            mid = start + (end-start)/2;
        }    

        return answer;
    }
};
