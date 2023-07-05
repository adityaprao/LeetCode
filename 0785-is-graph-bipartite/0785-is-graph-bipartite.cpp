class Solution {
public:
    
    bool check(int node, vector<vector<int>> &g, vector<int> &vis, vector<int> &col, int c)
    {
        vis[node] = 1;
        col[node] = c;
        
        for (auto it : g[node])
        {
            if (!vis[it])
            {
                if (!check(it, g, vis, col, c^1)) return false;
            }
            else if (col[it] == c) return false;            
        }
        return true;        
    }
    
    
    bool isBipartite(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> col(n), vis(n, 0);
        
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (!check(i, g, vis, col, 1)) return false;
            }
        }
        return true;
        
        
    }
};