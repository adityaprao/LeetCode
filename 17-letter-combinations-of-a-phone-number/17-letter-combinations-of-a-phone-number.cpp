class Solution {
public:
    vector<string> final;
    
    
    void gen(int ind, string &digits, string &cur, unordered_map<char, vector<char> > &mp)
    {
        // base case:
        if (ind == digits.size()) {
            final.push_back(cur);
            return;
        }
        
        vector<char> ch = mp[digits[ind]];
        for (int i = 0; i < ch.size(); i++)
        {
            cur += ch[i];
            gen(ind+1, digits, cur, mp);
            cur.pop_back();
        }
        return;      
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char> > mp;
        if (digits.size() == 0) return {};

        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};
        string cur = "";
        gen(0, digits, cur, mp);
        return final;       

    }
};