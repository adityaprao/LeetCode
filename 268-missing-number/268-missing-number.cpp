class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = size(nums);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int act = (n*(n+1)) / 2;
        
        return act - sum;        
    }
};