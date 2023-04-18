/*
Problem Link :
https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
*/

// Recursive + Memoized

#include <bits/stdc++.h> 

int solve(int i, int j, vector<vector<int>>&dp)
{
	if(i==0 && j==0) return 1;
	if(i<0 || j<0) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	int up = solve(i-1,j,dp);
	int left = solve(i,j-1,dp);
	return dp[i][j] = up + left;
}
int uniquePaths(int m, int n)
{
	vector<vector<int>>dp(m,vector<int>(n,-1));
	return solve(m-1,n-1,dp);	
}

// Tabulation

#include <bits/stdc++.h> 
int uniquePaths(int m, int n)
{
	vector<vector<int>>dp(m,vector<int>(n,-1));
	dp[0][0] = 1;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i==0 && j==0) dp[i][j]=1;
			else 
			{
				int up = 0;
				int left = 0;
				if(i>0) up = dp[i-1][j];
				if(j>0) left = dp[i][j-1];

				dp[i][j] = up+left;
			}
		}
	}
	return dp[m-1][n-1];
}
