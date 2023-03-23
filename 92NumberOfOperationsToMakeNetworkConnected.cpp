/*
Problem Link :
https://leetcode.com/problems/number-of-operations-to-make-network-connected/
*/

class Solution
{
public:

    void dfs(int node, vector<int>adj[], vector<int>&visited)
    {
        visited[node] = 1;
        for(auto it : adj[node])
        {
            if(visited[it]==0)
            {
                dfs(it,adj,visited);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) 
    {   
        int answer = 0;
        if(connections.size() < (n-1))
        {
            answer = -1;
        }
        else
        {
        vector<int>adj[n];
        for(int i=0; i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }    

        int counter = 0;
        vector<int>visited(n,0);
        for(int i=0; i<n; i++)
        {
            if(visited[i]==0)
            {
                dfs(i,adj,visited);
                counter++;
            }
        }
            answer = counter-1;
        }
        return answer;
    }
};
