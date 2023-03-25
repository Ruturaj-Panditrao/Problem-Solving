/*
Problem Link :
https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/
*/

class Solution 
{
public:

    void dfs(int node, vector<long long int>&visited, vector<int>adj[],long long int& c)
    {
        visited[node]=1;
        c+=1;
        for(auto it : adj[node])
        {
            if(visited[it]==0)
            {
                dfs(it,visited,adj,c);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
       
       vector<int>adj[n];

       for(int i=0; i<edges.size(); i++)
       {
           adj[edges[i][0]].push_back(edges[i][1]);
           adj[edges[i][1]].push_back(edges[i][0]);
       }

       vector<long long int>counters;
       vector<long long int>visited(n,0);
        for(int i=0; i<n; i++)
        {
            if(visited[i]==0)
            {
                long long int c = 0;
                dfs(i,visited,adj,c);
                counters.push_back(c);
            }
        }
        for(auto it : counters) cout<<it<<" ";
        long long ans = 0;
        if(counters.size()==1) return 0;
        else
        {
           for(int i=0; i<counters.size();i++)
           {
               long long unreachable = (n-counters[i]);
               ans += unreachable*(counters[i]);
           }
           
        }
        ans/=2;
        return ans;
    }
};

// 4,2,1

// 
