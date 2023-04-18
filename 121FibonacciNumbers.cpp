/*
Problem Link :
https://leetcode.com/problems/fibonacci-number/description/
*/


// Memoized
class Solution 
{
public:
    int fib(int n) 
    {
        vector<int>dp(n+1,0);

        dp[0] = 0;
       if(n>=1) dp[1] = 1;

        for(int i=2; i<=n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }    

        return dp[n];
    }
};

// Space Optimized

class Solution 
{
public:
    int fib(int n) 
    {
        // 0 1 1 2 3 5 8 13 21 34 55
        int prev1 = 1;
        int prev2 = 0;
        int next;
        if(n==0) return prev2;
        if(n==1) return prev1;

        for(int i=2; i<=n; i++)
        {
            next = prev1 + prev2; // 0 + 1 = 1
            prev2 = prev1;
            prev1 = next; 
        }    

        return next;
        // prev1 2
        // prev2 1
        // next  2
    }
};
