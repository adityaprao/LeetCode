class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero = 0, ans = 0, start = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            zero += (!nums[i]);
            while (zero > 1)
            {
                zero -= (!nums[start]);
                start++;
            }
            ans = max(ans, i - start);
        }
        
        return ans;
    }
};