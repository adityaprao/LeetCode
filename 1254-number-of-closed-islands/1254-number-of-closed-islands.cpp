class Solution {
public:
    
    void dfs(int i, int j, vector<vector<int>> &g, vector<vector<int>> &vis)
    {
        int m = g.size(), n = g[0].size();
        if (i < 0 or j < 0 or i >= m or j >= n or g[i][j] == 1 or vis[i][j]) return;

        
        vis[i][j] = 1, g[i][j] = 1;
        
        dfs(i+1, j, g, vis);
        dfs(i-1, j, g, vis);
        dfs(i, j+1, g, vis);
        dfs(i, j-1, g, vis);
        
        return;

    }
    
    
    int closedIsland(vector<vector<int>>& g) 
    {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        
        //left col:
        for (int i = 0; i < m; i++) 
        {
            if (!vis[i][0] and g[i][0] == 0) dfs(i, 0 , g, vis);
        }
        //right col:
        for (int i = 0; i < m; i++)
        {
            if (!vis[i][n-1] and g[i][n-1] == 0) dfs(i, n-1, g, vis);
        }
        //top row:
        for (int i = 0; i < n; i++)
        {
            if (!vis[0][i] and g[0][i] == 0) dfs(0, i, g, vis);
        }
        //bottom row:
        for (int i = 0; i < n; i++)
        {
            if (!vis[m-1][i] and g[m-1][i] == 0) dfs(m-1, i, g, vis);
        }
        
        int res = 0;
        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << g[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (g[i][j] == 0 and !vis[i][j])
                    dfs(i, j, g, vis), res++;
            }
        }
        return res;
        
    }
};