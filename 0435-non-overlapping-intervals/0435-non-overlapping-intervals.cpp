bool comp(vector<int> &a, vector<int> &b)
{
       return a[1] < b[1];
}

class Solution {
public:  
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), comp);
        int last = -1e9, remove = 0;
        
        for (int i = 0; i < intervals.size(); i++)
        {
            int st = intervals[i][0], end = intervals[i][1];
            
            if (last <= st) last = end;
            else remove++;
        }
        return remove;
        
    }
};