/*
Problem Link :
https://leetcode.com/problems/climbing-stairs/
*/

// Recursive Approach

class Solution
{
public:
    int climbStairs(int n)
    {
        if(n == 0) return 1;
        if(n < 0) return 0;

        int nm1 = climbStairs(n-1);
        int nm2 = climbStairs(n-2);

        return nm1 + nm2;    
    }
};

// Memoized Approach

vector<int>qb(46,-1);
class Solution 
{
public:
    int climbStairs(int n)
    {
        if(n == 0) return 1;
        if(n < 0) return 0;

        if(qb[n]!=-1) return qb[n];
        return qb[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};

// Tabulated Approach

class Solution
{
public:
    int climbStairs(int n) 
    {
        vector<int>dp(n+1,0);
        dp[0] = 1;
        for(int i=1; i<=n; i++)
        {
            if(i == 1) dp[i] = dp[i-1];
            else dp[i] = dp[i-1] + dp[i-2];
        }    

        return dp[n];
    }
};
