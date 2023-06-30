class Solution {
public:
    
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
                dfs(it, adj, vis);
        }
    }
    
    int findCircleNum(vector<vector<int>>& g) {
        int n = g.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j and g[i][j] == 1)
                {
                    adj[i].push_back(j);                    
                }
            }
            
        }
        vector<int> vis(n, 0);
        int cc = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis);
                cc++;
            }
                        
        }
        return cc;
        
    }
};