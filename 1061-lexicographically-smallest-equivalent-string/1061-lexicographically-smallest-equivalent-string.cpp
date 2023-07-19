class DSU
{
    public:
    vector<int> parent, size;
    
    DSU(int n)
    {
        parent.resize(n+1);
        size.resize(n+1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i, size[i] = 1;
        }
    }
    
    int findPar(int c)
    {
        if (parent[c] == c) return c;
        return parent[c] = findPar(parent[c]);
    }
    
    void Union(int c, int d)
    {
        // c will always be lexico smaller:
        c = findPar(c), d = findPar(d);
        if (c == d) return;
        
        if (c > d) swap(c, d);
        
        parent[d] = c;
    }
    
};



class Solution {
public:
    
    string smallestEquivalentString(string s1, string s2, string base) 
    {
        DSU dsu(26);
        
        for (int i = 0; i < s1.size(); i++)
        {
            dsu.Union(s1[i] - 'a', s2[i] - 'a');
        }
        string ans = "";
        for (char &c : base) {
            cout << dsu.findPar(c - 'a') << " ";
            ans += (dsu.findPar(c - 'a') + 'a');
        }
        cout << endl;
        return ans;
        
    }
};