/*
Problem Link :
https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/
*/

class Solution 
{
public:

    void dfs(int node, vector<int>&visited, int &answer, vector<pair<int,int>>adj[])
    {
            visited[node] = 1;

            for(auto it:adj[node])
            {
                 answer=min(answer,it.second);
            if(!visited[it.first])   
             {
                 dfs(it.first,visited,answer,adj);
             }
            }
    }
    int minScore(int n, vector<vector<int>>& roads)
    {
        vector<pair<int,int>>adj[n+1];
        for(auto it : roads)
        {
            adj[it[0]].push_back(make_pair(it[1],it[2]));
            adj[it[1]].push_back(make_pair(it[0],it[2]));
        }    
       
        vector<int>visited(n+1,0);
         visited[0] = 1;
        int answer = INT_MAX;
        dfs(1,visited,answer,adj);
        return answer;
    }
};
