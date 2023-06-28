class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < arr.size(); i++)
        {
            pq.push({abs(arr[i] - x), i});
            if (pq.size() > k) pq.pop();
        }
        vector<int> ans;
        // while (pq.size())
        // {
        //     cout << pq.top().first << arr[pq.top().second] << endl;
        //     int idx = pq.top().second;
        //     // cout << arr[idx] << " ";
        //     pq.pop();
        // }
        while (!pq.empty())
        {
            //cout << pq.top().first << " " << pq.top().second << endl;
            ans.push_back(arr[pq.top().second]);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};