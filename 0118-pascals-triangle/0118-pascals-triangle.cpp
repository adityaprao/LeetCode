class Solution {
public:
    vector<vector<int>> generate(int n) 
    {
        vector<vector<int>> g;
        
        for (int i = 0; i < n; i++)
        {
            vector<int> temp(i + 1, 0);
            temp[0] = 1;
            temp[i] = 1;
            
            if (i > 1)
            {
               for (int j = 1; j < i; j++)
                {
                    temp[j] = g[i-1][j] + g[i-1][j-1];
                } 
            }
            g.push_back(temp);                
        }
        return g;
        
    }
};