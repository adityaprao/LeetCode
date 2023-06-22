class Solution {
public:
    int minPartitions(string n) {
        int mx = 0;
        for (char c : n)
        {
            if (c - '0' == 9) return 9;
            mx = max(mx, c - '0');            
        }
        return mx;        
    }
};