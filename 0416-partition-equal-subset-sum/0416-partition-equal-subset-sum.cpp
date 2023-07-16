class Solution {
public:
    
    bool check(int i, int tar, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (tar == 0) return true;
        if (i == nums.size()) return false;
        if (i == nums.size()-1) return (tar == nums[i]);
        
        
        if (dp[i][tar] != -1) return dp[i][tar];
        
        bool notake = check(i+1, tar, nums, dp);
        bool take = false;
        
        if (nums[i] <= tar)
        {
            take = check(i+1, tar - nums[i], nums, dp);
        }
        return dp[i][tar] = take or notake;
    }
    
    
    bool canPartition(vector<int>& nums) {
        int totsum = 0;
        for (int &n : nums) totsum += n;
        if (totsum & 1) return false;
        
        vector<vector<int>> dp(nums.size(), vector<int> (totsum/2+1, -1));
        return check(0, totsum/2, nums, dp);
        
    }
};