class Solution {
public:
    
    
    void dfs(int i, int j, int &size, vector<vector<int>> &vis, vector<vector<int>> &g)
    {
        if (i < 0 or j < 0 or i >= vis.size() or j >= vis[0].size() or vis[i][j] == 1 or !g[i][j]) return;
        vis[i][j] = 1;
        
        size++;
        
        dfs(i+1, j, size, vis, g);
        dfs(i-1, j, size, vis, g);
        dfs(i, j+1, size, vis, g);
        dfs(i, j-1, size, vis, g); 
        
        return;
        
        
    }
    
    
    
    int maxAreaOfIsland(vector<vector<int>>& g) 
    {
        int m = g.size(), n = g[0].size(), ans = 0;
        
        vector<vector<int>> vis(m, vector<int> (n, 0));
        
        
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (g[i][j] and !vis[i][j])
                {   
                    int size = 0;
                    dfs(i, j, size, vis, g);
                    ans = max(ans, size);                 
                }
            }
        }
        return ans;
        
        
    }
};