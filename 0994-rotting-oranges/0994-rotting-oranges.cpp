class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size(), cnt1 = 0, cnt2 = 0, maxTime = 0;
        queue<pair<pair<int,int>, int>> q;
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (g[i][j] == 1) cnt1++;
                else if (g[i][j] == 2) 
                {
                    cnt2++;
                    q.push({{i,j}, 0});
                }
            }
        }
        
        if (!cnt1) return 0; if (!cnt2) return -1;
        int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

        
        while (!q.empty())
        {
            int i = q.front().first.first, j = q.front().first.second, time = q.front().second;
            maxTime = max(maxTime, time);
            q.pop();
            // cout << "i=" << i << " j=" << j << " t=" << time << endl;
            
            
            
                for (int idx = 0; idx < 4; idx++)
                {
                    
                    int curi = dx[idx] + i, curj = dy[idx] + j;
                    if (curi < 0 or curj < 0 or curi >= m or curj >= n or g[curi][curj] != 1) continue;
                    // cout << "curi=" << curi << " curj=" << curj << endl;

                    g[curi][curj] = 2;
                    q.push({{curi, curj}, time + 1});                    
                }
        }
            

        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
            if (g[i][j] == 1) return -1;
        }
        
        return maxTime;
        
        
        
        
        
    }
};