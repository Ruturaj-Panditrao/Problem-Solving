/*
Problem Link :
https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
*/

#include <bits/stdc++.h> 
 long long mod=1000000007;
int helper(int n, vector<int>&dp)
{
    if(n==0 || n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    
    return dp[n]=(helper(n-1,dp)+helper(n-2,dp))%mod;
}
int countDistinctWays(int n)
{
    vector<int>dp(n+1,-1);
    return helper(n,dp);
}
