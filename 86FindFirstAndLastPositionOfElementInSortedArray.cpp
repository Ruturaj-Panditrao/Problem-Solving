/*
Problem Link :
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
*/

class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
      int firstOcc = -1;
      int lastOcc = -1;

       long long int start = 0;
       long long int end = nums.size()-1;

       int mid = start + (end-start)/2;

       while(start <= end)
       {
           if(nums[mid]==target)
           {
               firstOcc = mid;
               end = mid-1;
           }
           else if(target > nums[mid])
           {
               start = mid+1;
           }
           else
           {
               end = mid-1;
           }

           mid = start + (end-start)/2;
       }        

            long long int start2 = 0;
            long long int end2 = nums.size()-1;
            long long int mid2 = start2 + (end2-start2)/2;
            
        while(start2 <= end2)
        {
            if(nums[mid2]==target)
            {
                lastOcc = mid2;
                start2 = mid2 + 1;
            }
            else if(target > nums[mid2])
            {
                start2 = mid2 +1;
            }
            else
            {
                end2 = mid2 - 1;
            }

            mid2 = start2 + (end2-start2)/2;
        }

            return {firstOcc, lastOcc};
    }
};
