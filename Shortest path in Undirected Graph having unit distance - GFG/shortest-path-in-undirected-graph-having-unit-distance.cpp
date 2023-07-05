//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> dist(N, 1e9);
        vector<vector<int>> adj(N);
        for (int i = 0; i < edges.size(); i++)
        {
            int e1 = edges[i][0], e2 = edges[i][1];
            adj[e1].push_back(e2);
            adj[e2].push_back(e1);
        }
        
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            
            for (auto it : adj[cur])
            {
                if (dist[cur] + 1 < dist[it])
                {
                    dist[it] = dist[cur] + 1;
                    q.push(it);
                }
            }
        }
        for (int &x : dist) x = (x == 1e9 ? -1 : x);
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends