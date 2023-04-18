/*
Problem Link :
https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
*/

// Memoized
int recursiveSolver(int index, vector<int>&heights, vector<int>&dp)
{
    if(index ==0 ) return 0;
    if(dp[index]!=-1) return dp[index];
    int left = recursiveSolver(index-1,heights,dp) + abs(heights[index]-heights[index-1]);
    int right = INT_MAX;
    if(index > 1) right = recursiveSolver(index-2,heights,dp) + abs(heights[index]-heights[index-2]);
    return dp[index] = min(left,right); 
}
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n,-1);
    return recursiveSolver(n-1,heights,dp);
}

// Tabulation
#include <bits/stdc++.h>
// Tabulation Approach
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n,0);
    dp[0] = 0;
    for(int i=1; i<n; i++)
    {
        int left = dp[i-1] + abs(heights[i]-heights[i-1]);
        int right = INT_MAX;
        if(i>1)
        right = dp[i-2] + abs(heights[i]-heights[i-2]);
        dp[i] = min(left,right);
    }

    return dp[n-1];
}

// Space Optimization
#include <bits/stdc++.h>
// Tabulation Approach
int frogJump(int n, vector<int> &heights)
{
    int prev1 = 0;
    int prev2 = 0;
    int curr = 0;
    for(int i=1; i<n; i++)
    {
        int fs = prev1 + abs(heights[i]-heights[i-1]);
        int ss = INT_MAX;
        if(i>1)
        ss = prev2 + abs(heights[i]-heights[i-2]);
        
        curr = min(fs,ss);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
