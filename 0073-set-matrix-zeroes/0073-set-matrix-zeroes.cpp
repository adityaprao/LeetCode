class Solution {
public:
    void setZeroes(vector<vector<int>>& g) 
    {
        int m = g.size(), n = g[0].size();
        vector<int> row(m, 0), col(n, 0);
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!g[i][j])
                {
                    row[i] = -1;
                    col[j] = -1;
                }
            }
        }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (row[i] == -1 or col[j] == -1) g[i][j] = 0;
            }
        }
        
        
        
    }
};