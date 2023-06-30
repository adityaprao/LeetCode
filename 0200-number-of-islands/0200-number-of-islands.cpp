class Solution {
public:
    int m, n, cc=0;
    
    void dfs(int i, int j, vector<vector<char>> &g)
    {
        if (i >= m or j >= n or i < 0 or j < 0 or g[i][j] == '#' or g[i][j] == '0') return;
        g[i][j] = '#';
        
        dfs(i+1, j, g);
        dfs(i, j+1, g);
        dfs(i-1, j, g);
        dfs(i, j-1, g);
        
    }
    int numIslands(vector<vector<char>>& g) {
        m = g.size(), n = g[0].size();
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (g[i][j] == '1')
                {
                    cc++;
                    dfs(i, j, g);
                }
            }
        }
        return cc;
        
        
    }
};