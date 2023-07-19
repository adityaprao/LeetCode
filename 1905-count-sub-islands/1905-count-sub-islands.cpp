class Solution {
public:
    
    void dfs(int i, int j, vector<vector<int>> &g1, vector<vector<int>> &g2, vector<vector<int>> &vis, bool &res)
    {
        int m = g1.size(), n = g1[0].size();
        if (i < 0 or j < 0 or i >= m or j >= n or !g2[i][j] or vis[i][j]) return;
        
        
        
        if (g1[i][j] != 1) {
            res = false;
            return;
        }
        vis[i][j] = 1;
        
        
        dfs(i+1, j, g1, g2, vis, res);
        dfs(i-1, j, g1, g2, vis, res);
        dfs(i, j+1, g1, g2, vis, res);
        dfs(i, j-1, g1, g2, vis, res);
        
        return;
        

    }
    
    
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) 
    {
        int m = g1.size(), n = g1[0].size(), cnt = 0;
        vector<vector<int>> vis(m, vector<int> (n, 0));
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (g2[i][j] == 1 and !vis[i][j])
                {
                    bool res = true;
                    dfs(i, j, g1, g2, vis, res);
                    if (res) {
                        cnt++;
                        cout << i << " " << j << endl;
                    }
                }
            }
        }
        return cnt;
    }
};