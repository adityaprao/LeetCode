class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        multiset<int, greater<int>> st;
        
        int maxi = INT_MIN, i = 0, j = 0;
        vector<int> ans;
        
        while (j < nums.size())
        {
            st.insert(nums[j]);
            if (j-i+1 < k) j++;
            else if (j-i+1 == k)
            {
                ans.push_back(*st.begin());
                st.erase(st.lower_bound(nums[i]));
                i++, j++;
            }
        }
        return ans;
        
    }
};