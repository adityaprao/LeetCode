class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& pts, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<long long, pair<int, int>>> pq;
        
        for (int i = 0; i < pts.size(); i++)
        {
            int x = pts[i][0], y = pts[i][1];
            long long dist = (long long)(x*x) + (y*y);
            pq.push({dist, {x,y}});
            if (pq.size() > k) pq.pop();            
        }
        while (pq.size()) 
        {
            int x = pq.top().second.first, y = pq.top().second.second;
            ans.push_back({x,y});
            pq.pop();
        }
        return ans;        
    }
};