class Solution {
public:
    int equalPairs(vector<vector<int>>& g) {
        map< vector<int>, int > mp;
        int ans = 0;
        
        for (int i = 0; i < g.size(); i++)
        {
            vector<int> temp;
            for (int j = 0; j < g[0].size(); j++)
            {
                temp.push_back(g[i][j]);                
            }
            mp[temp]++;
        }
        
        for (int i = 0; i < g.size(); i++)
        {
            vector<int> temp;
            for (int j = 0; j < g.size(); j++)
            {
                temp.push_back(g[j][i]);
            }
            
            if (mp[temp] > 0) ans += mp[temp];
        }
        return ans;
        
    }
};