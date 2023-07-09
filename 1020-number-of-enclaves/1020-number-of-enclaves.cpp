class Solution {
public:
    
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid)
    {
        if (i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or grid[i][j] == 0) return;
        
        vis[i][j] = 1;
        grid[i][j] = 0;
        
        dfs(i+1,j,vis,grid);
        dfs(i-1,j,vis,grid);
        dfs(i,j+1,vis,grid);
        dfs(i,j-1,vis,grid);
        
        return;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        vector<vector<int>> vis(grid.size(), vector<int> (grid[0].size(), 0));
        
        //top boundary
        for (int i = 0; i < grid[0].size(); i++)
        {
            if (!vis[0][i] and grid[0][i])
                dfs(0,i,vis,grid);
        }
        
        //bottom
        for (int i = 0; i < grid[0].size(); i++)
        {
            if (!vis[grid.size()-1][i] and grid[grid.size()-1][i])
                dfs(grid.size()-1, i, vis, grid);
        }
        
        //left
        for (int i = 0; i < grid.size(); i++)
        {
            if (!vis[i][0] and grid[i][0])
                dfs(i, 0, vis, grid);
        }
        
        for (int i = 0; i < grid.size(); i++)
        {
            if (!vis[i][grid[0].size()-1] and grid[i][grid[0].size()-1])
                dfs(i, grid[0].size()-1, vis, grid);
        }
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j]) cnt++;
            }
        }
        return cnt;
        
        
        
    }
};