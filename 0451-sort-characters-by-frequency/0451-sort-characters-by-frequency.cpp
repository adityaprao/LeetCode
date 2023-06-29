class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        priority_queue<pair<int,char>> pq;
        
        for (char c : s)
            freq[c]++;
        for (auto it : freq)
        {
            pq.push({it.second, it.first});
        }
        string res = "";
        while (pq.size())
        {
            int cnt = pq.top().first;
            char ch = pq.top().second;
            while (cnt--) res += ch;
            pq.pop();
        }
        return res;                
        
    }
};