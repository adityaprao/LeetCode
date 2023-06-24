class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curmax = 0, maxi = INT_MIN;
        
        for (int i = 0; i < nums.size(); i++)
        {
            curmax = max(nums[i], curmax + nums[i]);
            maxi = max(maxi, curmax);
        }
        return maxi;
        
    }
};