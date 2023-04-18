/*
Problem Link :
https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
*/

#include <bits/stdc++.h> 
int helper(int index, vector<int>&nums, vector<int>&dp)
{
    if(index == 0) return nums[0];
    if(index < 0) return 0;

    if(dp[index]!=-1) return dp[index];
    int pick = nums[index] + helper(index-2,nums,dp);
    int notPick = 0  + helper(index-1,nums,dp);

    return dp[index] = max(pick,notPick);
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int>dp(n,-1);
   return helper(n-1,nums,dp);
}
