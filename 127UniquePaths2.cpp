/*
Problem Link :
https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
*/

// Recursive 
int mod = int(1e9 +  7);

int solve(int i, int j, vector<vector<int>>&mat)
{
    if(i>=0 && j>=0 && mat[i][j]==-1) return 0;
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;

    int up = solve(i-1,j,mat)%mod;
    int left = solve(i,j-1,mat)%mod;

    return (up+left)%mod;
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) 
{
    return solve(n-1,m-1,mat);
}

// Tabulated
int mod = int(1e9 +  7);

int solve(int i, int j, vector<vector<int>>&mat,  vector<vector<int>>&dp)
{
    if(i>=0 && j>=0 && mat[i][j]==-1) return 0;
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up = solve(i-1,j,mat,dp)%mod;
    int left = solve(i,j-1,mat,dp)%mod;

    return dp[i][j] = (up+left)%mod;
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) 
{
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return solve(n-1,m-1,mat,dp);
}
