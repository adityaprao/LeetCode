class Solution {
public:
    
//     int calc(int i, int j, vector<vector<int>> &g, vector<vector<int>> &dp)
//     {
//         int n = g.size(), m = g[0].size();
//         if (i < 0 or j < 0 or i >= n or j >= m) return 0;
        
//         if (dp[i][j] != -1) return dp[i][j];
        
        
//     }
    
    
    int minPathSum(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> dp(n, vector<int> (m, 1e9));
        dp[0][0] = g[0][0];
        for (int i = 1; i < m; i++) dp[0][i] = g[0][i] + dp[0][i-1];
        for (int i = 1; i < n; i++) dp[i][0] = g[i][0] + dp[i-1][0];
        
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                dp[i][j] = min({dp[i][j], dp[i-1][j] + g[i][j], dp[i][j-1] + g[i][j]});
            }
        }
        return dp[n-1][m-1];
        
        
        
    }
};