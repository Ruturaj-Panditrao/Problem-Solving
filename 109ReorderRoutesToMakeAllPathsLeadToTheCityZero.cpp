/*
Problem Link :
https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/
*/

class Solution 
{
public:
    long long int counter = 0;

    bool IsPresent(int it, int node, vector<int>adjdir[])
    {
        for(auto jt : adjdir[node])
        {
            if(jt == it)
            {
                return true;
            }
        }
        return false;
    }
    void dfs(int node, vector<int>adj[], vector<int>adjdir[],vector<int>&visited)
    {   
        visited[node]=1;
        for(auto it : adj[node])
        {
            if(visited[it]==0)
            {
            if (IsPresent(it,node,adjdir)==true) counter++;
            dfs(it,adj,adjdir,visited);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections)
    {
        vector<int>adj[n];
        vector<int>adjdir[n];
        for(int i=0; i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adjdir[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        vector<int>visited(n,0);
                dfs(0,adj,adjdir,visited);
         
        return counter;
    }
};
