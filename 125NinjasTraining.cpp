/*
Problem Link :
https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
*/

// Memoization
int solve(int index, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if(index == 0)
    {
        int maxi = 0;
        for(int i=0; i<3;i++)
        {
            if(i!=last)
            {
                maxi =max(points[index][i],maxi);
            }
        }
        return maxi;
    }
    if(dp[index][last]!=-1) return dp[index][last];
    int maxo = 0;
    for(int i=0; i<3;i++)
    {
        if(i!=last)
        {
            int score = points[index][i] + solve(index-1,i,points,dp); 
            maxo = max(score,maxo);
        }
    }
    return dp[index][last] =maxo;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return solve(n-1,3,points,dp);
}

// Tabulation

#include <bits/stdc++.h>

using namespace std;

int ninjaTraining(int n, vector < vector < int > > & points) {

  vector < vector < int > > dp(n, vector < int > (4, 0));

  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++) {
    for (int last = 0; last < 4; last++) {
      dp[day][last] = 0;
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          int activity = points[day][task] + dp[day - 1][task];
          dp[day][last] = max(dp[day][last], activity);
        }
      }
    }

  }

  return dp[n - 1][3];
}
