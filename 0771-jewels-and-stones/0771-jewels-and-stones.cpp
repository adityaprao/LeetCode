class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        set<char> s;
        int ans = 0;
        for (int i = 0; i < jewels.size(); i++) s.insert(jewels[i]);
        for (char c : stones)
        {
            if (s.find(c) != s.end()) ans++ ;           
        }
        return ans;
    }
};