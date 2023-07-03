class Solution {
public:
    bool buddyStrings(string s, string t) {
        if (s.size() != t.size()) return false;
        if (s == t)
        {
            vector<int> freq(26, 0);
            for (char c : s)
            {
                freq[c-'a']++;
                if (freq[c-'a'] > 1) return true;
            }
            return false;            
        }
        
        int fi = -1, se = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != t[i])
            {
                if (fi == -1) {
                    fi = i; continue;
                }
                else if (se == -1)
                {
                    se = i;
                }
                else return false;
                
            }
        }
        if (se == -1) return false;
        return (s[fi] == t[se] and s[se] == t[fi] ? true : false);
        
        
    }
};