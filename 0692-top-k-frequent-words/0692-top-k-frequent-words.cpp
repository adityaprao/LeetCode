class comp 
{
  public:
    bool operator() (const pair<int, string>&p1, const pair<int, string>&p2) 
    {
        if(p1.first > p2.first) return false;
        else if(p1.first == p2.first) return p1.second > p2.second;
        else return true;
    }
};    

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto it : words)
			mp[it]++;
        
        priority_queue< pair<int, string>, vector<pair<int, string>>, comp > pq;
        for(auto it : mp)
			pq.push({it.second, it.first});
        
        vector<string> ans;
        for(int i = 1; i <= k; i++)
            ans.push_back(pq.top().second), pq.pop();
			
        return ans;    
    }
};