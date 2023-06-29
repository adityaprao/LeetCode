class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        unordered_map<int, int> freq;
        for (int x : nums)
            freq[x]++;
        for (auto it : freq)
        {
            int cnt = it.second;
            int n = it.first;
            pq.push({cnt, n});
            if (pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while (pq.size())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};