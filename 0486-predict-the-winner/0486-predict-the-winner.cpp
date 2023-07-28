class Solution {
public:
    
    int calc(int l, int r, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (l == r) return nums[l];
        if (dp[l][r] != -1) return dp[l][r];
        
        int left = nums[l] - calc(l+1, r, nums, dp);
        int right = nums[r] - calc(l, r-1, nums, dp);
        
        return dp[l][r] = max(left, right);
    }
    
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+5, vector<int> (n+5, -1));
        if (calc(0,n-1,nums,dp) >= 0) return true;
        return false;
        
        
    }
};