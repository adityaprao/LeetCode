class Solution {
public:
    
    int calc(int i, int j, vector<vector<int>> &g, vector<vector<int>> &dp)
    {
        int m = g.size(), n = g[0].size();
        if (i < 0 or j < 0 or i >= m or j >= n or g[i][j] != 0) return 0;

        
        if (i == 0 and j == 0) return 1;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int up = calc(i-1, j, g, dp);
        int left = calc(i, j-1, g, dp);
        
        return dp[i][j] = up + left;       
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return calc(m-1, n-1, g, dp);
    }
};