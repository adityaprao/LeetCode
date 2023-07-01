class Solution {
public:
    
    
    int solve(vector<int> &nums, int curidx, vector<int> &give, int k)
    {
        if (curidx == nums.size())
        {
            return *max_element(give.begin(), give.end());            
        }
        int mini = INT_MAX;
        for (int i = 0; i < k; i++)
        {
            give[i] += nums[curidx];
            mini = min(solve(nums, curidx+1, give, k), mini);
            give[i] -= nums[curidx];
        }
        return mini;       
        
        
    }
    int distributeCookies(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> give(k, 0);
        return solve(nums, 0, give, k);
        
        
        
        
    }
};