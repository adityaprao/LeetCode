
class Solution 
{
    public:
    
    vector<int> parent, size;
    void make(int n)
    {
        for (int i = 0; i < n; i++) parent[i] = i, size[i] = 1;
    }
    
    int findPar(int i)
    {
        if (parent[i] == i) return i;
        
        return parent[i] = findPar(parent[i]);
    }
    
    void _union(int i, int j)
    {
        i = findPar(i), j = findPar(j);
        if (i == j) return;
        
        if (size[i] < size[j]) swap(i, j);
        parent[j] = i;
        size[i] += size[j];
    }
    
    
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) 
    {
        parent.resize(n+5);
        size.resize(n+5);
        make(n);
        for (int i = 0; i < edges.size(); i++)
        {
            _union(edges[i][0], edges[i][1]);
        }
        
        if (findPar(src) == findPar(dest)) return true;
        return false;
                
        
    }
};