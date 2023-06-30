class Solution {
public:
    int m, n, startcol;
    
    void dfs(int i, int j, vector<vector<int>> &g, int c)
    {
        if (i < 0 or j < 0 or i >= m or j >= n or g[i][j] != startcol) return;
        
        g[i][j] = c;
        dfs(i+1, j, g, c);
        dfs(i-1, j, g, c);
        dfs(i, j+1, g, c);
        dfs(i, j-1, g, c);        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& g, int sr, int sc, int c) 
    {
        m = g.size(), n = g[0].size();
        startcol = g[sr][sc];
        if (startcol == c) return g;
        dfs(sr, sc, g, c);
        return g;
        
        
        
        
        
    }
};