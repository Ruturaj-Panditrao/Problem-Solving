/*
Problem Link :
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
*/

class Solution
{
public:
    int findMin(vector<int>& nums)
     {
		int n=nums.size();
       if(n==1)
	    return nums[0] ;
	        int s=0,end=n-1;
	        while(s<=end){ 
	        int mid=(s+end)/2;
	        int next=(mid+1)%n;
	        int prev=(mid+n-1)%n;
	        if(nums[mid]<=nums[prev]  && nums[mid]<=nums[next] ){
	            return nums[mid];
	            
	        }
	       else if(nums[end]<nums[mid])
                s = mid+1;
            else 
                end= mid-1;   
	    }
	    return 0;   
    }
};
