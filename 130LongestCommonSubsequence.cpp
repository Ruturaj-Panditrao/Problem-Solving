// TABULATED
int longestCommonSubsequence(string text1, string text2) 
    {
        int n = text1.length();
        int m = text2.length();
        // n x m Storage
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // 0 Indexed Positions in dp should be 0
        // Data filling in table should start at 1 index
        // Since we have n & m entries in total
        // If 0  was there 0->n-1,0->m-1
        // But now 0 has been filled up as the base case
        // Hence 1->n, 1->m
        // We need the indices n and m
        // To get the indices n and m, we need storage of size n+1,m+1

        for(int i=0; i<=n;i++)  dp[i][0] = 0;
        for(int j=0; j<=m;j++)  dp[0][j] = 0;
        // Filling up the Base Cases

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(text1[i-1]==text2[j-1])
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
