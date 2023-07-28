class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i + 1 < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                string s1 = to_string(nums[i]), s2 = to_string(nums[j]);
                s1 = s1[0], s2 = s2[s2.size()-1];
                int n1 = stoi(s1), n2 = stoi(s2);
                int gcd = __gcd(n1, n2);
                if (gcd == 1) cnt++;
            }
        }
        return cnt;        
    }
};