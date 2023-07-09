class Solution {
public:
    vector<int> findAnagrams(string s1, string s2) 
    {
        unordered_map<char, int> mp;
        for (char ch : s2) mp[ch]++;
        int n1 = s1.size(), n2 = s2.size(), cnt = mp.size(), i = 0, j = 0;
        vector<int> ans;
        
        while (j < n1)
        {
            if (mp.find(s1[j]) != mp.end())
            {
                mp[s1[j]]--;
                if (mp[s1[j]] == 0) cnt--;
            }
            if (j-i+1 < n2) j++;
            else if (j-i+1 == n2)
            {
                if (cnt == 0)
                {
                    ans.push_back(i);
                }
                if (mp.find(s1[i]) != mp.end())
                {
                    mp[s1[i]]++;
                    if (mp[s1[i]] == 1) cnt++;
                }
                i++, j++;
            }
        }
        return ans;
        
    }
};