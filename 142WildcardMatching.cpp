/*
Problem Link :
https://leetcode.com/problems/wildcard-matching/
*/

// Recursive

class Solution 
{
public:

    bool f(int i, int j, string& p, string& s)
    {
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(j<0 && i>=0)
        {
            for(int ii=0; ii<=i; ii++)
            {
                if(p[ii]!='*') return false;
            }
            return true;
        }

        if(p[i]==s[j] || p[i]=='?') return f(i-1,j-1,p,s);
        if(p[i]=='*') {return f(i-1,j,p,s) | f(i,j-1,p,s); }
        return false;
    }
    bool isMatch(string s, string p)
    {
        int n = p.length();
        int m = s.length();
        return f(n-1,m-1,p,s);
    }
};

// Memorized

class Solution 
{
public:

    bool f(int i, int j, string& p, string& s, vector<vector<int>>&dp)
    {
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(j<0 && i>=0)
        {
            for(int ii=0; ii<=i; ii++)
            {
                if(p[ii]!='*') return false;
            }
            return true;
        }

        if(dp[i][j]!= -1) return dp[i][j];
        if(p[i]==s[j] || p[i]=='?') return dp[i][j] = f(i-1,j-1,p,s,dp);
        if(p[i]=='*') {return dp[i][j] = f(i-1,j,p,s,dp) | f(i,j-1,p,s,dp); }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p)
    {
        int n = p.length();
        int m = s.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,p,s,dp);
    }
};

// Tabulated

class Solution {
    int solve(string&s, string&p){
        vector<vector<bool>>dp(s.length()+1,vector<bool>(p.length()+1,0));
        dp[0][0]=true;
        for(int j=1;j<=p.length();j++){
            int f=true;
            for(int c=1;c<=j;c++){
                if(p[c-1]!='*'){
                    f=false;
                    break;
                }
            }
            dp[0][j]=f;
        }
        for(int a=1;a<=s.length();a++){
            for(int b=1;b<=p.length();b++){
                if(s[a-1]==p[b-1] || p[b-1]=='?'){
                    dp[a][b]=dp[a-1][b-1];
                }
                else if(p[b-1]=='*'){
                    bool i=dp[a-1][b];
                    bool j=dp[a][b-1];
                    dp[a][b]=i||j;
                }
                else{
                 dp[a][b]=false;
                }
            }
        }
        return dp[s.length()][p.length()];
    }
public:
    bool isMatch(string s, string p) {
        return solve(s,p);
    }
};
