class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curmax = 0;
        int sum = 0, maxi = -1e8;
        
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            maxi = max(maxi, sum);
            if (sum < 0) sum = 0;
            // curmax = max(nums[i], curmax + nums[i]);
            // maxi = max(maxi, curmax);
        }
        return maxi;
        
    }
};