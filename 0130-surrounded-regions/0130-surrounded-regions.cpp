class Solution {
public:
    
    void dfs(int i, int j, vector<vector<char>> &g, vector<vector<int>> &vis)
    {
        int m = g.size(), n = g[0].size();
        
        if (i < 0 or j < 0 or i >= m or j >= n) return;
        
        vis[i][j] = 1;
        g[i][j] = '#';
        
        if (i+1 < m and g[i+1][j] == 'O') dfs(i+1, j, g, vis);
        if (j+1 < n and g[i][j+1] == 'O') dfs(i, j+1, g, vis);
        if (i-1 >= 0 and g[i-1][j] == 'O') dfs(i-1, j, g, vis);
        if (j-1 >= 0 and g[i][j-1] == 'O') dfs(i, j-1, g, vis);
        return;        
    }
    
    
    
    
    void solve(vector<vector<char>>& g) 
    {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        // top boundary:
        for (int j = 0; j < n; j++)
        {
            if (g[0][j] == 'O' and !vis[0][j])
            {
                dfs(0, j, g, vis);
            }            
        }
        // bottom boundary:
        for (int j = 0; j < n; j++)
        {
            if (g[m-1][j] == 'O' and !vis[m-1][j])
            {
                dfs(m-1, j, g, vis);
            }            
        }
        // left boundary:
        for (int j = 0; j < m; j++)
        {
            if (g[j][0] == 'O' and !vis[j][0])
            {
                dfs(j, 0, g, vis);
            }            
        }
        // right boundary:
        for (int j = 0; j < m; j++)
        {
            if (g[j][n-1] == 'O' and !vis[j][n-1])
            {
                dfs(j, n-1, g, vis);
            }            
        }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (g[i][j] == 'O') g[i][j] = 'X';
                else if (g[i][j] == '#') g[i][j] = 'O';
            }
        }
        
    }
};