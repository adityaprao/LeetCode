class Solution {
public:
    
    int calc(int i, int j1, int j2, vector<vector<int>> &g, vector<vector<vector<int>>> &dp)
    {
        int m = g.size(), n = g[0].size();
        if (j1 >= n or j1 < 0 or j2 >= n or j2 < 0) return -1e8;
        if (i == m-1)
        {
            if (j1 == j2) return g[i][j1];
            else return g[i][j1] + g[i][j2];
        }
        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int cur = -1e8;
        
        for (int dj1 = -1; dj1 <= 1; dj1++)
        {
            for (int dj2 = -1; dj2 <= 1; dj2++)
            {
                int val = 0;
                if (j1 == j2) val = g[i][j1];
                else val = g[i][j1] + g[i][j2];    
                val += calc(i+1, j1+dj1, j2+dj2, g, dp);
                cur = max(cur, val);
            }

        }
        return dp[i][j1][j2] = cur;     
    
        
    }
    
    
    
    
    int cherryPickup(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (n, -1)));
        
        return calc(0, 0, n-1, g, dp);
        
    }
};