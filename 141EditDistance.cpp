/*
Problem Link :
https://leetcode.com/problems/edit-distance/
*/

// Recursive 
class Solution 
{
public:

    int recurse(int i, int j, string word1, string word2)
    {
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(word1[i]==word2[j])
        {
            return recurse(i-1,j-1,word1,word2);
        }
        else
        {
            return 1 + min(recurse(i,j-1,word1,word2),min(recurse(i-1,j,word1,word2),
            recurse(i-1,j-1,word1,word2)));
        }
    }
    int minDistance(string word1, string word2) 
    {
        int n = word1.length();
        int m = word2.length();
        return recurse(n-1,m-1,word1,word2);
    }
};

// Memorized

class Solution 
{
public:

    int recurse(int i, int j, string word1, string word2, vector<vector<int>>&dp)
    {
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j])
        {
            return dp[i][j] = recurse(i-1,j-1,word1,word2,dp);
        }
        else
        {
            return dp[i][j] = 1 + min(recurse(i,j-1,word1,word2,dp),min(recurse(i-1,j,word1,word2,dp),
            recurse(i-1,j-1,word1,word2,dp)));
        }
    }
    int minDistance(string word1, string word2) 
    {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return recurse(n-1,m-1,word1,word2,dp);
    }
};

// Tabulated

class Solution 
{
public:
    int minDistance(string word1, string word2) 
    {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j=0; j<=m; j++) dp[0][j] = j;
        for(int i=0; i<=n; i++) dp[i][0] = i;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                  if(word1[i-1]==word2[j-1])
                {
           dp[i][j] = dp[i-1][j-1];
                 }
        else
        {
           dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
        }
            }
        }
        return dp[n][m];
    }
};

// Space Optimized

class Solution 
{
public:
    int minDistance(string word1, string word2) 
    {
        int n = word1.length();
        int m = word2.length();
        vector<int>curr(m+1,0);
        vector<int>prev(m+1,0);
        for(int j=0; j<=m; j++) prev[j] = j;

        for(int i=1; i<=n; i++)
        {
            curr[0] = i;
            for(int j=1; j<=m; j++)
            {
                  if(word1[i-1]==word2[j-1])
                {
           curr[j] = prev[j-1];
                 }
        else
        {
           curr[j] = 1 + min(curr[j-1],min(prev[j],prev[j-1]));
        }
            }
            prev = curr;
        }
        return prev[m];
    }
};
