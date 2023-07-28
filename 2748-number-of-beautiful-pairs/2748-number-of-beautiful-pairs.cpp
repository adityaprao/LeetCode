class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) 
    {
        int cnt = 0;
        vector<int> firstDig(10);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                if (gcd((nums[i] % 10), j) == 1) cnt += firstDig[j];
            }
            while (nums[i] >= 10) nums[i] = nums[i] / 10;
            firstDig[nums[i]]++;            
        }
        return cnt;        
    }
};