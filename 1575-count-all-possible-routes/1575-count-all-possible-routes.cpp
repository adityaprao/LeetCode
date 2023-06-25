class Solution {
public:
    int n, st, end, left, MOD = 1e9+7;
    
    int solve(vector<vector<int>> &dp, vector<int> &locations, int curcity, int end, int left)
    {
        if (left < 0) return 0;
        if (dp[curcity][left] != -1) return dp[curcity][left];
        
        int ways = (curcity == end ? 1 : 0);
        
        for (int i = 0; i < n; i++)
        {
            if (i != curcity and abs(locations[i] - locations[curcity]) <= left) 
                ways = (ways + solve(dp, locations, i, end, left - abs(locations[i] - locations[curcity]))) % MOD;
        }
        return dp[curcity][left] = ways;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n = locations.size(), st = start, end = finish, left = fuel;
        vector<vector<int>> dp(n, vector<int> (left + 5, -1));
        
        return solve(dp, locations, st, end, left);        
    }
};