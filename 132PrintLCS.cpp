#include <vector>
#include <iostream>
using namespace std;

int tab(string s1, string s2, vector<vector<int>>&dp)
{
    int n = s1.length();
    int m = s2.length();

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}
int main()
{
    string s1 = "abcde";
    string s2 = "bdgek";
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    int len = tab(s1,s2,dp);
    // cout<<len<<endl;
    string lcs = "";
    for(int i=0; i<len; i++) lcs+="$";
    int index = len-1;
    
    int i =n; 
    int j =m;

    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            lcs[index] = s1[i-1];
            index--; i--; j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    cout<<lcs<<endl;
}
